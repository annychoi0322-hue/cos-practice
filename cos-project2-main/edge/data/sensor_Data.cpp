#include "sensor_data.h"

/* 생성자: avg만 있는 경우 (PowerData용) */
SensorData::SensorData(time_t timestamp, double avg)
{
  this->timestamp = timestamp;
  this->avg = avg;
  this->min = 0;
  this->max = 0;
  this->unit = "";
}

/* 생성자: min/max/avg 모두 있는 경우 (Temperature/HumidityData용) */
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

void SensorData::setTimestamp(time_t timestamp) { this->timestamp = timestamp; }
time_t SensorData::getTimestamp()               { return this->timestamp; }

string SensorData::getUnit()            { return this->unit; }
