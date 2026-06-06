#include <stdio.h>           // standard I/O functions
#include <stdlib.h>          // memory allocation, atoi
#include <string.h>          // strlen, memcpy, memset
#include <unistd.h>          // read, write, close
#include <arpa/inet.h>       // inet_addr, htons, htonl
#include <sys/socket.h>      // socket, connect
#include <getopt.h>          // getopt_long for CLI parsing
#include <stdint.h>          // fixed-width integer types

#include "../edge/byte_op.h"    // custom big-endian encode/decode macros

#define BUFLEN        1024
#define OPCODE_SUM    1
#define OPCODE_REPLY  2


/**
 * Executes protocol communication after TCP connection is established.
 * This function demonstrates:
 *  - Length-prefixed string transmission
 *  - Big-endian encoding/decoding
 *  - Simple binary protocol with opcodes
 */
void protocol_execution(int sock);
void error_handling(const char *message);

void usage(const char *pname)
{
  printf(">> Usage: %s [options]\n", pname);             // show program name
  printf("Options\n");                    
  printf("  -a, --addr       Server's address\n");       // IP address option
  printf("  -p, --port       Server's port\n");          // port option
  exit(0);                                               // terminate program
}

int main(int argc, char *argv[])
{
	int sock;                         // socket descriptor
	struct sockaddr_in serv_addr;     // server address struct
  char msg[] = "Hello, World!\n";     // unusesd test message
	char message[30] = {0, };         // unused buffer
	int c, port, tmp, str_len;        // CLI parsing variables
  char *pname;                        // program name
  uint8_t *addr;                      // server IP string
  uint8_t eflag;                      // error flag

  pname = argv[0];                    // program name
  addr = NULL;                        // init addr
  port = -1;                          // init port
  eflag = 0;                          // no error initially


// Parse command line arguments using getopt_long:
//  -a : server IP address
//  -p : server port number
  while (1)
  {
    int option_index = 0;
    static struct option long_options[] = {
      {"addr", required_argument, 0, 'a'},   // -a option
      {"port", required_argument, 0, 'p'},   // -p option
      {0, 0, 0, 0}
    };

    const char *opt = "a:p:0";     // getopt short options

    c = getopt_long(argc, argv, opt, long_options, &option_index);

    if (c == -1)        // no more options
      break;

    switch (c)
    {
      case 'a':                             // allocate memory and copy server address string
        tmp = strlen(optarg);               // get IP string length
        addr = (uint8_t *)malloc(tmp);      // allocate memor
        memcpy(addr, optarg, tmp);          // copy IP string
        break;

      case 'p':                           // Convert port argument to integer
        port = atoi(optarg);              // convert port to int
        break;

      default:
        usage(pname);                     // invalid option
    }
  }

  if (!addr)      // validate required arguments
  {
    printf("[*] Please specify the server's address to connect\n");
    eflag = 1;
  }

  if (port < 0)
  {
    printf("[*] Please specify the server's port to connect\n");
    eflag = 1;
  }

  if (eflag)
  {
    usage(pname);         // exit if invalid
    exit(0);
  }

// create TCP socket
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		error_handling("socket() error");
	memset(&serv_addr, 0, sizeof(serv_addr));   // clear struct
// configure server address structure
	serv_addr.sin_family = AF_INET;             // IPv4
	serv_addr.sin_addr.s_addr = inet_addr((const char *)addr);   // set IP
	serv_addr.sin_port = htons(port);           // convert port to network order
// connect to server
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");
  printf("[*] Connected to %s:%d\n", addr, port);  // success message
// execute custom application-level protocol
  protocol_execution(sock);

	close(sock);  // close socket
	return 0;
}


/**
 * Custom binary protocol implementation.
 *
 * Protocol overview:
 * 1. Client sends:  [4-byte length][string]
 * 2. Server responds: [4-byte length][string]
 * 3. Client sends:  [1-byte opcode][4-byte arg1][4-byte arg2]
 * 4. Server responds: [4-byte opcode][4-byte result]
 */
