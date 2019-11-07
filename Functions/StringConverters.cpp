#include "StringConverters.h"

Location stringToLocation(string str){ //Morada da base, morada do cliente
    string delimiter = ",";
    vector<string> data;
    vector<string> data_clean;
    Location result;
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
        result.setAddress(data_clean.at(0));
        result.setCounty(data_clean.at(1));
        result.setGps(data_clean.at(2));
    }
    else{
        result.setAddress(data_clean.at(0));
        result.setAddress(data_clean.at(1));
    }
    return result;
}

//Returns a client if str is the client's NIF
vector<Client> stringToClientVectorSearch(string str, const Base& b) {   //Blacklist
    string delimiter = ",";
    vector<string> data;
    vector<int> data_clean;
    vector<Client> result;
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
    for (vector<int>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Client>::const_iterator it1 = b.getClients().begin(); it1 != b.getClients().end(); it1++){
            if ((*it) == it1->getNif())
                result.push_back((*it1));
        }
    }
    return result;
}

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
        current.setprice(stof(stringToStringVector(i).at(2)));
        result.push_back(current);
    }
    return result;
}

Time stringToDate(string str){
    string delimiter = "/";
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
    result.setDay(data_clean.at(0));
    result.setMonth(data_clean.at(1));
    result.setYear(data_clean.at(0));
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

vector<Delivery> stringToDeliveryVectorSearch(string str, const Base& b){
    string delimiter = ",";
    vector<string> data;
    vector<int> data_clean;
    vector<Delivery> result;
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
    for (vector<int>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Delivery>::const_iterator it1 = b.getDeliveries().begin(); it1 != b.getDeliveries().end(); it1++){
            if ((*it) == (it1->getId()))
                result.push_back((*it1));
        }
    }
    return result;
}

Restaurant stringToRestaurantSearch(string str, const Base& b){
    for (vector<Restaurant>::const_iterator it = b.getRestaurants().begin(); it != b.getRestaurants().end(); it++){
        if (str == it->getName())
            return (*it);
    }
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

vector<Product> stringToProductVectorSearch(string str, const Base& b){
    string delimiter = ",";
    vector<string> data;
    vector<string> data_clean;
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
        data_clean.push_back(i);
    }
    for (vector<string>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Restaurant>::const_iterator it1 = b.getRestaurants().begin(); it1 != b.getRestaurants().end(); it1++){
            for (vector<Product>::const_iterator it2 = (*it1).getProducts().begin();it2 != (*it1).getProducts().end(); it2++){
                if ((*it) == (it2->getName()))
                    result.push_back((*it2));
            }
        }
    }
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
