#ifndef UGH_EATS_BASE_H
#define UGH_EATS_BASE_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "Person.h"


using namespace std;


class Base {
private:
    Location location;
    string manager;
    vector<Client> clients;
    vector<Employee*> employees;
    vector<Client> blacklist;
    vector<Restaurant> restaurants;
    vector<Delivery> deliveries;

public:
    Base(){};
    Base(Location location, string manager, vector<Client>blacklist);
    Location getLocation() const;
    string getManager() const;
    vector<Client> getClients() const;
    vector<Client> getBlackList() const;
    vector<Restaurant> getRestaurants()const;
    vector<Employee*> getEmployees() const;
    vector<Delivery> getDeliveries() const;
    void setLocation(Location location);
    void setManager(string manager);
    void setClients(vector<Client>);
    void setBlacklist(vector<Client> blacklist);
    void setRestaurants(vector<Restaurant> restaurants);
    void addClient(Client client);
    void addRestaurant(Restaurant restaurant);
    void addEmployee(Employee* employees);
    void addDelivery(Delivery delivery);
    bool removeRestaurant(string name);
    Restaurant searchRestaurant(string name);
    int getIndexrestaurant(Restaurant restaurant);

};

#endif //UGH_EATS_BASE_H
