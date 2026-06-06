#ifndef __HUMIDITY_DATA_H__
#define __HUMIDITY_DATA_H__

#include <ctime>
#include <string>
#include "sensor_data.h"  // Base Class 상속

/* HumidityData는 SensorData를 상속받아 습도 특화 기능만 추가 */
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
