#ifndef PROJETO_RESTAURANTS_FUNCTIONS_H
#define PROJETO_RESTAURANTS_FUNCTIONS_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Exceptions.h"
#include "../Classes/Restaurant.h"
#include "../Classes/Base.h"
#include "utils.h"
#include "Verification_Inputs.h"


int create_restaurant(Base &Porto, Base &Lisboa, Base &Faro);
int modify_restaurant(Base &Porto, Base &Lisboa, Base &Faro);
int remove_restaurant(Base &Porto, Base &Lisboa, Base &Faro);


#endif //PROJETO_RESTAURANTS_FUNCTIONS_H
