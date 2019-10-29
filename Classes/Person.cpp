//
// Created by ritap on 14/10/2019.
//

#include "Person.h"


Person::Person(string nome, int nif){
    this->nome = nome;
    this->nif = nif;
}

string Person::getNome() const{
    return nome;
}

int Person::getNif() const{
    return nif;
}

Employee::Employee(string nome, int nif, Time birthdate, float income) : Person(nome, nif){
    this->birthdate = birthdate;
    this->income = income;
}


Time Employee::getBirthdate() const{
    return birthdate;
}

float Employee::getIncome() const{
    return income;
}

Admin::Admin(string nome, int nif, Time birthdate, float income, string task): Employee(nome, nif, birthdate, income){
    this->task = task;
}

string Admin::getTask() const{
    return task;
}

Deliverer::Deliverer(string nome, int nif, Time birthdate, float income, Vehicle vehicle, int background) : Employee(nome, nif, birthdate, income){
    this->vehicle = vehicle;
    this->background = background;
}

Vehicle Deliverer::getVehicle() const {
    return vehicle;
}

int Deliverer::getBackground() const {
    return background;
}