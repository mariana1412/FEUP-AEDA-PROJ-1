//
// Created by ritap on 13/10/2019.
//

#ifndef UGH_EATS_ORDER_H
#define UGH_EATS_ORDER_H

#include <iostream>
#include"Restaurant.h"
#include"Time.h"
#include"Product.h"
#include"Deliver.h"

using namespace std;


class Order{
private:
    Restaurant restaurant;
    Time time;
    vector<Product> products;

public:
    Order(){};
    Order(Restaurant restaurant, Time time , vector<Product>products);
    Restaurant getRestaurant() const;
    Time getTime() const;
    vector<Product> getProducts()const;
    void setRestaurant(Restaurant restaurant);
    void setTime(Time time);
    void setProducts(vector<Product> products);

};

class Deliver : public Order {
private:
    bool success;
    string reason_insucess;
    Time deliver_time;
    float price;
public:
    Deliver(){};
    Deliver(Restaurant restaurant, Time time , vector<Product> products, bool success, string reason_insucess, Time deliver_time, float price, );
    bool getSuccess() const;
    string getReason_insucess() const;
    Time getDeliver_time() const;
    float getPrice() const;
    void setSuccess(bool success);
    void setReason_insucess(string reason_insucess);
    void setDeliver_time(Time deliver_time);
    void setPrice(float price);

};


#endif //UGH_EATS_ORDER_H
