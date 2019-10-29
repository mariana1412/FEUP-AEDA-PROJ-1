#ifndef UGH_EATS_BASE_H
#define UGH_EATS_BASE_H

#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "Person.h"
#include "Restaurant.h"


using namespace std;


class Base {
private:
    Location location;
    string manager;
    vector<Client> clients;
    vector<Client> blacklist;
    vector<Restaurant> restaurants;

public:
    Base(Location location, string manager, vector <Client> clients, vector<Client>blacklist, vector<Restaurant> restaurants);
    Location getLocation() const;
    string getManager() const;
    vector<Client> getClients() const;
    vector<Client> getBlackList() const;
    vector<Restaurant> getRestaurants()const;
};


#endif //UGH_EATS_BASE_H
