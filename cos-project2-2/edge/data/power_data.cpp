#include "power_data.h"

/**
 * Calls SensorData base constructor with avg only.
 * Sets unit to "kWh" for power readings.
 */
PowerData::PowerData(time_t timestamp, double avg)
  : SensorData(timestamp, avg)                       // base class 초기화
{
  this->next = NULL;   // Linked List 초기 상태
  this->unit = "kWh";  // 전력 데이터 단위 설정
}

void PowerData::setNext(PowerData *data) { this->next = data; }  // 다음 PowerData 노드 설정
PowerData *PowerData::getNext()          { return this->next; }  // 다음 PowerData 노드 반환
string PowerData::getUnit()              { return this->unit; }  // PowerData 단위 반환
