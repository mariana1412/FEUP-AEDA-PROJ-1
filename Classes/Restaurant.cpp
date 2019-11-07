#include "Restaurant.h"

Restaurant::Restaurant(string name, string address, vector<string> types_of_food, vector<Product> products, float revenue){
    this->name = name;
    this-> address=address;
    this-> types_of_food=types_of_food;
    this-> products=products;
    this-> revenue=revenue;
}
Restaurant::Restaurant(string name, string address, string types_of_food, string products, float revenue){
    this->name = name;
    this-> address=address;
    this->setTypes_of_food(types_of_food);
    this->setProducts(products);
    this-> revenue=revenue;
}

string Restaurant::getName() const {
    return name;
}

string Restaurant::getAddress() const{
    return address;
}

vector<string> Restaurant::getTypes_of_food() const{
    return types_of_food;
}

vector<Product> Restaurant:: getProducts() const{
    return products;
}

float Restaurant::getRevenue() const{
    return revenue;
}


void Restaurant::setName(string name) {
    this->name = name;
}


void Restaurant::setAddress(string address){
    this->address = address;
}

void Restaurant::setTypes_of_food(vector<string> types_of_food){
    this->types_of_food = types_of_food;
}

void Restaurant::setTypes_of_food(string types_of_food){
    string delimiter = ",";
    vector<string> data;
    size_t pos = 0;
    string token;
    while ((pos = types_of_food.find(delimiter)) != std::string::npos) {
        token = types_of_food.substr(0, pos);
        data.push_back(token);
        types_of_food.erase(0, pos + delimiter.length());
    }
    data.push_back(types_of_food);
    for (auto & i : data) {
        trim(i);
        this->addType_of_food(i);
    }

}

void Restaurant::setProducts(vector<Product> products){
    this->products = products;
}

void Restaurant::setProducts(string str){
    string delimiter = "/";
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
        data_clean.push_back((i));
    }
    for (auto & i : data_clean){
        Product current(i);
        this->addProduct(current);
    }

}

void Restaurant::setRevenue(float revenue){
    this->revenue = revenue;
}

void Restaurant::addProduct(Product product){
    this->products.push_back(product);
}
void Restaurant::addType_of_food(string type_of_food){
    this->types_of_food.push_back(type_of_food);
}