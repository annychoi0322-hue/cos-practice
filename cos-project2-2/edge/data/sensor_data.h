#ifndef __SENSOR_DATA_H__
#define __SENSOR_DATA_H__

#include <ctime>
#include <string>
using namespace std;

/**
 * SensorData: Base class for TemperatureData, HumidityData, and PowerData.
 * Provides common attributes (timestamp, avg, min, max, unit) and
 * shared getter/setter methods to eliminate code duplication.
 */

 * TemperatureData, HumidityData, PowerData 등 다양한 센서 데이터 클래스의
 * 공통 구조를 제공하는 부모 클래스이다.
 *
 * 공통 속성:
 * - timestamp : 데이터가 측정된 시간
 * - avg       : 평균값 (공통 측정값)
 * - min       : 최소값 (필요한 센서에서만 사용)
 * - max       : 최대값 (필요한 센서에서만 사용)
 * - unit      : 데이터 단위 (예: "C", "%", "W")
 *
 * 공통 getter/setter를 통해 코드 중복을 줄이기 위한 구조
 */

   
class SensorData           
{
  protected:
    time_t timestamp;   // 데이터가 기록된 시간
    double avg;         // 평균값
    double min;         // 최솟값
    double max;         // 최댓값
    string unit;        // 단위

  public:
    SensorData(time_t timestamp, double avg);                          // 단일 값(avg)만 사용하는 경우 생성자
    SensorData(time_t timestamp, double min, double max, double avg);  // min/max/avg 등 모두 사용하는 경우 생성자

    void setValue(double value);  // 평균값 설정
    double getValue();            // 평균값 반환

    void setMin(double min);      // 최솟값 설정
    double getMin();              // 최솟값 반환

    void setMax(double max);      // 최댓값 설정
    double getMax();              // 최댓값 반환

    void setTimestamp(time_t timestamp);  // timestamp 설정
    time_t getTimestamp();                // timestamp 반환

    string getUnit();                     // 데이터 단위 반환
};

#endif /* __SENSOR_DATA_H__ */