void protocol_execution(int sock)
{
  char msg[] = "Alice";                      // client name
  char buf[BUFLEN];                          // buffer for send/receive
  int tbs, sent, tbr, rcvd, offset;          // bytes to send / sent bytes, bytes to read / received bytes, current buffer offset
  int len;                                   // message length

  // tbs: the number of bytes to send
  // tbr: the number of bytes to receive
  // offset: the offset of the message

  // 1. Alice -> Bob: length of the name (4 bytes) || name (length bytes)
  // Send the length information (4 bytes)
  len = strlen(msg);
  printf("[*] Length information to be sent: %d\n", len);

  len = htonl(len);  // convert to network byte order
  tbs = 4;           // send 4byte length
  offset = 0;

  while (offset < tbs)
  {
    sent = write(sock, &len + offset, tbs - offset);       // send partial data
    if (sent > 0)
      offset += sent;
  }

  // Send the name (Alice)
  tbs = ntohl(len);             // send actual string
  offset = 0;

  printf("[*] Name to be sent: %s\n", msg);
  while (offset < tbs)
  {
    sent = write(sock, msg + offset, tbs - offset);   // send string
    if (sent > 0)
      offset += sent;
  }

  // 2. Bob -> Alice: length of the name (4 bytes) || name (length bytes)
  // Receive the length information (4 bytes)
  tbr = 4;             // read 4-byte length
  offset = 0;

  while (offset < tbr)
  {
	  rcvd = read(sock, &len + offset, tbr - offset);   // receive length
    if (rcvd > 0)
      offset += rcvd;
  }
  len = ntohl(len);                                   // convert to host order
  printf("[*] Length received: %d\n", len);

  // Receive the name (Bob)
  tbr = len;   // set string length
  offset = 0;

  while (offset < tbr)
  {
    rcvd = read(sock, buf + offset, tbr - offset);  // receive name
    if (rcvd > 0)
      offset += rcvd;
  }

	printf("[*] Name received: %s \n", buf);

  // Implement following the instructions below
  // Let's assume there are two opcodes:
  //     1: summation request for the two arguments
  //     2: reply with the result
  // 3. Alice -> Bob: opcode (4 bytes) || arg1 (4 bytes) || arg2 (4 bytes)
  // The opcode should be 1

  char *p;
  int i, arg1, arg2;

  memset(buf, 0, BUFLEN);
  p = buf;     // pointer for encoding
  arg1 = 2;     // first operand
  arg2 = 5;     // second operand

  VAR_TO_MEM_1BYTE_BIG_ENDIAN(OPCODE_SUM, p);   // opcode = 1
  VAR_TO_MEM_4BYTES_BIG_ENDIAN(arg1, p);        // arg1
  VAR_TO_MEM_4BYTES_BIG_ENDIAN(arg2, p);        // arg2
  tbs = p - buf;                                // total packet size
  offset = 0;

  printf("[*] # of bytes to be sent: %d\n", tbs);
  printf("[*] The following bytes will be sent\n");
  for (i=0; i<tbs; i++)
    printf ("%02x ", buf[i]);    // print packet bytes
  printf("\n");

  while (offset < tbs)
  {
    sent = write(sock, buf + offset, tbs - offset);   // send packet
    if (sent > 0)
      offset += sent;
  }

  // 4. Bob -> Alice: opcode (4 bytes) || result (4 bytes)
  // The opcode should be 2

  int opcode, result;

  tbr = 8; offset = 0;       // 4 bytes opcode + 4 bytes result
  memset(buf, 0, BUFLEN);

  printf("[*] # of bytes to be received: %d\n", tbr);
  while (offset < tbr)
  {
    rcvd = read(sock, buf + offset, tbs - offset);  // receive packet
    if (rcvd > 0)
      offset += rcvd;
  }

  printf("[*] The following bytes is received\n");
  for (i=0; i<tbr; i++)
    printf("%02x ", buf[i]);  // dump raw bytes
  printf("\n");

  p = buf;
  MEM_TO_VAR_4BYTES_BIG_ENDIAN(p, opcode); // decode opcode
  printf("[*] Opcode: %d\n", opcode);
  MEM_TO_VAR_4BYTES_BIG_ENDIAN(p, result);  // decode result
  printf("[*] Result: %d\n", result);
}

/* print error and exit */
void error_handling(const char *message)
{
	fputs(message, stderr);  // print error message
	fputc('\n', stderr);     // newline
	exit(1);                 // terminate program
}
