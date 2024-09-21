/****************************************************
Titre: Labo 2, 3e exercice factoriel et
Par: Jean-Philippe Toutant
Date: 19 Septembre 2024

Contient une seule fonction main:
Factoriel du nombre pass
*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factoriel(int n) {
	int total = 1;
	while (n != 0) {
		total *= n;
		n--;
	}
	return total;
}

int main() {
	printf("\nfactoriel de 4: %d", factoriel(4));
	return;
}
