#include "humidity_data.h"

HumidityData::HumidityData(time_t timestamp, double min, double max, double avg)
  : SensorData(timestamp, min, max, avg)  // Base Class 생성자 호출
{
  this->next = NULL;
  this->unit = "%";
}

void HumidityData::setNext(HumidityData *data) { this->next = data; }
HumidityData *HumidityData::getNext()          { return this->next; }

string HumidityData::getUnit()                 { return this->unit; }
