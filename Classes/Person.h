#ifndef UGH_EATS_PERSON_H
#define UGH_EATS_PERSON_H

#include <iostream>
#include <vector>
#include<fstream>
#include "Time.h"
#include "Vehicle.h"
#include "Order.h"
#include "Base.h"

class Time;
class Delivery;
class Vehicle;

using namespace std;

class Person{
private:
    string name;
    int nif;
    string base;
public:
    Person(){};
    Person(string base, string name, int nif);
    string getBase() const;
    string getName() const;
    int getNif() const;
    void setName(string name);
    void setNif(int nif);
    void setBase(string base);

};

class Client:public Person{
private:
    string address;
    bool black;
    string county;
public:
    Client(){};
    Client(string base, string name, int nif, string address, bool black, string county);
    bool getBlack() const;
    string getAddress() const;
    string getCounty() const;
    void setAddress(string address);
    void setBlack(bool black);
    void setCounty(string county);
    friend ostream & operator<<(ostream &os,const Client cl);
};

class Employee: public Person{
private:
    Time* birthdate;
    float income;
public:
    Employee(){};
    virtual ~Employee(){};
    Employee(string base, string name, int nif, Time birthdate, float income);
    Time getBirthdate() const;
    float getIncome() const;
    void setBirthdate(Time birthdate);
    void setIncome(float income);
};


class Admin: public Employee{
private:
    string task;
public:
    Admin(){};
    Admin(string base, string name, int nif, Time birthdate, float income, string task);
    string getTask() const;
    void setTask(string task);
};

class Deliverer: public Employee{
private:
    Vehicle* vehicle;
    vector<Delivery> background;
public:
    Deliverer() {};
    Deliverer(string base, string name, int nif, Time birthdate, float income, Vehicle vehicle, vector<Delivery> background);
    Vehicle getVehicle() const;
    vector<Delivery> getBackground() const;
    void setVehicle(Vehicle vehicle);
    void setBackground(vector<Delivery> background);

};

#endif //UGH_EATS_PERSON_H
