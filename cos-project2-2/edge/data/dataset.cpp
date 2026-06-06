#include <cstdlib>
#include <ctime>
#include "dataset.h"

// DataSet 생성자
// 특정 timestamp 기준으로 DataSet을 초기화
// HouseData linked list는 비어있는 상태로 시작
DataSet::DataSet(time_t timestamp) 
{
  this->timestamp = timestamp;
  this->num = 0;
  this->head = NULL;
  this->tail = NULL;
  this->iterator = 0;
}

// HouseData 개수 반환
int DataSet::getNumHouseData()
{
  return this->num;
}

// HouseData 추가 (linked list append)
// tail 기반으로 O(1) 삽입 수행
void DataSet::addHouseData(HouseData *data)
{
  HouseData *curr;

  // 첫 노드인 경우 head 설정
  if (!this->head)
    this->head = data;

  curr = this->tail;

  // 기존 tail이 있으면 next 연결
  if (curr)
    curr->setNext(data);

  // tail 갱신
  this->tail = data;

  // 개수 증가
  this->num++;
}

//index 위치의 HouseData 반환
// linked list를 순차 탐색하여 접근
HouseData *DataSet::getHouseData(int index)
{
  HouseData *ret = this->head;

  if (index < this->num)
  {
    for (int i = 0; i < index; i++)
      ret = ret->getNext();
  }
  else
    ret = NULL;

  return ret;
}


// iterator 초기화
void DataSet::setIterator()
{
  this->iterator = 0;
}


// iterator 기반 다음 HouseData 반환
HouseData *DataSet::getNextHouseData()
{
  HouseData *ret;

  ret = this->getHouseData(this->iterator);

  if (ret)
    this->iterator++;

  return ret;
}


// TemperatureData 설정
void DataSet::setTemperatureData(TemperatureData *temp)
{
  this->temp = temp;
}


// TemperatureData 반환
TemperatureData *DataSet::getTemperatureData()
{
  return this->temp;
}


// HumidityData 설정
void DataSet::setHumidityData(HumidityData *humid)
{
  this->humid = humid;
}


// HumidityData 반환
HumidityData *DataSet::getHumidityData()
{
  return this->humid;
}


// timestamp 반환
time_t DataSet::getTimestamp()
{
  return this->timestamp;
}
