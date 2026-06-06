#include "info.h"
#include "house_info.h"
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

Info::Info(int num)                                 // 랜덤 정보 생성 생성자
{
  this->serial = generateRandomSerial(num);         // num 값을 기반으로 serial / name / address를 랜덤 생성
  this->name = generateRandomName(num);
  this->address = generateRandomAddress(num);
}

Info::Info(string serial, string name, string address)  // 직접 값 입력 생성자
{
  this->serial = serial;
  this->name = name;
  this->address = address;
}

void Info::setSerial(string serial)  // serial setter
{
  this->serial = serial;
}

string Info::getSerial()  // serial getter
{
  return this->serial;
}

string Info::generateRandomSerial(int num)  // 랜덤 serial 생성 (11자리 영문/숫자 혼합 문자열 생성, 뒤에 num을 5자리 zero-padding으로 붙임)
{
  int coin, v;
  stringstream ss;
  string ret;
  int seed;

  seed = time(NULL) + 8 * num;
  srand(seed);
  ret = "";

  for (int i=0; i<11; i++)            // 11자리 랜덤 문자열 생성
  {
    coin = rand() % 2;
    if (!coin)
      v = rand() % 10 + '0';  // 숫자
    else
      v = rand() % 26 + 'A';  // 대문자
    ret += v;                
  }
  ss << setw(5) << setfill('0') << num;   // num을 5자리로 padding해서 뒤에 붙임
  ret += ss.str();

  return ret;
}

void Info::setName(string name)   // name setter
{
  this->name = name;
}

string Info::getName()            // name getter
{
  return this->name;
}

string Info::generateRandomName(int num)    // 랜덤 이름 생성, first name + last name 조합
{
  string ret;
  int count_first, count_last, first_index, last_index;
  int seed;
    
  seed = time(NULL) + 7 * num;
  srand(seed);
  count_first = sizeof(first)/sizeof(string);
  count_last = sizeof(last)/sizeof(string);

  first_index = rand() % count_first;
  last_index = rand() % count_last;

  ret = first[first_index] + " " + last[last_index];

  return ret;
}

void Info::setAddress(string address)      // address setter
{
  this->address = address;
}

string Info::getAddress()                  // address getter
{
  return this->address;
}

string Info::generateRandomAddress(int num)   // 랜덤 주소 생성, 1~5000 번지 + 고정 도로명 주소
{
  string ret;
  int addr, count;
  int seed;

  seed = time(NULL) + 9 * num;
  srand(seed);

  addr = rand() % 50000 + 1;
  ret += to_string(addr) + " ";
  ret += "Songwol-gil, Jongro-gu, Seoul";

  return ret;
}
