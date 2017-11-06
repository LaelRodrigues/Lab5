/**
 * @file	main.cpp
 * @brief	Codigo fonte de teste da funcaos realizam 
 *			operacoes referente a valores primos contidos
 *			em um container
 * @author	LaelRodrigues (laelRodrigues7@gmail.com)
 * @since	06/11/2017
 * @date	06/11/2017
 */

#include <list>
using std::list;

#include "primos.h"

#include <iostream>
using std::cout;

#include <string>
using std::stoi;

/** @brief Funcao principal */
int main(int argc, char* argv[]) {

	if (argc < 2){
		cout << "Erro: nao foram digitados os paramentros necessarios." << endl;
		return EXIT_FAILURE;
	}

	int valor = stoi(argv[1]);
	list<int> vetor;
	sequenciaPrimos(valor, vetor);
	return EXIT_SUCCESS;

   
	return 0;
} 	