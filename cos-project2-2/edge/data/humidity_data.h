#ifndef __HUMIDITY_DATA_H__
#define __HUMIDITY_DATA_H__

#include <ctime>
#include <string>
#include "sensor_data.h"

/**
 * HumidityData: Inherits SensorData.
 * Adds humidity-specific unit and linked list pointer.
 * Used in V1 (avg_humid), V2 (avg_humid), V3 (avg_humid).
 */
class HumidityData : public SensorData
{
  private:
    HumidityData *next;      // Linked List에서 다음 HumidityData를 가리키는 포인터

  public:
    HumidityData(time_t timestamp, double min, double max, double avg);  // HumidityData 생성자

    void setNext(HumidityData *data);  // 다음 노드 설정
    HumidityData *getNext();           // 다음 노드 반환

    string getUnit();                  // 습도 단위 반환
};

#endif /* __HUMIDITY_DATA_H__ */
