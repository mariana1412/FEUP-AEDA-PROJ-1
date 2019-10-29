//
// Created by ritap on 13/10/2019.
//

#ifndef UGH_EATS_PRODUCT_H
#define UGH_EATS_PRODUCT_H

#include<string>
#include<iostream>
#include"Product.h"

using namespace std;

class Product{
private:
    string name;
    string type_of_food;
    float price;
public:
    Product(string name, string type_of_food, float price);
    string getName() const;
    string getType_of_food() const;
    float getPrice() const;
};


#endif //UGH_EATS_PRODUCT_H
