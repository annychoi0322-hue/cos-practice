#ifndef __POWER_DATA_H__
#define __POWER_DATA_H__

#include <ctime>
#include <string>
#include "sensor_data.h"

/**
 * PowerData: Inherits SensorData.
 * Only uses avg (daily power value, 200-300 kWh range).
 * min/max are unused and initialized to 0 in SensorData.
 */
class PowerData : public SensorData
{
  private:
    PowerData *next;

  public:
    PowerData(time_t timestamp, double avg);

    void setNext(PowerData *data);
    PowerData *getNext();

    string getUnit();
};

#endif /* __POWER_DATA_H__ */
