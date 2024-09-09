/****************************************************
Titre: Exercice 3
Par: Jean-Philippe Toutant
Date: 8 Septembre 2024

Contient une seule fonction main:
Additione des entiers saisis du clavier entre 0 et 10
*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define FIN 0 
#define MIN 1
#define MAX 100
#include <stdio.h>

int main() {
	//
	int valeurEntre;
	while (1) {
		//entres de l'utilisateur
		printf("Entrez un nombre entre %d et %d. ", MIN_VALUE, MAX_VALUE);
		scanf("%d", &valeurEntre);

		//verification
		if (valeurEntre >= MIN_VALUE && valeurEntre <= MAX_VALUE) {
			printf("Approuve");
			break;
		}
		else {
			printf("Essayezencre");
			//system("pause");
		}
	}
}