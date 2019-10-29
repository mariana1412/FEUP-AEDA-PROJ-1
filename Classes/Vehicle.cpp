#include "Vehicle.h"

Vehicle::Vehicle(){}

Vehicle::Vehicle(string brand, string type, Time date){
    this->brand = brand;
    this->type = type;
    this->date = date;
}
string Vehicle::getBrand() const{
    return brand;
}
string Vehicle::getType() const{
    return type;
}
Time Vehicle::getDate() const{
    return date;
}


