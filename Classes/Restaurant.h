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
    void setAddress(string address);
    void setTypes_of_food(vector<string> types_of_food);
    void setProducts(vector<Product> products);
    void setRevenue(float revenue);
};


#endif //UGH_EATS_RESTAURANTS_H
