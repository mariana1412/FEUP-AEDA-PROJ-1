#ifndef PROJETO_VERIFICATIONS_INPUTS_H
#define PROJETO_VERIFICATIONS_INPUTS_H

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;

void menu_int_options(int &option, int omin, int omax);
void verification_int(string &aux);
void verification_nif(string &aux);
void verification_all_letters(string &aux);
void verification_date(string &aux);
void verification_base(string &aux);
void verification_float(string &aux);

#endif //PROJETO_VERIFICATIONS_INPUTS_H

