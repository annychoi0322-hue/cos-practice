#ifndef __DATASET_H__
#define __DATASET_H__

#include "house_data.h"
#include "temperature_data.h"
#include "humidity_data.h"


// Dataset 클래스
// 전체 시스템에서 하나의 timestamp에 대한 모든 데이터를 관리하는 클래스
// 포함 구성: HouseData 리스트, TemperatureData, HumidityData
// 역할: HouseData 관리, Temperature / Humidity 요약 데이터 저장
class DataSet
{
  private:
    time_t timestamp;        // 데이터셋 기준 시간
    int num;                 // HouseData 개수
    TemperatureData *temp;   // 전체 온도 데이터
    HumidityData *humid;     // 전체 습도 데이터
    HouseData *head;         // Linked List 시작
    HouseData *tail;         // Linked List 끝
    int iterator;            // 순회용 인덱스
  public:                        
    DataSet(time_t timestamp);  // DataSet 생성자, timestamp 데이터 기준 시간

    int getNumHouseData();                 // HouseData 개수 반환
    void addHouseData(HouseData *data);    // HouseData 추가
    HouseData *getHouseData(int index);    // index에 해당하는 HouseData 반환
    void setIterator();                    // iterator 초기화
    HouseData *getNextHouseData();         // iterator 기반 다음 HouseData 반환

    void setTemperatureData(TemperatureData *temp);  // 전체 TemperatureData 설정
    TemperatureData *getTemperatureData();           // 전체 TemperatureData 반환

    void setHumidityData(HumidityData *humid);    // 전체 HumidityData 설정
    HumidityData *getHumidityData();              // 전체 HumidityData 반환

    time_t getTimestamp();  // timestamp 반환
};

#endif /* __DATASET_H__ */
