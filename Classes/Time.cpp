#include "Time.h"
Time::Time(){
    this-> hour=0;
    this-> minutes=0;
    this-> day=0;
    this-> month=0;
    this-> year=0;
}

Time::Time(int hour, int minutes, int day, int month, int year){
    this-> hour=hour;
    this-> minutes=minutes;
    this-> day=day;
    this-> month=month;
    this-> year=year;
}
int Time::getHour() const{
    return hour;
}
int Time::getMinutes() const{
    return minutes;
}
int Time::getDay() const{
    return day;
}
int Time::getMonth() const{
    return month;
}
int Time::getYear() const{
    return year;
}

void Time::setHour(int hour){
    this->hour=hour;
}

void Time::setMinutes(int minutes){
    this->minutes = minutes;
}

void Time::setDay(int day){
    this->day = day;
}

void Time::setMonth(int month){
    this->month = month;
}

void Time::setYear(int year) {
    this->year = year;
}
