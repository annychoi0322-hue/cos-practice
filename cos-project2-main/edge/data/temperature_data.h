#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__

#include <ctime>
#include <string>
#include "sensor_data.h"  // Base Class 상속

/* TemperatureData는 SensorData를 상속받아 기온 특화 기능만 추가 */
class TemperatureData : public SensorData
{
  private:
    TemperatureData *next;

  public:
    TemperatureData(time_t timestamp, double min, double max, double avg);

    void setNext(TemperatureData *data);
    TemperatureData *getNext();

    string getUnit();
};

#endif /* __TEMPERATURE_H__ */
