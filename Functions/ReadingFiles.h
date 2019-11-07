#ifndef PROJETO_READINGFILES_H
#define PROJETO_READINGFILES_H

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../Classes/Person.h"
#include "../Classes/Restaurant.h"
#include "../Classes/Base.h"
#include "../Classes/Order.h"
#include "../Classes/Location.h"
#include "../Classes/Time.h"
#include "StringConverters.h"

void extract_Clients(Base& baseP, Base& baseL, Base& baseF);
void extract_Restaurants(Base& baseP, Base& baseL, Base& baseF);
void extract_Deliveries(Base& baseP, Base& baseL, Base& baseF);
void extract_Employees(Base& baseP, Base& baseL, Base& baseF);
void extract_Bases(Base& baseP, Base& baseL, Base& baseF);


#endif //PROJETO_READINGFILES_H
