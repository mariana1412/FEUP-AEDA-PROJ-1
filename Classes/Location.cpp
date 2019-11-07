#include "Location.h"


Location::Location(string str){
    string delimiter = ",";
    vector<string> data;
    vector<string> data_clean;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data)
    {
        trim(i);
        data_clean.push_back(i);
    }
    if (data_clean.size() == 3){
        this->address = data_clean.at(0);
        this->county = data_clean.at(1);
        this->gps = data_clean.at(2);
    }
    else{
        this->address = data_clean.at(0);
        this->county = data_clean.at(1);
    }
}

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

void Location::setAddress(string address){
    this->address = address;
}

void Location::setCounty(string county){
    this->county = county;
}

void Location::setGps(string gps){
    this->gps = gps;
}