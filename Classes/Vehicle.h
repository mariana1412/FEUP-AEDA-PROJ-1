#ifndef UGH_EATS_VEHICLE_H
#define UGH_EATS_VEHICLE_H

#include <iostream>
#include <vector>
#include <string>
#include "Time.h"
#include "../Functions/utils.h"
class Time;

using namespace std;

class Vehicle{
private:
    string brand;
    string type;
    Time* date;
public:
    Vehicle();
    Vehicle(string brand, string type, Time date);
    Vehicle(string vehicle);
    string getBrand() const;
    string getType() const;
    Time getDate() const;
    void setBrand(string brand);
    void setType(string type);
    void setDate(Time date);
    void setDate(string date);

};


#endif //UGH_EATS_VEHICLE_H
