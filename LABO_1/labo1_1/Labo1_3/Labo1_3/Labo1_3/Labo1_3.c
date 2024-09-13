/****************************************************
Titre: Labo 1, 3e exercice  entre 1 et 2000 000 000
Par: Jean-Philippe Toutant
Date: 12 Septembre 2024

Contient une seule fonction main:
Decompose un nombre entre 1 et 2x10E9, utilise le modulo 
10 pour decomposition et additionne ces termes
ex: 450 => 0 + 5 + 4 = 9 
*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 2000000000
#define MIN 1
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
