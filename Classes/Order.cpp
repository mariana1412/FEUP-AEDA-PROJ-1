#include"Order.h"


Order::Order(Restaurant restaurant, Time time , vector<Product>products){
    this->time = time;
    this->restaurant = restaurant;
    this->products = products;
    for (vector<Product>::const_iterator it = products.begin(); it != products.end(); it++){
        this->price += it->getPrice();
    }
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


Delivery::Delivery(Restaurant restaurant, Time time , vector<Product> products, int id, bool success, string reason_insuccess, Time deliver_time, float tax): Order(restaurant, time , products){
    this->id = id;
    this->success = success;
    this->reason_insuccess = reason_insuccess;
    this->deliver_time = deliver_time;
    this->tax = tax;
    this->final_price = this->price + this->tax;
}

int Delivery::getId() const {
    return id;
}

bool Delivery::getSuccess() const{
    return success;
}

string Delivery::getReason_insuccess() const {
    return reason_insuccess;
}
Time Delivery::getDeliver_time() const{
    return deliver_time;
}

float Delivery::getPrice() const{
    return price;
}

void Delivery::setSuccess(bool success){
    this->success = success;
}

void Delivery::setReason_insuccess(string reason_insuccess){
    this->reason_insuccess = reason_insuccess;
}

void Delivery::setDeliver_time(Time deliver_time){
    this->deliver_time = deliver_time;
}

void Delivery::setPrice(float price){
    this->price = price;
}
float Delivery::getFinalPrice() const {
    return final_price;
}

float Delivery::getTax() const {
    return tax;
}


