#ifndef UGH_EATS_RESTAURANTS_H
#define UGH_EATS_RESTAURANTS_H

#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "../Functions/utils.h"
class Product;

using namespace std;

class Restaurant{
private:
    string name;
    string address;
    vector<string> types_of_food;
    vector<Product> products;
    float revenue;

public:
    Restaurant(){};
    Restaurant(string name, string address, vector<string> types_of_food, vector<Product> products, float revenue);
    Restaurant(string name, string address, string types_of_food, string products, float revenue);
    string getName() const;
    string getAddress() const;
    vector<string> getTypes_of_food() const;
    vector<Product> getProducts() const;
    float getRevenue() const;
    void setName(string name);
    void setAddress(string address);
    void setTypes_of_food(vector<string> types_of_food);
    void setTypes_of_food(string types_of_food);
    void setProducts(vector<Product> products);
    void setProducts(string products);
    void setRevenue(float revenue);
    void addProduct(Product product);
    void addType_of_food(string type_of_food);
};


#endif //UGH_EATS_RESTAURANTS_H
