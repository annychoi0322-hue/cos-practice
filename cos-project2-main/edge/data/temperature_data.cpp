#include "temperature_data.h"

TemperatureData::TemperatureData(time_t timestamp, double min, double max, double avg)
  : SensorData(timestamp, min, max, avg)  // Base Class 생성자 호출
{
  this->next = NULL;
  this->unit = "celcius";
}

void TemperatureData::setNext(TemperatureData *data) { this->next = data; }
TemperatureData *TemperatureData::getNext()          { return this->next; }

string TemperatureData::getUnit()                    { return this->unit; }
