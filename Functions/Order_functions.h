#ifndef PROJETO_ORDER_FUNCTIONS_H
#define PROJETO_ORDER_FUNCTIONS_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Classes/Base.h"
#include "../Functions/Verification_Inputs.h"

using namespace std;
/**
 * Funções de encomenda
 */

/**
 * @brief Função que realiza uma encomenda
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */

int create_order(Base &Porto, Base &Lisboa, Base &Faro);

/**
 * @brief Função que procura pelo restaurante dando como arguemento uma string com o nome do mesmo
 * @param base - informação da base
 * @param name - nome do restaurante a procurar
 * @return restaurante como o nome dado como argumento
 */
Restaurant searchByRestaurant(Base base, string name);




#endif //PROJETO_ORDER_FUNCTIONS_H
