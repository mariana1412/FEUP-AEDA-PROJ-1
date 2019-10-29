//
// Created by ritap on 13/10/2019.
//

#ifndef UGH_EATS_ORDER_H
#define UGH_EATS_ORDER_H

#include <iostream>
#include"Restaurants.h"
#include"Time.h"
#include"Product.h"
#include"Deliver.h

using namespace std;


class Order{
private:
    Restaurant restaurant;
    Time time;
    vector<Product> products;
    Deliver deliver;
public:
    Order(Restaurant restaurant, Time time , vector<Product>products, Deliver deliver);
    Restaurant getRestaurant() const;
    Time getTime() const;
    vector>Product> getProducts()const;
    Deliver getDeliver() const;

};
#endif //UGH_EATS_ORDER_H
