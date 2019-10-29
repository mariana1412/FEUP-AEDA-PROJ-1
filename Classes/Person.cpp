#include "Person.h"

Person::Person(string base, string nome, int nif){
    this->base = base;
    this->nome = nome;
    this->nif = nif;
}

string Person::getNome() const{
    return nome;
}

int Person::getNif() const{
    return nif;
}

string Person::getBase() const{
    return base;
}

Client::Client(string base, string nome, int nif, string address, bool black):Person(base, nome, nif){
    this->address = address;
    this->black = black;
}
bool Client::getBlack() const{
    return black;
}

string Client::getAddress() const{
    return address;
}

Employee::Employee(string base, string nome, int nif, Time birthdate, float income) : Person(base, nome, nif){
    this->birthdate = birthdate;
    this->income = income;
}


Time Employee::getBirthdate() const{
    return birthdate;
}

float Employee::getIncome() const{
    return income;
}

Admin::Admin(string base, string nome, int nif, Time birthdate, float income, string task): Employee(base, nome, nif, birthdate, income){
    this->task = task;
}

string Admin::getTask() const{
    return task;
}

Deliverer::Deliverer(string base, string nome, int nif, Time birthdate, float income, Vehicle vehicle, int background) : Employee(base, nome, nif, birthdate, income){
    this->vehicle = vehicle;
    this->background = background;
}

Vehicle Deliverer::getVehicle() const {
    return vehicle;
}

int Deliverer::getBackground() const {
    return background;
}