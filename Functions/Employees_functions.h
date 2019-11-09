#ifndef PROJETO_EMPLOYEES_FUNCTIONS_H
#define PROJETO_EMPLOYEES_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
//#include "Exceptions.h"
#include "../Classes/Person.h"
#include "../Classes/Base.h"
#include "utils.h"
#include "Verification_Inputs.h"
class Base;
class Client;

using namespace std;

int create_employee(Base &Porto, Base &Lisboa, Base &Faro);
int modify_employee(Base &Porto, Base &Lisboa, Base &Faro);
int remove_employee(Base &Porto, Base &Lisboa, Base &Faro);






#endif //PROJETO_EMPLOYEES_FUNCTIONS_H
