#include "power_data.h"

/**
 * Calls SensorData base constructor with avg only.
 * Sets unit to "kWh" for power readings.
 */
PowerData::PowerData(time_t timestamp, double avg)
  : SensorData(timestamp, avg)
{
  this->next = NULL;
  this->unit = "kWh";
}

void PowerData::setNext(PowerData *data) { this->next = data; }
PowerData *PowerData::getNext()          { return this->next; }
string PowerData::getUnit()              { return this->unit; }
