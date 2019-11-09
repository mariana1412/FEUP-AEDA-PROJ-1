#ifndef PROJETO_UTILS_H
#define PROJETO_UTILS_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../Functions/Exceptions.h"

using namespace std;

bool isNumber(string n);
bool isAlgarism(char n);
bool isLetter(char a);
void trim(string &str); // retirar ' ' do inicio e do fim da string
void formatting_string(string &str); //formatar a string para que todas as letras sejam minusculas menos a primeira letra de cada palavra
void remove_all_whitespaces(string &aux);
string remove_extra_whitespaces(string aux);
bool confirm_modifications(string action, string str);


#endif //PROJETO_UTILS_H
