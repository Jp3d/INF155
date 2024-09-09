/****************************************************
Par: Jean-Philippe Toutant
Date: 8 Septembre 2024

Contient une seule fonction main:
Demande à l'utilisateur d'entrer un nombre entier 
entre deux constantes (1 et 100). Valide l'entrée. 
*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define MIN_VALUE 1
#define MAX_VALUE 100
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