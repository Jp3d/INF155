/****************************************************
Titre: Labo 1.4 Pi 
Par: Jean-Philippe Toutant
Date: 12 Septembre 2024

Contient une seule fonction main:
Evalue Pi en utilisant un nombre N d<iteration du produit
de Wallis
*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define ITER 12000000 
#include <stdio.h>

int main() {
	//
	double pi = 1.0;
	double twoPi;
	int n = 1;

	while (n != ITER) {
		double numerator = (2.0 * n) * (2.0 * n);
		double denominator = (2.0 * n - 1) * (2.0 * n + 1);
		pi *= (numerator / denominator);
		twoPi = pi * 2;
		printf("\n%d iterations, Pi value: %.15f", n, twoPi);
		n++;
	}
	return 0;
}