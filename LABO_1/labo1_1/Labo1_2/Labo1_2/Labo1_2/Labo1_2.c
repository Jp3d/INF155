/********************************************************
Titre: Labo 1_2e exercice
Par: Jean-Philippe Toutant
Date: 12 Septembre 2024

Contient une seule fonction main:
Additionne des entiers compris dans une intervalle donnée
dont les bornes sont saisies au clavier
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int borne_inf;
	int borne_sup;
	int somme = 0;

	while (1) {

		//entres de l'utilisateur
		printf("Definition d'une intervalle\n");
		printf("Entrez la valeur minimum \n");							//definition de borne_inf		
		if (scanf("%d", &borne_inf) != 1) {
			printf("entree invalide");
			break;
		}
		printf("\nEntrez la valeur maximum \n");						//definition de borne_sup
		if (scanf("%d", &borne_sup) != 1) {
			printf("entree invalide");
			break;
		}
		printf("\n");
		if (borne_inf > borne_sup) break;								//verifie que l'intervalle est valide

		//addition des termes en loupe utilisant les bornes comme iterateurs
		while (borne_inf <= borne_sup) {
			somme = somme + borne_inf;
			if (borne_inf < borne_sup) printf(" %d +", borne_inf);		//verifie que l'iteration nest pas finale
			else printf(" %d = %d", borne_inf, somme);					//cherche l'ite finale pour afficher resultat	
			borne_inf++;
		}
		printf("\nLa somme est: %d\n", somme);
		break;
	}
}