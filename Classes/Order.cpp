#include"Order.h"


Order::Order(Restaurant restaurant, Time time , vector<Product>products, Deliver deliver){
    this->time = time;
    this->restaurant = restaurant;
    this->products = products;
    this->deliver = deliver;
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

Deliver Order::getDeliver() const{
    return deliver;
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

void Order::setDeliver(Deliver deliver){
    this->deliver = deliver;
}
