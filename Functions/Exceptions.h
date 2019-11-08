#ifndef PROJETO_EXCEPTIONS_H
#define PROJETO_EXCEPTIONS_H

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

class RestaurantNotFound {
private:
    string name;
public:
    RestaurantNotFound(string n) {this->name = name; }
    string getName() const {return name;}
};



#endif //PROJETO_EXCEPTIONS_H
