#ifndef UGH_EATS_TIME_H
#define UGH_EATS_TIME_H

#pragma once

#include<iostream>
#include<iomanip>

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
    void setMinutes(int minutes);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    bool isValid();
    bool isEqualTo(const Time& date);
    bool isNotEqualTo(const Time& date);
    bool isAfter(const Time& date);
    bool isBefore(const Time& date);
    friend ostream &operator <<(ostream &os,const Time t);

};

bool leap_year(int year);
int numberOfDays(int month, int year);
#endif //UGH_EATS_TIME_H
