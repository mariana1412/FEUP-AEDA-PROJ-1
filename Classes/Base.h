#ifndef UGH_EATS_BASE_H
#define UGH_EATS_BASE_H

#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "Person.h"
#include "Restaurant.h"
class Location;
class Restaurant;
class Client;
class Deliverer;

using namespace std;


class Base {
private:
    Location location;
    string manager;
    vector<Client> clients;
    vector<Deliverer> deliverers;
    vector<Admin> admins;
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
    vector<Admin> getAdmins() const;
    vector<Deliverer> getDeliverers() const;
    vector<Delivery> getDeliveries() const;
    void setLocation(Location location);
    void setManager(string manager);
    void setClients(vector<Client>);
    void setBlacklist(vector<Client> blacklist);
    void setRestaurants(vector<Restaurant> restaurants);
    void addClient(Client client);
    void addRestaurant(Restaurant restaurant);
    void addAdmin(Admin admin);
    void addDeliverer(Deliverer deliverer);
    void addDelivery(Delivery delivery);

};


#endif //UGH_EATS_BASE_H
