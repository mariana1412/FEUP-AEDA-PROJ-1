//
// Created by ritap on 14/10/2019.
//

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
