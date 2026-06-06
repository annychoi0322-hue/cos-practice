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
class SensorData
{
  protected:
    time_t timestamp;
    double avg;
    double min;
    double max;
    string unit;

  public:
    SensorData(time_t timestamp, double avg);
    SensorData(time_t timestamp, double min, double max, double avg);

    void setValue(double value);
    double getValue();

    void setMin(double min);
    double getMin();

    void setMax(double max);
    double getMax();

    void setTimestamp(time_t timestamp);
    time_t getTimestamp();

    string getUnit();
};

#endif /* __SENSOR_DATA_H__ */
