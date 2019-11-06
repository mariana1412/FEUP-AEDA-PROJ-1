#ifndef PROJETO_UTILS_H
#define PROJETO_UTILS_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string cleaning_invalid_characters(string line); // retirar acentos e cedilhas
void trim(string &str); // retirar ' ' do inicio e do fim da string
void formatting_string(string &str); //formatar a string para que todas as letras sejam minusculas menos a primeira letra de cada palavra
void remove_all_whitespaces(string &aux);
string remove_extra_whitespaces(string aux);


#endif //PROJETO_UTILS_H
