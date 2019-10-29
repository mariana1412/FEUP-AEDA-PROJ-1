//
// Created by ritap on 14/10/2019.
//

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

