#include "Product.h"

Product::Product(string name, string type_of_food, float price){
    this-> name=name;
    this-> type_of_food=type_of_food;
    this-> price=price;
}

Product::Product(string product){
    string delimiter = ",";
    vector<string> data;
    vector<string> result;
    size_t pos = 0;
    string token;
    while ((pos = product.find(delimiter)) != std::string::npos) {
        token = product.substr(0, pos);
        data.push_back(token);
        product.erase(0, pos + delimiter.length());
    }
    data.push_back(product);
    for (auto & i : data) {
        trim(i);
        result.push_back(i);
    }

    this->name = result[0];
    this->type_of_food = result[1];
    this->price = stof(result[2]);
}

string Product::getName() const{
    return name;
}

string Product::getType_of_food() const{
    return type_of_food;
}

float Product::getPrice() const{
    return price;
}

void Product::setName(string name){
    this->name = name;
}

void Product::setType_of_food(string type_of_food){
    this->type_of_food = type_of_food;
}

void Product::setprice(float price){
    this->price = price;
}
