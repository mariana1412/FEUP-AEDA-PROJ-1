#ifndef UGH_EATS_ORDER_H
#define UGH_EATS_ORDER_H

#pragma once
#include <iostream>
#include "Restaurant.h"
#include "Vehicle.h"

using namespace std;

class Order{
private:
    Restaurant restaurant;
    Time time;
    vector<Product> products;

protected:
    float price;

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

class Delivery : public Order {
private:
    int id;
    bool success;
    string reason_insuccess;
    Time deliver_time;
    float tax;
    float final_price;
public:
    Delivery(){};
    Delivery(Restaurant restaurant, Time time , vector<Product> products, int id, bool success, string reason_insuccess, Time deliver_time, float tax);
    int getId() const;
    bool getSuccess() const;
    string getReason_insuccess() const;
    Time getDeliver_time() const;
    float getPrice() const;
    float getFinalPrice() const;
    float getTax() const;
    void setSuccess(bool success);
    void setReason_insuccess(string reason_insucess);
    void setDeliver_time(Time deliver_time);
    void setPrice(float price);


};


#endif //UGH_EATS_ORDER_H
