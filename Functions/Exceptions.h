#ifndef PROJETO_EXCEPTIONS_H
#define PROJETO_EXCEPTIONS_H

#pragma once
#include <string>


using namespace std;

class BlackList {
private:
    string msg;
public:
    BlackList() { msg = "Client belongs to the Black List!"; }
    string getMsg() const { return msg; }
};


class OutOfArea {
private:
    string msg;
public:
    OutOfArea() { msg = "It is not possible to create this client, it does not belong to the base area! "; }
    string getMsg() const { return msg;  }
};

class RestaurantOutOfArea {
private:
    string county;
public:
    RestaurantOutOfArea(string c) {this->county = county;}
    string getCounty() const {return county;}
};

class RestaurantNotFound {
private:
    string name;
public:
    RestaurantNotFound(string n) {this->name = name; }
    string getName() const {return name;}
};

class RestaurantAlreadyExists {
private:
    string name;
public:
    RestaurantAlreadyExists(string n) {this->name = name;}
    string getName() const {return name;}
};


class ProductAlreadyExists {
private:
    string name;
public:
    ProductAlreadyExists(string name) {this->name = name;}
    string getName() const {return name;}
};

class ProductNotFound {
private:
    string name;
public:
    ProductNotFound(string p) {this->name = p;}
    string getName() const {return name;}
};

class ClientAlreadyExists{
private:
    string nif;
public:
    ClientAlreadyExists(string name){this->nif=nif;}
    string getNIF() const{return nif;}
};


#endif //PROJETO_EXCEPTIONS_H
