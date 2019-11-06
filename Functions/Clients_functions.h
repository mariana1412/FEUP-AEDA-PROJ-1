#ifndef PROJETO_CLIENTS_FUNCTIONS_H
#define PROJETO_CLIENTS_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include "../Classes/Person.h"
#include "../Classes/Base.h"
#include "utils.h"

using namespace std;

int create_client(Base &Porto, Base &Lisboa, Base &Faro);
int modify_client(Base &Porto, Base &Lisboa, Base &Faro);
int remove_client(Base &Porto, Base &Lisboa, Base &Faro);


static const  vector<string> nearby_Porto = { "Matosinhos", "Vila Nova de Gaia", "Maia", "Gondomar", "Porto" };
static const vector<string> nearby_Lisboa = { "Oeiras", "Loures", "Amadora", "Odivelas","Lisboa" };
static const vector<string> nearby_Faro = { "Loulé","Olhão", "São Brás de Alportel","Faro" };

class BlackList {
private:
    string msg;
public:
    BlackList() { msg = "Client belongs to the Black List"; }
    string getMsg() const { return msg; }
};


class OutOfArea {
private:
    string msg;
public:
    OutOfArea() { msg = "It is not possible to create this client, it does not belong to the base area "; }
    string getMsg() const { return msg;  }
};

bool black_list(Base base, int nif) {
    vector<Client> black_list = base.getBlackList();
    if (int_sequential_search(black_list, nif) == -1) {
        throw (BlackList());
    }

    return true;
}

bool out_of_area(vector<Client> v,string county) {
    if (string_sequential_search(v, county) == -1) {
        throw(OutOfArea());
    }
    return true;
}

#endif //PROJETO_CLIENTS_FUNCTIONS_H
