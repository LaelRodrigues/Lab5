/**
 * @file	primos.h
 * @brief	Implementacao das funcoes que verifica e encontra os 
 *			valores primos presentes em um conteiner
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	06/11/2017
 * @date	06/11/2017
 */


#ifndef PRIMOS_H
#define PRIMOS_H

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::find_if;

/**
 * @class 	Primos primos.h
 * @brief	Classe que verfica se um dado valor e primo
 */

class Primos
{
	public:

		/** @brief Construtor padrao */
		Primos() {}

		/** 
		 * @brief Sobrecarga do operador de parenteses 
		 * @param n Valor verificado
		 * @return True(se o valor for primo) ou false(caso contrario)
		 */
		bool operator()(int n) const {
			int cont = 0;
			for(int i = 2; i < n; i++) {
				if (n % i == 0) {
					cont++;
				}	
			}
			if(cont == 0) {
				return true;
			}
			else {
				return false;
			}
		}
};


/**
 * @brief Funcao que insere em um container valores de 
 *		  1 a N(onde N = tam) e imprime todos os valores 
 *		  primos presentes no container
 * @param tam Tamanho do container
 * @param container Conteiner que armazenar os valores
 */
template <typename TContainer>
void sequenciaPrimos(int tam, TContainer& container){

	for(int i = 1; i <= tam; i++) {
		container.push_back(i);
	}

	cout << "Numeros primos [1-" << tam << "]: ";
	auto it = container.begin();
	for(auto i = container.begin(); i != container.end(); ++i) {
		it = find_if(i, container.end(), Primos());
		if(it == i) { 
			cout << (*i) << " ";
		}
	}
	cout << endl;
}

#endif