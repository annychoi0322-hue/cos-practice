#include "process_manager.h"
#include "opcode.h"
#include "byte_op.h"
#include "setting.h"
#include <cstring>
#include <iostream>
#include <ctime>
using namespace std;

// ── 버전 선택 (하나만 주석 해제) ──
// #define PROCESS_VERSION_1
// #define PROCESS_VERSION_2
#define PROCESS_VERSION_3
// ──────────────────────────────────

ProcessManager::ProcessManager()
{
  this->num = 0;
}

void ProcessManager::init()
{
}

uint8_t *ProcessManager::processData(DataSet *ds, int *dlen)
{
  uint8_t *ret, *p;
  int num, tmp;
  HouseData *house;
  TemperatureData *tdata;
  HumidityData *hdata;
  PowerData *pdata;
  double sum_power;
  time_t ts;
  struct tm *tm_info;
  int month;

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

  ts = ds->getTimestamp();
  tm_info = localtime(&ts);
  month = tm_info->tm_mon + 1;

  memset(ret, 0, BUFLEN);
  p = ret;

#if defined(PROCESS_VERSION_1)
  // v1: avg_temp(1B) + avg_humid(1B) + avg_power(2B) + month(1B)
  tmp = (int)tdata->getValue();     VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)hdata->getValue();     VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)(sum_power / num);     VAR_TO_MEM_2BYTES_BIG_ENDIAN(tmp, p);
  tmp = month;                      VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);

#elif defined(PROCESS_VERSION_2)
  // v2: max_temp(1B) + min_temp(1B) + avg_power(2B) + month(1B)
  tmp = (int)tdata->getMax();       VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)tdata->getMin();       VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)(sum_power / num);     VAR_TO_MEM_2BYTES_BIG_ENDIAN(tmp, p);
  tmp = month;                      VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);

#elif defined(PROCESS_VERSION_3)
  // v3: max_humid(1B) + min_humid(1B) + avg_power(2B) + month(1B)
  tmp = (int)hdata->getMax();       VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)hdata->getMin();       VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);
  tmp = (int)(sum_power / num);     VAR_TO_MEM_2BYTES_BIG_ENDIAN(tmp, p);
  tmp = month;                      VAR_TO_MEM_1BYTE_BIG_ENDIAN(tmp, p);

#else
  #error "PROCESS_VERSION not defined."
#endif

  *dlen = p - ret;
  return ret;
}