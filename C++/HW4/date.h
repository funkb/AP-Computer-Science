#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date{
private:
  int month=1;
  int day = 1;
  int year = 1977;
  int hour = 0;
  int minute = 0;
public:
  Date();
  Date(const int& day,const int& month,const int& year, const int& hour, const int& minute);
  void SetDay(const int& day);
  void SetMonth(const int& month);
  void SetYear(const int& year);
  void SetMinute(const int& minute);
  void SetHour(const int& hour);
  string toString() const;
};
#endif
