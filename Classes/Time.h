#ifndef UGH_EATS_TIME_H
#define UGH_EATS_TIME_H

#include<iostream>

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

};
#endif //UGH_EATS_TIME_H
