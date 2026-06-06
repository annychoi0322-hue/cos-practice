#include "power_data.h"

PowerData::PowerData(time_t timestamp, double avg)
  : SensorData(timestamp, avg)  // Base Class 생성자 호출
{
  this->next = NULL;
  this->unit = "kWh";
}

void PowerData::setNext(PowerData *data) { this->next = data; }
PowerData *PowerData::getNext()          { return this->next; }

string PowerData::getUnit()              { return this->unit; }
