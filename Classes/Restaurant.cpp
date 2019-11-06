#include "Restaurant.h"

Restaurant::Restaurant(string name, string address, vector<string> types_of_food, vector<Product> products, float revenue){
    this->name = name;
    this-> address=address;
    this-> types_of_food=types_of_food;
    this-> products=products;
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

void Restaurant::setProducts(vector<Product> products){
    this->products = products;
}

void Restaurant::setRevenue(float revenue){
    this->revenue = revenue;
}