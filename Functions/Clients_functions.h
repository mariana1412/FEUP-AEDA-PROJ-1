#ifndef PROJETO_CLIENTS_FUNCTIONS_H
#define PROJETO_CLIENTS_FUNCTIONS_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Classes/Base.h"
#include "../Functions/Verification_Inputs.h"


using namespace std;

extern const  vector<string> nearby_Porto;
extern const vector<string> nearby_Lisboa;
extern const vector<string> nearby_Faro;

int create_client(Base &Porto, Base &Lisboa, Base &Faro);
int modify_client(Base &Porto, Base &Lisboa, Base &Faro);
int remove_client(Base &Porto, Base &Lisboa, Base &Faro);

void black_list(const Base &base, int nif);
void out_of_area(const vector<Client> &v,string county,string b);
void client_already_exists(string nif, const Base &b);


int int_sequential_search_c(const vector<Client> &v, int x);
int string_sequential_search_c(const vector<Client> &v, string x);

#endif //PROJETO_CLIENTS_FUNCTIONS_H
