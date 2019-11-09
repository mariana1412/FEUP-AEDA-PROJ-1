#ifndef PROJETO_STRINGCONVERTERS_H
#define PROJETO_STRINGCONVERTERS_H

#pragma once

#include <string>
#include <vector>
#include "../Classes/Base.h"


vector<string> stringToStringVector(string str);
vector<Product> stringToProductVector(string str);
Time stringToDate(string str);
Vehicle stringToVehicle(string str);
Time stringToTime(string str);
Time stringToHour(string str);
Location stringToLocation(string str);
vector<Client> stringToClientVectorSearch(string str, const Base& b);
vector<Delivery> stringToDeliveryVectorSearch(string str, const Base& b);
vector<Product> stringToProductVectorSearch(string str, const Restaurant& r);

#endif //PROJETO_STRINGCONVERTERS_H
