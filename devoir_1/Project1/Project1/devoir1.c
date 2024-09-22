/****************************************************
Par: Jean-Philippe Toutant
Date: 19 Septembre 2024

Contient une seule fonction main:
calcule le montant d'un salaire en fonction d'un taux
horaire, et la saisie du nombre d'heures travaillées.
*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int nbr_annee, nbr_mois, nbr_jour;

int validation_entre_Min_Max(int num, int min, int max) {
	int result = 0;
	if (num >= min || num <= max) {
		result += 1;
	}
	return result;
}

int validation_du_mois() {

}

void entree_Utilisateur_date() {
	//entres de l'utilisateur avec verification immediate et loop sur erreur, 0 pour annuller l'entree
	int error = 1;
	while (1) {
		printf("\n Entrez une date en format AAAA,MM,JJ\n");
		while (!error) {
			printf("Annee (entre 1900 et 2024), 0 pour annuler: ");
			error = scanf("%d", &nbr_annee);
			if (nbr_annee == 0) {
				break;
			}
			else {
				
			}
		}
		//if (!validation_entre_Min_Max(nbr_annee, 1900, 2024)) break;        //min max 1900 et 2024
		//printf("\n mois: ?");
		//scanf("%d", &nbr_mois);
		//printf("\n jour: ?");
		//scanf("%d", &nbr_annee);
	}
}

int main() {
	entree_Utilisateur_date();
	return 0;
}