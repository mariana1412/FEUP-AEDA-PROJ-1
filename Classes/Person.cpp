#include "Person.h"

Person::Person(string base, string name, int nif){
    this->base = base;
    this->name = name;
    this->nif = nif;
}

string Person::getName() const{
    return name;
}

int Person::getNif() const{
    return nif;
}

string Person::getBase() const{
    return base;
}

void Person::setName(string name){
    this->name = name;
}

void Person::setNif(int nif){
    this->nif = nif;
}

void Person::setBase(string base){
    this->base = base;
}

Client::Client(string base, string name, int nif, string address, bool black, string county):Person(base, name, nif){
    this->address = address;
    this->black = black;
    this->county = county;
}

bool Client::getBlack() const{
    return black;
}

string Client::getAddress() const{
    return address;
}

string Client::getCounty() const{
    return county;
}

void Client::setAddress(string address){
    this->address = address;
}

void Client::setBlack(bool black){
    this->black = black;
}

void Client::setCounty(string county) {
    this->county = county;
}

ostream &operator<<(ostream &os, const Client cl){
    os<< "Name: "<< cl.getName()<<endl
      <<"NIF: "<<cl.getNif()<<endl
      <<"Base: "<<cl.getBase()<<endl
      << "Address: "<<cl.getAddress()<<endl
      <<"County: "<<cl.getCounty()<<endl;
    return os;
}

Employee::Employee(string base, string name, int nif, Time birthdate, float income) : Person(base, name, nif){
    this->birthdate = birthdate;
    this->income = income;
}

Time Employee::getBirthdate() const{
    return birthdate;
}

float Employee::getIncome() const{
    return income;
}

void Employee::setBirthdate(Time birthdate){
    this->birthdate = birthdate;
}

void Employee::setIncome(float income){
    this->income = income;
}

Admin::Admin(string base, string name, int nif, Time birthdate, float income, string task): Employee(base, name, nif, birthdate, income){
    this->task = task;
}

string Admin::getTask() const{
    return task;
}

void Admin::setTask(string task){
    this->task = task;
}

Deliverer::Deliverer(string base, string name, int nif, Time birthdate, float income, Vehicle vehicle, vector<Delivery> background) : Employee(base, name, nif, birthdate, income){
    this->vehicle = vehicle;
    this->background = background;
}

Vehicle Deliverer::getVehicle() const {
    return vehicle;
}

vector<Delivery> Deliverer::getBackground() const {
    return background;
}

void Deliverer::setVehicle(Vehicle vehicle){
    this->vehicle = vehicle;
}

void Deliverer::setBackground(vector<Delivery> background){
    this->background = background;
}



int string_sequential_search(const vector<Client> &v, string x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i].getName() == x)
            return i; // encontrou
    return -1; // não encontrou
}

int int_sequential_search(const vector<Client> &v, int x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i].getNif() == x)
            return i; // encontrou
    return -1; // não encontrou
}