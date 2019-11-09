#ifndef UGH_EATS_PRODUCT_H
#define UGH_EATS_PRODUCT_H

#include <string>
#include <vector>
#include <iostream>
#include "../Functions/utils.h"

using namespace std;

class Product{
private:
    string name;
    string type_of_food;
    float price;
public:
    Product(){};
    Product(string name, string type_of_food, float price);
    Product(string product);
    string getName() const;
    string getType_of_food() const;
    float getPrice() const;
    void setName(string name);
    void setType_of_food(string type_of_food);
    void setprice(float price);
    bool operator==(const Product& prod) const;
};


#endif //UGH_EATS_PRODUCT_H
