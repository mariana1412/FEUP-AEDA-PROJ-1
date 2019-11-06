#ifndef PROJETO_VERIFICATIONS_INPUTS_H
#define PROJETO_VERIFICATIONS_INPUTS_H

#include <iostream>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;

void menu_int_options(int &option, int omax);
bool verification_int(string aux);
bool verification_nif(string aux);
bool verification_all_letters(string aux);
bool verification_date(string aux);
void verification_base(string &aux);

#endif //PROJETO_VERIFICATIONS_INPUTS_H

