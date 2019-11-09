#ifndef PROJETO_STRINGCONVERTERS_H
#define PROJETO_STRINGCONVERTERS_H

#pragma once

#include <string>
#include <vector>
#include "../Classes/Location.h"
#include "../Classes/Person.h"
#include "../Classes/Base.h"
#include "utils.h"


vector<string> stringToStringVector(string str);
vector<Product> stringToProductVector(string str);
Time stringToDate(string str);
Vehicle stringToVehicle(string str);
Time stringToTime(string str);
Time stringToHour(string str);
Location stringToLocation(string str);

#endif //PROJETO_STRINGCONVERTERS_H
