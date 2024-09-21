/****************************************************
Titre: example en classe 2
Par: Jean-Philippe Toutant
Date: 16 Septembre 2024

Contient une seule fonction main:

*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//
	int valeurChoisie, somme = 0, chiffre;

	while (1) {

		//entres de l'utilisateur
		printf("Entrez un nombre entre %d et %d. ", MIN, MAX);		//choix du nombre a decomposer
		if (scanf("%d", &valeurChoisie) != 1) {
			printf("entree invalide");
			break;
		}

		//verification que la valeur appartient a l'intervalle
		if (valeurChoisie < MIN || valeurChoisie > MAX) break;

		while (valeurChoisie > 0) {
			chiffre = valeurChoisie % 10;							//methode de decomposition des termes modulo 10 
			somme = somme + chiffre;
			if (valeurChoisie > 10) printf(" %d +", chiffre);       //affiche un des termes de l'addition
			else printf(" %d = %d", chiffre, somme);				//affiche le dernier chiffre et le resultat				
			valeurChoisie /= 10;									//divise le ter
		}
		//printf("%d", somme);
		break;
	}
}
