#include "StringConverters.h"


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
    result.setYear(data_clean.at(2));
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
    vector<Delivery> deliveries = b.getDeliveries();
    for (vector<int>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Delivery>::const_iterator it1 = deliveries.begin(); it1 != deliveries.end(); it1++){
            if ((*it) == (it1->getId()))
                result.push_back((*it1));
        }
    }
    return result;
}

Restaurant stringToRestaurantSearch(string str, const Base& b){
    vector<Restaurant> restaurants = b.getRestaurants();
    for (vector<Restaurant>::iterator it = restaurants.begin(); it != restaurants.end(); it++){
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
    vector<Restaurant> restaurants = b.getRestaurants();
    for (vector<string>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Restaurant>::const_iterator it1 = restaurants.begin(); it1 != restaurants.end(); it1++){
            vector<Product> products = it1->getProducts();
            for (vector<Product>::const_iterator it2 = products.begin();it2 != products.end(); it2++){
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
