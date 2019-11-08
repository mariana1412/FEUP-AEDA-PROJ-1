#ifndef UGH_EATS_TIME_H
#define UGH_EATS_TIME_H

#include<iostream>
#include <vector>
#include <string>
#include "../Functions/utils.h"

using namespace std;

class Time{
private:
    int hour;
    int minutes;
    int day;
    int month;
    int year;
public:
    Time();
    Time(int hour, int minutes, int day, int month, int year);
    int getHour() const;
    int getMinutes() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setHour(int hour);
    void setHour(string str); //format: hh:mm
    void setMinutes(int minutes);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setDate(string str); //format: dd/mm/yyyy
    void setTime(string str); //format: dd/mm/yyyy, hh:mm
    bool isValid();
    bool isEqualTo(const Time& date);
    bool isNotEqualTo(const Time& date);
    bool isAfter(const Time& date);
    bool isBefore(const Time& date);

};

bool leap_year(int year);
int numberOfDays(int month, int year);
#endif //UGH_EATS_TIME_H
