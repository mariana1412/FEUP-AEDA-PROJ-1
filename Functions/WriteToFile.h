#ifndef PROJETO_WRITETOFILE_H
#define PROJETO_WRITETOFILE_H

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "../Classes/Base.h"
/**
 * Funções de escrita/atualização dos ficheiros
 */


/**
 * @brief Função que escreve a informação do ficheiro de clientes
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */

void write_Clients(Base& baseP, Base& baseL, Base& baseF);
/**
 * @brief Função que escreve a informação do ficheiro de restaurantes
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void write_Restaurants(Base& baseP, Base& baseL, Base& baseF);
/**
 * @brief Função que escreve a informação do ficheiro de entregas
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void write_Deliveries(Base& baseP, Base& baseL, Base& baseF);
/**
 * @brief Função que escreve a informação do ficheiro de funcionários
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void write_Employees(Base& baseP, Base& baseL, Base& baseF);
/**
 * @brief Função que escreve a informação do ficheiro de bases
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void write_Bases(Base& baseP, Base& baseL, Base& baseF);


#endif //PROJETO_WRITETOFILE_H
