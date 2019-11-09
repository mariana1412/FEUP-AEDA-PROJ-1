#ifndef PROJETO_EMPLOYEES_FUNCTIONS_H
#define PROJETO_EMPLOYEES_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
//#include "Exceptions.h"
#include "../Classes/Base.h"
#include "Verification_Inputs.h"
#include "StringConverters.h"
class Base;
class Client;

using namespace std;

int create_employee(Base &Porto, Base &Lisboa, Base &Faro);
int modify_employee(Base &Porto, Base &Lisboa, Base &Faro);
int remove_employee(Base &Porto, Base &Lisboa, Base &Faro);

bool employee_already_exists(string nif, Base &b);


int int_sequential_search_e(const vector<Employee*> &v, int x);
int string_sequential_search_e(const vector<Employee*> &v, string x);


#endif //PROJETO_EMPLOYEES_FUNCTIONS_H
