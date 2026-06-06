#include "temperature_data.h"

/**
 * Calls SensorData base constructor with min/max/avg.
 * Sets unit to "celcius" for temperature readings.
 */
TemperatureData::TemperatureData(time_t timestamp, double min, double max, double avg)
  : SensorData(timestamp, min, max, avg)
{
  this->next = NULL;
  this->unit = "celcius";
}

void TemperatureData::setNext(TemperatureData *data) { this->next = data; }
TemperatureData *TemperatureData::getNext()          { return this->next; }
string TemperatureData::getUnit()                    { return this->unit; }
