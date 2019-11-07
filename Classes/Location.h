#ifndef UGH_EATS_LOCATION_H
#define UGH_EATS_LOCATION_H

#include <iostream>
#include <string>
#include <vector>
#include "../Functions/utils.h"

using namespace std;

class Location{
private:
    string address;
    string county;
    string gps;
public:
    Location(){};
    Location(string str);
    Location(string address, string county, string gps);
    string getAddress() const;
    string getCounty() const;
    string getGps() const;
    void setAddress(string address);
    void setCounty(string county);
    void setGps(string gps);
};


#endif //UGH_EATS_LOCATION_H
