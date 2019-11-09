#ifndef UGH_EATS_RESTAURANTS_H
#define UGH_EATS_RESTAURANTS_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Base.h"
#include "Location.h"
#include "Order.h"
#include "Person.h"
#include "Product.h"
#include "Time.h"
#include "../Functions/utils.h"
class Product;
class Base;

using namespace std;

extern const  vector<string> nearby_Porto;
extern const vector<string> nearby_Lisboa;
extern const vector<string> nearby_Faro;

class Restaurant{
private:
    string name;
    string address;
    string county;
    vector<string> types_of_food;
    vector<Product> products;
    float revenue;

public:
    Restaurant(){};
    Restaurant(string name, string address, string county, vector<string> types_of_food, vector<Product> products, float revenue);
    string getName() const;
    string getAddress() const;
    string getCounty() const;
    vector<string> getTypes_of_food() const;
    vector<Product> getProducts() const;
    float getRevenue() const;
    void setName(string name);
    void setName(string name, const Base &b);
    void setCounty(string county);
    void setCounty(string county, string base);
    void setAddress(string address);
    void setTypes_of_food(vector<string> types_of_food);
    void setProducts(vector<Product> products);
    void setRevenue(float revenue);
    void addProduct(Product product);
    void addType_of_food(string type_of_food);
    bool operator==(const Restaurant& rest) const;
    Product searchProduct(string name);
    int getIndexProduct(Product product);
    bool removeProduct(string name);
};


#endif //UGH_EATS_RESTAURANTS_H
