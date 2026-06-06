#include "temperature_data.h"

/**
 * Calls SensorData base constructor with min/max/avg.
 * Sets unit to "celcius" for temperature readings.
 */
TemperatureData::TemperatureData(time_t timestamp, double min, double max, double avg)
  : SensorData(timestamp, min, max, avg)  // base class 초기화 리스트
{
  this->next = NULL;          // 다음 노드 없음 (Linked List 초기 상태)
  this->unit = "celcius";     // 온도 데이터 단위 설정
}

void TemperatureData::setNext(TemperatureData *data) { this->next = data; }  // 다음 TemperatureData 노드 설정
TemperatureData *TemperatureData::getNext()          { return this->next; }  // 다음 TemperatureData 노드 반환
string TemperatureData::getUnit()                    { return this->unit; }  // 단위 반환
