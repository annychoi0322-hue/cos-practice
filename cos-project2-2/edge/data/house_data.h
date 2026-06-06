#ifndef __HOUSE_DATA_H__
#define __HOUSE_DATA_H__

#include <string>
#include <ctime>
#include "power_data.h"
#include "house_data.h"
#include "info.h"
using namespace std;

// HouseData zmffotm
// 하나의 house 데이터를 표현하는 클래스
// 포함 구성: Info 객체, PowerData, next
// 전체 구조에서 HouseData는 "노드 역할"을 수행
class HouseData 
{
  private:
    Info *info;               // 해당 House의 기본 정보
    PowerData *data;          // 해당 House의 전력 데이터
    HouseData *next;          // Linked List에서 다음 HouseData
  public:
    HouseData(Info *info);                      // Info만 포함된 HouseData 생성자
    HouseData(Info *info, PowerData *power);    // Info + PowerData 포함 생성자
    void setInfo(Info *info);                   // Info 객체 설정
    Info *getInfo();                            // Info 객체 반환

    string getSerial();                         // serial 값 반환
    string getName();                           // name 값 반환
    string getAddress();                        // address 값 반환

    void setPowerData(PowerData *power);        // PowerData 성정
    PowerData *getPowerData();                  // PowerData 반환

    void setNext(HouseData *hd);                // 다음 HouseData 서정
    HouseData *getNext();                       // 다음 HouseData 반환
};

#endif /* __HOUSE_DATA_H__ */
