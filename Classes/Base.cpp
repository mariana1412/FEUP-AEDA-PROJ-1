#include "Base.h"

Base::Base(Location location, string manager, vector<Client>blacklist){
        this->location = &location;
        this->manager=manager;
        this->blacklist=blacklist;
}

Location Base::getLocation() const{
    return *location;
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

vector<Delivery> Base::getDeliveries() const {
    return deliveries;
}

vector<Employee*> Base::getEmployees() const {
    return employees;
}

void Base::setLocation(Location location){
    this->location = &location;
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

void Base::addEmployee(Employee* employee){
    employees.push_back(employee);
}

void Base::addDelivery(Delivery delivery) {
    deliveries.push_back(delivery);
}
