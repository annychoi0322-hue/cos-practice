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
    PowerData *next;  // Linked List에서 다음 PowerData를 가리키는 포인터

  public:
    PowerData(time_t timestamp, double avg);   // PowerData 생성자

    void setNext(PowerData *data);             // 다음 노드 설정 (Linked List 연결)
    PowerData *getNext();                      // 다음 노드 반환

    string getUnit();                          // 전력 데이터 단위 반환
};

#endif /* __POWER_DATA_H__ */
