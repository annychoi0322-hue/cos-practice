#include "sensor_data.h"

/**
 * Constructor for PowerData (avg only).
 * min and max are initialized to 0 since they are not used for power.
 */
SensorData::SensorData(time_t timestamp, double avg)
{
  this->timestamp = timestamp;
  this->avg = avg;
  this->min = 0;
  this->max = 0;
  this->unit = "";
}

/**
 * Constructor for TemperatureData and HumidityData (min/max/avg).
 */
SensorData::SensorData(time_t timestamp, double min, double max, double avg)
{
  this->timestamp = timestamp;
  this->avg = avg;
  this->min = min;
  this->max = max;
  this->unit = "";
}

void SensorData::setValue(double value) { this->avg = value; }
double SensorData::getValue()           { return this->avg; }

void SensorData::setMin(double min)     { this->min = min; }
double SensorData::getMin()             { return this->min; }

void SensorData::setMax(double max)     { this->max = max; }
double SensorData::getMax()             { return this->max; }

void SensorData::setTimestamp(time_t t) { this->timestamp = t; }
time_t SensorData::getTimestamp()       { return this->timestamp; }

string SensorData::getUnit()            { return this->unit; }
