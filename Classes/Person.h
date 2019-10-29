#ifndef UGH_EATS_PERSON_H
#define UGH_EATS_PERSON_H

#include<iostream>
#include"Time.h"
#include "Vehicle.h"

using namespace std;

class Person{
private:
    string nome;
    int nif;
    string base;
public:
    Person(){};
    Person(string base, string nome, int nif);
    string getBase() const;
    string getNome() const;
    int getNif() const;

};

class Client:public Person{
private:
    string address;
    bool black;
public:
    Client(){};
    Client(string base, string nome, int nif, string address, bool black);
    bool getBlack() const;
    string getAddress() const;
};

class Employee: public Person{
private:
    Time birthdate;
    float income;
public:
    Employee(){};
    Employee(string base, string nome, int nif, Time birthdate, float income);
    Time getBirthdate() const;
    float getIncome() const;
};


class Admin: public Employee{
private:
    string task;
public:
    Admin(){};
    Admin(string base, string nome, int nif, Time birthdate, float income, string task);
    string  getTask() const;
};

class Deliverer: public Employee{
private:
    Vehicle vehicle;
    int background;
public:
    Deliverer() {};
    Deliverer(string base, string nome, int nif, Time birthdate, float income, Vehicle vehicle, int background);
    Vehicle getVehicle() const;
    int getBackground() const;

};

#endif //UGH_EATS_PERSON_H
