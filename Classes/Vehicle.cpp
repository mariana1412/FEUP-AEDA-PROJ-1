#include "Vehicle.h"

Vehicle::Vehicle(){}

Vehicle::Vehicle(string brand, string type, Time date){
    this->brand = brand;
    this->type = type;
    this->date = &date;
}

Vehicle::Vehicle(string vehicle){
    string delimiter = ",";
    vector<string> data;
    vector<string> data_clean;
    Vehicle result;
    size_t pos = 0;
    string token;
    while ((pos = vehicle.find(delimiter)) != std::string::npos) {
        token = vehicle.substr(0, pos);
        data.push_back(token);
        vehicle.erase(0, pos + delimiter.length());
    }
    data.push_back(vehicle);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(i);
    }
    this->brand = data_clean.at(0);
    this->type = data_clean.at(1);
    result.setDate(data_clean.at(2));
}

string Vehicle::getBrand() const{
    return brand;
}

string Vehicle::getType() const{
    return type;
}

Time Vehicle::getDate() const{
    return *date;
}

void Vehicle::setBrand(string brand){
    this-> brand = brand;
}

void Vehicle::setType(string type){
    this->type = type;
}

void Vehicle::setDate(Time date){
    this->date = &date;
}

void Vehicle::setDate(string date){
    string delimiter = "/";
    vector<string> data;
    vector<int> data_clean;
    Time result;
    size_t pos = 0;
    string token;
    while ((pos = date.find(delimiter)) != std::string::npos) {
        token = date.substr(0, pos);
        data.push_back(token);
        date.erase(0, pos + delimiter.length());
    }
    data.push_back(date);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    result.setDay(data_clean.at(0));
    result.setMonth(data_clean.at(1));
    result.setYear(data_clean.at(2));
    this->date = &result;

}


