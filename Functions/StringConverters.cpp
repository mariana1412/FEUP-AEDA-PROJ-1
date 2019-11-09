#include "StringConverters.h"

vector<string> stringToStringVector(string str){ //Types of food
    string delimiter = ",";
    vector<string> data;
    vector<string> result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        result.push_back(i);
    }

    return result;
}

vector<Product> stringToProductVector(string str){
    string delimiter = "/";
    vector<string> data;
    vector<string> data_clean;
    Product current;
    vector<Product> result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back((i));
    }
    for (auto & i : data_clean){
        current.setName(stringToStringVector(i).at(0));
        current.setType_of_food(stringToStringVector(i).at(1));
        current.setPrice(stof(stringToStringVector(i).at(2)));
        result.push_back(current);
    }
    return result;
}

Time stringToDate(string str){
    string delimiter = "/";
    vector<string> data;
    vector<int> data_clean;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    Time result(0,0,data_clean.at(0),data_clean.at(1),data_clean.at(2));
    return result;
}

Vehicle stringToVehicle(string str){
    string delimiter = ",";
    vector<string> data;
    vector<string> data_clean;
    Vehicle result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(i);
    }
    result.setBrand(data_clean.at(0));
    result.setType(data_clean.at(1));
    result.setDate(stringToDate(data_clean.at(2)));
    return result;
}

Time stringToTime(string str){
    vector<string> split = stringToStringVector(str);
    Time result = stringToDate(split.at(0));
    str= split.at(1);
    string delimiter = ":";
    vector<string> data;
    vector<int> data_clean;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    result.setHour(data_clean.at(0));
    result.setMinutes(data_clean.at(1));
    return result;
}

Time stringToHour(string str){
    string delimiter = ":";
    vector<string> data;
    vector<int> data_clean;
    Time result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    result.setHour(data_clean.at(0));
    result.setMinutes(data_clean.at(1));
    return result;
}

Location stringToLocation(string str){
    Location location;
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
        location.setAddress(data_clean.at(0));
        location.setCounty(data_clean.at(1));
        location.setGps(data_clean.at(2));
    }
    else{
        location.setAddress(data_clean.at(0));
        location.setCounty(data_clean.at(1));
    }

    return location;
}