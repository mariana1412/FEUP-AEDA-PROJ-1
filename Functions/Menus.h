#ifndef PROJETO_MENUS_H
#define PROJETO_MENUS_H

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Verification_Inputs.h"
using namespace std;


/**
 * Funções dos Menus
 */


/**
 * @brief Menu principal do programa
 * @return valor inteiro para retorno do Menu
 * **/
int MainMenu();
/**
 * @brief Menu de gerir clientes
 * @return valor inteiro para retorno do Menu
 * **/
int ClientsManagement();
/**
 * @brief Menu de gerir funcionários
 * @return valor inteiro para retorno do Menu
 * **/
int EmployeesManagement();
/**
 * @brief Menu de gerir restaurantes
 * @return valor inteiro para retorno do Menu
 * **/
int RestaurantsManagement();
/**
 * @brief Menu de realizar uma encomenda
 * @return valor inteiro para retorno do Menu
 * **/
int Order();
/**
 * @brief Menu de procura por um certo critério
 * @return valor inteiro para retorno do Menu
 * **/
int SearchBy();
/**
 * @brief Menu de cálculo de lucro
 * @return valor inteiro para retorno do Menu
 * **/
int ProfitsCalculation();
/**
 * @brief Menu de Visualização de informação
 * @return valor inteiro para retorno do Menu
 */

int VisualizeInformation();

#endif //PROJETO_MENUS_H
