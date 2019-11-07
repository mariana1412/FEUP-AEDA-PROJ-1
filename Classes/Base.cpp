#include "Base.h"

Base::Base(Location location, string manager, vector<Client>blacklist){
        this->location = location;
        this->manager=manager;
        this->blacklist=blacklist;
}

Location Base::getLocation() const{
    return location;
}

string Base::getManager() const{
    return manager;
}

vector<Client> Base::getClients() const{
    return clients;
}

vector<Client> Base::getBlackList() const{
    return blacklist;
}

vector<Restaurant> Base::getRestaurants()const{
    return restaurants;
}

void Base::setLocation(Location location){
    this->location = location;
}

void Base::setManager(string manager){
    this->manager = manager;
}

void Base::setClients(vector<Client>){
    this->clients = clients;
}

void Base::setBlacklist(vector<Client> blacklist){
    this->blacklist = blacklist;
}

void Base::setRestaurants(vector<Restaurant> restaurants){
    this->restaurants = restaurants;
}

void Base::addClient(Client client) {
    clients.push_back(client);
}

void Base::addRestaurant(Restaurant restaurant) {
    restaurants.push_back(restaurant);
}

void Base::addAdmin(Admin admin) {
    admins.push_back(admin);
}

void Base::addDeliverer(Deliverer deliverer) {
    deliverers.push_back(deliverer);
}

vector<Admin> Base::getAdmins() const {
    return admins;
}

vector<Deliverer> Base::getDeliverers() const {
    return deliverers;
}

vector<Delivery> Base::getDeliveries() const {
    return deliveries;
}

void Base::addDelivery(Delivery delivery) {
    deliveries.push_back(delivery);
}
