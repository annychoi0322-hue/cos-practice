#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__

#include <ctime>
#include <string>
#include "sensor_data.h"

/**
 * TemperatureData: Inherits SensorData.
 * Adds temperature-specific unit and linked list pointer.
 * Used in V1 (avg_temp), V2 (temp_range), V3 (max_temp, min_temp).
 */
class TemperatureData : public SensorData
{
  private:
    TemperatureData *next;           // Linked List에서 다음 TemperatureData를 가리키는 포인터

  public:
    TemperatureData(time_t timestamp, double min, double max, double avg);   // TemperatureData 생성자

    void setNext(TemperatureData *data);  // 다음 노드 설정 (Linked List 연결)
    TemperatureData *getNext();           // 다음 노드 반환

    string getUnit();                     // 온도 단위 반환
};

#endif /* __TEMPERATURE_H__ */
