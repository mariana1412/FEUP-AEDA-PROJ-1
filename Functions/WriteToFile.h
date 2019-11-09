#ifndef PROJETO_WRITETOFILE_H
#define PROJETO_WRITETOFILE_H

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "../Classes/Person.h"
#include "../Classes/Restaurant.h"
#include "../Classes/Base.h"
#include "../Classes/Order.h"
#include "../Classes/Location.h"
#include "../Classes/Time.h"

class Time;
class Location;
class Employee;
class Restaurant;
class Delivery;
class Base;

void write_Clients(Base& baseP, Base& baseL, Base& baseF);
void write_Restaurants(Base& baseP, Base& baseL, Base& baseF);
void write_Deliveries(Base& baseP, Base& baseL, Base& baseF);
void write_Employees(Base& baseP, Base& baseL, Base& baseF);
void write_Bases(Base& baseP, Base& baseL, Base& baseF);



#endif //PROJETO_WRITETOFILE_H
