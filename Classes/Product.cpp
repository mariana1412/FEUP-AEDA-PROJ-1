#include "Product.h"

Product::Product(string name, string type_of_food, float price){
    this-> name=name;
    this-> type_of_food=type_of_food;
    this-> price=price;
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
