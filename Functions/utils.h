#ifndef PROJETO_UTILS_H
#define PROJETO_UTILS_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../Classes/Person.h"
#include "../Classes/Base.h"
#include "../Classes/Product.h"
#include "../Classes/Order.h"
class Product;


using namespace std;

bool isNumber(string n);
bool isAlgarism(char n);
bool isLetter(char a);
void trim(string &str); // retirar ' ' do inicio e do fim da string
void formatting_string(string &str); //formatar a string para que todas as letras sejam minusculas menos a primeira letra de cada palavra
void remove_all_whitespaces(string &aux);
string remove_extra_whitespaces(string aux);
int int_sequential_search(const vector<Client> &v, int x);
int string_sequential_search(const vector<Client> &v, string x);
bool confirm_modifications(string action, string person);
vector<Client> stringToClientVectorSearch(string str, const Base &b);
Restaurant stringToRestaurantSearch(string str, const Base &b);
vector<Delivery> stringToDeliveryVectorSearch(string str, const Base& b);
vector<Product> stringToProductVectorSearch(string str, const Base& b);
vector<string> stringToStringVector(string str);

#endif //PROJETO_UTILS_H
