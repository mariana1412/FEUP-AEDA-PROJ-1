#ifndef UGH_EATS_RESTAURANTS_H
#define UGH_EATS_RESTAURANTS_H

#include <iostream>
#include <string>
#include <vector>
#include "Product.h"

using namespace std;

class Restaurant{
private:
    string address;
    vector<string> types_of_food;
    vector<Product> products;
    float revenue;

public:
    Restaurant(){};
    Restaurant(string address, vector<string> types_of_food, vector<Product> products, float revenue);
    string getAddress() const;
    vector<string> getTypes_of_food() const;
    vector<Product> getProducts() const;
    float getRevenue() const;
};


#endif //UGH_EATS_RESTAURANTS_H
