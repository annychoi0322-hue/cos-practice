#include "humidity_data.h"

/**
 * Calls SensorData base constructor with min/max/avg.
 * Sets unit to "%" for humidity readings.
 */
HumidityData::HumidityData(time_t timestamp, double min, double max, double avg)
  : SensorData(timestamp, min, max, avg)
{
  this->next = NULL;
  this->unit = "%";
}

void HumidityData::setNext(HumidityData *data) { this->next = data; }
HumidityData *HumidityData::getNext()          { return this->next; }
string HumidityData::getUnit()                 { return this->unit; }
