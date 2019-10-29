#include "Base.h"

Base::Base(Location location, string manager, vector <Client> clients, vector<Client>blacklist, vector<Restaurant> restaurants){
        this->location = location;
        this->manager=manager;
        this->clients=clients;
        this->restaurants=restaurants;
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