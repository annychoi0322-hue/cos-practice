#include <cstdio>
#include <cstdlib>
#include <cstring>

#define BIT_VECTOR_LENGTH 4
#define MSB_INDEX (BIT_VECTOR_LENGTH - 1)
#define LSB_INDEX 0

void print_command(char *argv[]);
int check_validity(char *input);
void init_bit_vector(char *input, char *bv);
void print_bit_vector(char *bv);

unsigned int b2u(char *bv);
int b2s(char *bv);
int b2o(char *bv);
int b2t(char *bv);


int main(int argc, char *argv[])
{
    char bv1[BIT_VECTOR_LENGTH];
    char bv2[BIT_VECTOR_LENGTH];

    if (argc != 3)
    {
        printf("Error: invalid number of arguments\n");
        print_command(argv);
        return 1;
        print_bit_vector(bv1);

        printf(“ B2U: %u\n”, b2u(bv1));
        printf(“ B2S: %d\n”, b2s(bv1));
        printf(“ B2O: %d\n”, b2o(bv1));
        printf(“ B2T: %d\n”, b2t(bv1));

        print_bit_vector(bv2);
        printf(“ B2U: %u\n”, b2u(bv2));
        printf(“ B2S: %d\n”, b2s(bv2));
        printf(“ B2O: %d\n”, b2o(bv2));
        printf(“ B2T: %d\n”, b2t(bv2));

    return 0;

    }

    if (!(check_validity(argv[1]) && check_validity(argv[2])))
    {
        printf("Error: invalid arguments\n");
        print_command(argv);
        return 1;
    }

void print_command(char *argv[])
{
    printf(“Command: %s <first bit vector> <second bit vector>\n”, argv[0]);
    printf(“Example: %s 0110 1000\n”, argv[0]);
    exit(1);
}

int check_validity(char *input)
{
    // TODO: implement the function
}

    init_bit_vector(argv[1], bv1);
    init_bit_vector(argv[2], bv2);

    print_bit_vector(bv1);
    print_bit_vector(bv2);

    return 0;
}