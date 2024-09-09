/****************************************************
Par: Jean-Philippe Toutant
Date: 6 Septembre 2024

Contient une seule fonction main:
calcule le montant d'un salaire en fonction d'un taux
horaire, et la saisie du nombre d'heures travaillées.
*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//
	int nbr_heures;
	float taux_horaire,
		salaire;

	//entres de l'utilisateur
	printf("Nombre d'heures travaillées? ");
	scanf("%d", &nbr_heures);

	printf("Taux horaire? ");
	scanf("%f", &taux_horaire);

	//calcul 
	salaire = nbr_heures * taux_horaire;
	
	//affichage du resultat
	printf("\n%d heures * %.2f $/h = %.2f $ de salaire. \n", nbr_heures, taux_horaire, salaire);
	system("pause");

	return 0; 
}