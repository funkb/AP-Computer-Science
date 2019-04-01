#include "date.h"
#include <iostream>

using namespace std;

Date::Date(){
  int day = 1;
  int month = 1;
  int year = 1977;
  int hour = 0;
  int minute = 0;
}

Date::Date(const int& day,const int& month,const int& year, const int& hour, const int& minute):
day(day), month(month),year(year),hour(hour),minute(minute){ }

void Date::SetDay(const int& day){
  this->day = day;
}

void Date::SetMonth(const int& month){
  if(month <= 12 && month >= 1)
    this->month = month;
  else
    cout << "Month must be between 1 and 12" << endl;
}

void Date::SetYear(const int& year){
  this->year = year;
}

void Date::SetHour(const int& hour){
  this->hour = hour;
}

void Date::SetMinute(const int& minute){
  this->minute = minute;
}

string Date::toString() const{

  string monthName[] = { "January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };
  string time;

  string TOD = (hour < 12) ? "AM" : "PM";

  if(hour == 0){
    time = "12:";
  }else if(hour < 13){
    time = to_string(hour) + ":";
  }else{
    time = to_string(hour-12) + ":";
  }
  if(minute<10){
    time += "0" + to_string(minute) + " " + TOD;
  }else{
    time += to_string(minute) + " " + TOD;
  }
  return monthName[month-1] + " " + to_string(day) + ", " + to_string(year) + "  " + time;
}
