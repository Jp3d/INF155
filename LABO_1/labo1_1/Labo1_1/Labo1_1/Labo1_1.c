/****************************************************
Titre: Labo1_1 BMI 
Par: Jean-Philippe Toutant
Date: 11 Septembre 2024

Calcule de l'indice de masse corporelle et affiche le 
resultat.
*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define maigreur 20
#define normal 25
#define ponderal 30
#define obesite 40
#include <stdio.h>

int main() {
	//
	float _poid;
	float _taille;
	float _bmi =0;
	while (1) {

		printf("\nCalculateur de BMI\n");
												//entres de l'utilisateur pour poid et taille
		printf("Entrez le poid (Kg).");
		if (scanf("%f", &_poid) != 1) {
			printf("entree invalide");
			break;
		}
		printf("\nEntrez la taille (m metres).\n");
		if (scanf("%f", &_taille) != 1) {
			printf("entree invalide");
			break;
		}

		//calcule le BMI
		_bmi = (_poid / (_taille * _taille));
		
		//verification sur l'echelle
		//if (valeurEntre >= MIN && valeurEntre <= MAX) {
		if (_bmi <= maigreur && _bmi >0) {
			printf("Indice: %f => Maigreur", _bmi);					//maigreur
		}
		if (_bmi <= normal && _bmi >maigreur) {
			printf("Indice: %f => Normal", _bmi);					//normal
		}
		if (_bmi <= ponderal && _bmi > normal) {
			printf("Indice: %f => surcharge ponderale", _bmi);		//surcharge ponderale
		}
		if (_bmi <= obesite && _bmi > ponderal) {					
			printf("Indice: %f => obesite", _bmi);					//obesite
		}
		if (_bmi > obesite) {
			printf("Indice: %f => obesite severe", _bmi);			//obesite severe
		}
	break;
	}
}