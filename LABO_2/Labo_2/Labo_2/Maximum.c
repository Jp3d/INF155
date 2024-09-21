/****************************************************
Titre: Labo 2, exercice 2 fonction MAX
Par: Jean-Philippe Toutant
Date: 19 Septembre 2024

Contient une seule fonction main:
*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

/* Fonction qui retourne le plus grand des 2 entiers reçus en paramètres. */
int max_des_deux(int entier1, int entier2) {
	if (entier1 >= entier2) {					//trouve le plus grand des deux entiers
		return entier1;
	}
	else
		return entier2;
}

// Fonction qui retourne le plus grand des 3 entiers reçus en paramètres.
int max_des_trois(int entier1, int entier2, int entier3) {
	return max_des_deux(entier3, max_des_deux(entier2, entier1));			  //combinant max_de2 2x
}

// Fonction qui retourne le plus grand des 4 entiers reçus en paramètres.
int max_des_quatres(int entier1, int entier2, int entier3, int entier4) {
	return max_des_deux(entier4, max_des_trois(entier1, entier2, entier3));   //combinant max_de3 et 2
}


int main() {

	printf("\n max des deux: %d", max_des_deux(12, 15));
	printf("\n max des trois %d", max_des_trois(100, 12, 15));
	printf("\n max des quatres: %d", max_des_quatres(199, 123, 124, 123));
	printf("\n");

	printf("\n assert max de deux 1 et 10 est 10: %d", assert(max_des_deux(1, 10) == 10));
	printf("\n assert max de quatre 1,2,3,4 est 4: %d", assert(max_des_quatres(1, 2, 3, 4) == 4));
	return;
}
