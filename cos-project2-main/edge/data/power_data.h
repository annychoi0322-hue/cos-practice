#ifndef __POWER_DATA_H__
#define __POWER_DATA_H__

#include <ctime>
#include <string>
#include "sensor_data.h"  // Base Class 상속

/* PowerData는 SensorData를 상속받아 전력 특화 기능만 추가 */
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
