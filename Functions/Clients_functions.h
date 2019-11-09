#ifndef PROJETO_CLIENTS_FUNCTIONS_H
#define PROJETO_CLIENTS_FUNCTIONS_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Classes/Person.h"
#include "../Classes/Base.h"
#include "utils.h"
#include "Verification_Inputs.h"
class Base;
class Client;


using namespace std;
extern const  vector<string> nearby_Porto;
extern const vector<string> nearby_Lisboa;
extern const vector<string> nearby_Faro;

int create_client(Base &Porto, Base &Lisboa, Base &Faro);
int modify_client(Base &Porto, Base &Lisboa, Base &Faro);
int remove_client(Base &Porto, Base &Lisboa, Base &Faro);

bool black_list(Base base, int nif);
bool out_of_area(vector<Client> v,string county);
bool client_already_exists(string nif, Base &b);

#endif //PROJETO_CLIENTS_FUNCTIONS_H
