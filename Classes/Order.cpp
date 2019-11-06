#include"Order.h"


Order::Order(Restaurant restaurant, Time time , vector<Product>products){
    this->time = time;
    this->restaurant = restaurant;
    this->products = products;

}

Restaurant Order::getRestaurant() const{
    return restaurant;
}

Time Order::getTime() const{
    return time;
}

vector<Product> Order::getProducts()const{
    return products;
}


void Order::setRestaurant(Restaurant restaurant){
    this->restaurant = restaurant;
}

void Order::setTime(Time time){
    this->time = time;
}

void Order::setProducts(vector<Product> products){
    this->products = products;
}


Deliver::Deliver(Restaurant restaurant, Time time , vector<Product>products, bool success, string reason_insucess, Time deliver_time, float price) : Order(restaurant, time, products){
    this->success = success;
    this->reason_insucess = reason_insucess;
    this->deliver_time = deliver_time;
    this->price = price;
}

bool Deliver::getSuccess() const{
    return success;
}

string Deliver::getReason_insucess() const {
    return reason_insucess;
}
Time Deliver::getDeliver_time() const{
    return deliver_time;
}

float Deliver::getPrice() const{
    return price;
}

void Deliver::setSuccess(bool success){
    this->success = success;
}

void Deliver::setReason_insucess(string reason_insucess){
    this->reason_insucess = reason_insucess;
}

void Deliver::setDeliver_time(Time deliver_time){
    this->deliver_time = deliver_time;
}

void Deliver::setPrice(float price){
    this->price = price;
}