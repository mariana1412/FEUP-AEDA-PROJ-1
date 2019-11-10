#ifndef PROJETO_ORDER_FUNCTIONS_H
#define PROJETO_ORDER_FUNCTIONS_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Classes/Base.h"
#include "../Functions/Verification_Inputs.h"

using namespace std;

int create_order(Base &Porto, Base &Lisboa, Base &Faro);
int modify_order(Base &Porto, Base &Lisboa, Base &Faro);
int remove_order(Base &Porto, Base &Lisboa, Base &Faro);


#endif //PROJETO_ORDER_FUNCTIONS_H
