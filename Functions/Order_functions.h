#ifndef PROJETO_ORDER_FUNCTIONS_H
#define PROJETO_ORDER_FUNCTIONS_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Clients_functions.h"
#include "Verification_Inputs.h"

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
 * @brief Função que procura pelo restaurante dando como argumento uma string com o nome do mesmo
 * @param base - informação da base
 * @param name - nome do restaurante a procurar
 * @param restaurant - restaurante escolhido
 * @return indice do produto escolhido
 */
int searchByRestaurant(Base base, string name, Restaurant &restaurant);

/**
 * @brief Função que procura pelo restaurante dando como argumento uma string com o concelho do mesmo
 * @param b - informação da base
 * @param base - nome da base
 * @param county - concelho do restaurante a procurar
 * @param restaurant - restaurante escolhido
 * @return indice do produto escolhido
 */
int searchByArea(Base b, string base, string county, Restaurant& restaurant);

/**
 * @brief Função que procura pelo restaurante dando como argumento um float com o valor maximo do preço do produto
 * @param base - informação da base
 * @param pmax - preço máximo do produto
 * @param restaurant - restaurante escolhido
 * @return indice do produto escolhido
 */
int searchByPrice(Base base, float pmax, Restaurant& restaurant);

/**
 * @brief Função que procura pelo restaurante dando como argumento uma string com o tipo de comida pretendido
 * @param base - informação da base
 * @param type_of_food - tipo de comida do produto
 * @param restaurant - restaurante escolhido
 * @return indice do produto escolhido
 */
int searchByTypeOfFood(Base base, string type_of_food, Restaurant& restaurant);


#endif //PROJETO_ORDER_FUNCTIONS_H
