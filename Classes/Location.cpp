#include "Location.h"

#include "Location.h"

Location::Location() {}

Location::Location(string address, string county, string gps){
    this-> address=address;
    this-> county=county;
    this-> gps=gps;
}
string Location::getAddress() const{
    return address;
}
string Location::getCounty() const{
    return county;
}
string Location::getGps() const{
    return gps;
}