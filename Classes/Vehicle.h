#ifndef UGH_EATS_VEHICLE_H
#define UGH_EATS_VEHICLE_H

#include<iostream>
#include"Time.h"

using namespace std;

class Vehicle{
private:
    string brand;
    string type;
    Time date;
public:
    Vehicle();
    Vehicle(string brand, string type, Time date);
    string getBrand() const;
    string getType() const;
    Time getDate() const;
    void setBrand(string brand);
    void setType(string type);
    void setDate(Time date);

};


#endif //UGH_EATS_VEHICLE_H
