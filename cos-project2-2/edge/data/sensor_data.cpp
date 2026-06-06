#include "sensor_data.h"

/**
 * Constructor for PowerData (avg only).
 * min and max are initialized to 0 since they are not used for power.
 */
SensorData::SensorData(time_t timestamp, double avg)
{
  this->timestamp = timestamp; // 데이터가 측정된 시간
  this->avg = avg;             // 평균값
  this->min = 0;               // 사용하지 않으므로 0으로 초기화
  this->max = 0;               // 사용하지 않으므로 0으로 초기화
  this->unit = "";             // 단위는 기본 빈 문자열
}

/**
 * Constructor for TemperatureData and HumidityData (min/max/avg).
 */
SensorData::SensorData(time_t timestamp, double min, double max, double avg)
{
  this->timestamp = timestamp;  // 데이터 측정 시간
  this->avg = avg;              // 평균값
  this->min = min;              // 최솟값
  this->max = max;              // 최댓값
  this->unit = "";              // 단위는 기본값
}


void SensorData::setValue(double value) { this->avg = value; }         // 평균값 설정
double SensorData::getValue()           { return this->avg; }          // 평균값 반환

void SensorData::setMin(double min)     { this->min = min; }           // 최솟값 설정
double SensorData::getMin()             { return this->min; }          // 최솟값 반환

void SensorData::setMax(double max)     { this->max = max; }           // 최댓값 설정
double SensorData::getMax()             { return this->max; }          // 최댓값 반환

void SensorData::setTimestamp(time_t t) { this->timestamp = t; }       // timestamp 설정
time_t SensorData::getTimestamp()       { return this->timestamp; }    // timestamp 반환

string SensorData::getUnit()            { return this->unit; }         // 데이터 단위 반환
