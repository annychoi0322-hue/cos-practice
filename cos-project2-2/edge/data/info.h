#ifndef __INFO_H__
#define __INFO_H__
#include <string>
using namespace std;

class Info {
  private: 
    string serial;                              // 고유 식별 번호
    string name;                                // 이름
    string address;                             // 주소
    string generateRandomSerial(int num);       // 내부에서 사용하는 랜덤 serial 생성 함수
    string generateRandomName(int num);         // 내부에서 사용하는 랜덤 이름 생성 함수
    string generateRandomAddress(int num);      // 내부에서 사용하는 랜덤 주소 생성 함수

  public:
    Info(int num);                                           // 랜덤 정보 생성 생성자, num 랜덤 생성 기준 값
    Info(string serial, string name, string address);        // 직접 값 입력 생성자

    void setSerial(string serial);  // serial 생성
    string getSerial();             // serial 반환

    void setName(string name);      // name 설정
    string getName();               // name 반환

    void setAddress(string address);    // address 설정
    string getAddress();                // address 반환
};

#endif /* __INFO_H__ */
