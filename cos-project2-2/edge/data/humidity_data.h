#ifndef __HUMIDITY_DATA_H__
#define __HUMIDITY_DATA_H__

#include <ctime>
#include <string>
#include "sensor_data.h"

/**
 * HumidityData: Inherits SensorData.
 * Adds humidity-specific unit and linked list pointer.
 * Used in V1 (avg_humid), V2 (avg_humid), V3 (avg_humid).
 */
class HumidityData : public SensorData
{
  private:
    HumidityData *next;

  public:
    HumidityData(time_t timestamp, double min, double max, double avg);

    void setNext(HumidityData *data);
    HumidityData *getNext();

    string getUnit();
};

#endif /* __HUMIDITY_DATA_H__ */
