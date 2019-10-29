#include "Deliver.h"



Deliver::Deliver(bool success, string reason_insucess, Time deliver_time, float price){
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