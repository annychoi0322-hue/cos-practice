#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__

#include <ctime>
#include <string>
#include "sensor_data.h"

/**
 * TemperatureData: Inherits SensorData.
 * Adds temperature-specific unit and linked list pointer.
 * Used in V1 (avg_temp), V2 (temp_range), V3 (max_temp, min_temp).
 */
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
