#include "process_manager.h"
#include "opcode.h"
#include "byte_op.h"
#include "setting.h"
#include <cstring>
#include <iostream>
#include <ctime>
using namespace std;

ProcessManager::ProcessManager()
{
  this->num = 0;
}

void ProcessManager::init()
{
}

// TODO: You should implement this function if you want to change the result of the aggregation
uint8_t *ProcessManager::processData(DataSet *ds, int *dlen)
{
  uint8_t *ret, *p;
  int num, len;
  HouseData *house;
  Info *info;
  TemperatureData *tdata;
  HumidityData *hdata;
  PowerData *pdata;
  char buf[BUFLEN];
  ret = (uint8_t *)malloc(BUFLEN);
  int tmp, min_humid, min_temp, min_power, month;
  double sum_power;
  time_t ts;
  struct tm *tm;

  ret = (uint8_t *)malloc(BUFLEN);



  num = ds->getNumHouseData();
  sum_power = 0;
  for (int i = 0; i < num; i++) {
    house = ds->getHouseData(i);
    pdata = house->getPowerData();
    sum_power += pdata->getValue();
  }

  tdata = ds->getTemperatureData();
  hdata = ds->getHumidityData();

  ::memset(ret, 0, BUFLEN);
  p = ret;

  tmp = 1; VAR_TO_MEM_1BYTE(tmp, p);                        // version = 1

  tmp = (int)(sum_power / num);
  VAR_TO_MEM_2BYTES_BIG_ENDIAN(tmp, p);                     // avg_power (2B)

  tmp = (int)tdata->getValue(); VAR_TO_MEM_1BYTE(tmp, p);   // avg_temp  (1B)
  tmp = (int)hdata->getValue(); VAR_TO_MEM_1BYTE(tmp, p);   // avg_humid (1B)

  *dlen = p - ret;  // = 5
  return ret;
}


  // Example) getting the month value from the timestamp
  ts = ds->getTimestamp();
  tm = localtime(&ts);
  month = tm->tm_mon + 1;

  // Example) initializing the memory to send to the network manager
  memset(ret, 0, BUFLEN);
  *dlen = 0;
  p = ret;

  // Example) saving the values in the memory
#if defined(PROCESS_VERSION_1)
  // v1: avg_temp + avg_humid + avg_power + month
  tmp = (int)tdata->getValue();        
  VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)hdata->getValue();        
  VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)(sum_power / num);        
  VAR_TO_MEM_2BYTES_BIG_ENDIAN(tmp, p);
  tmp = month;                         
  VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);

#elif defined(PROCESS_VERSION_2)
  // v2: max_temp + min_temp + avg_power + month
  tmp = (int)tdata->getMax();          
  VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)tdata->getMin();          
  VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)(sum_power / num);        
  VAR_TO_MEM_2BYTES_BIG_ENDIAN(tmp, p);
  tmp = month;                         
  VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);

#elif defined(PROCESS_VERSION_3)
  // v3: max_humid + min_humid + avg_power + month
  tmp = (int)hdata->getMax();          
  VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)hdata->getMin();          
  VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)(sum_power / num);        
  VAR_TO_MEM_2BYTES_BIG_ENDIAN(tmp, p);
  tmp = month;                         
  VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);

#else
 #error "PROCESS_VERSION not defined."
#endif

  *dlen = p - ret;  // = 5
  return ret;
}

