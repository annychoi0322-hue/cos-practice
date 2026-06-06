#include <cstdlib>
#include <iostream>
#include "house_data.h"


// Info 객체만 연결하고 PowerData는 없는 상태로 초기화
HouseData::HouseData(Info *info)
{
  this->info = info;  // 기본 정보 설정
  this->data = NULL;  // 전력 데이터 없음
}


// HouseData 생성자 (Info + PowerData 포함)
HouseData::HouseData(Info *info, PowerData *power)
{
  this->info = info;  // 기본 정보 설정
  this->data = power; // 전력 데이터 설정
}


// Info 객체 설정
void HouseData::setInfo(Info *info)
{
  this->info = info;
}

// Info 객체 반환
Info *HouseData::getInfo()
{
  return this->info;
}

// serial 값 반환
string HouseData::getSerial()
{
  return this->info->getSerial();
}

// name 값 반환
string HouseData::getName()
{
  return this->info->getName();
}

// address 값 반환
string HouseData::getAddress()
{
  return this->info->getAddress();
}

// PowerData 설정
void HouseData::setPowerData(PowerData *power)
{
  this->data = power;
}

// PowerData 반환
PowerData *HouseData::getPowerData()
{
  return this->data;
}

// Linked List에서 다음 HouseData 설정
void HouseData::setNext(HouseData *data)
{
  this->next = data;
}

// Linked List에서 다음 HouseData 반환
HouseData *HouseData::getNext()
{
  return this->next;
}
