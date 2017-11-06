/**
 * @file	intervalo.h
 * @brief	implementacao da funcao que realiza operacoes para 
 *			encontrar o elemento do intervalo cujo valor é o mais  
 *			proximo da media do intervalo.
 * @author	LaelRodrigues (laelrodrigues7@gmail.com)
 * @since	05/11/2017
 * @date	05/11/2017
 */	


#ifndef INTERVALO_H
#define INTERVALO_H

#include <numeric>
using std::accumulate;


/**
 * @brief funcao que encontra o elemento do intervalo cujo
 *		  valor é o mais o proximo da media do intervalo
 * @param first iterador para o primeiro elemento do container
 * @param last iterador para uma posicao apos o ultimo elemento
 * @return iterador para o elemento mais proximo da media do intervalo
 */ 
template<typename InputIterator>
InputIterator closest2mean(InputIterator first, InputIterator last){

	int cont = 0;

	auto it = first;
	while(it != last) {
		cont++;
		it++;
	}

	auto media = accumulate(first, last, 0.0) / cont;

	it = first;
	auto elemento = it;
	auto atual = abs(*it - media);
	++it;

	while(it != last) {
		if(abs(*it - media) < atual){
			atual = abs(*it - media);
			elemento = it;
		}
		it++;		
	}

	return elemento;
}

#endif