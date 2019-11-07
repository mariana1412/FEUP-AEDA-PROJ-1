#ifndef PROJETO_STRINGCONVERTERS_H
#define PROJETO_STRINGCONVERTERS_H

#pragma once

#include <string>
#include <vector>
#include "../Classes/Location.h"
#include "../Classes/Person.h"
#include "../Classes/Base.h"
#include "utils.h"


vector<Client> stringToClientVectorSearch(string str, const Base& b);
vector<string> stringToStringVector(string str);
vector<Product> stringToProductVector(string str);
Time stringToDate(string str);
Vehicle stringToVehicle(string str);
vector<Delivery> stringToDeliveryVectorSearch(string str, const Base& b);
Restaurant stringToRestaurantSearch(string str, const Base& b);
Time stringToTime(string str);
vector<Product> stringToProductVectorSearch(string str, const Base& b);
Time stringToHour(string str);

#endif //PROJETO_STRINGCONVERTERS_H
