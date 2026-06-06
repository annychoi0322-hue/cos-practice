#include "humidity_data.h"

/**
 * Calls SensorData base constructor with min/max/avg.
 * Sets unit to "%" for humidity readings.
 */
HumidityData::HumidityData(time_t timestamp, double min, double max, double avg)
  : SensorData(timestamp, min, max, avg)
{
  this->next = NULL; // 다음 노드 없음
  this->unit = "%";  // 습도 단위 설정
}

void HumidityData::setNext(HumidityData *data) { this->next = data; }  // 다음 HumidityData 노드 설정
HumidityData *HumidityData::getNext()          { return this->next; }  // 다음 HumidityData 노드 반환
string HumidityData::getUnit()                 { return this->unit; }  // 습도 단위 반환
