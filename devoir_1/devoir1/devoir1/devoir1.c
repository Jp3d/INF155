/*********************************************************
Par: Jean-Philippe Toutant
Date: 19 Septembre 2024

Contient 3 fonctions: est_bissextile(int annee)
					  nb_jours_mois(int mois, int annee)
					  valider_entier(message, min, max)
Saisi une date valide et l'affiche
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define FFLUSH()   while (getchar() != '\n') {}
#define MODE_TEST 0;

#include <stdio.h>
#include <assert.h>
int nbr_annee, nbr_mois, nbr_jour;												//variables globales
static const char* nom_mois[] = { "vide","Janvier","Fevrier","Mars",			//Array nom des mois
"Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre",
"Novembre", "Decembre" };

int est_bissextile(int annee) {
	int resultat = 0;
	if ((annee %4 == 0 && annee %100 != 0) || annee % 400 == 0) resultat++;		//valeur multiple de 4 mais pas de 100 OU tout multiples de 400 est bon
	return resultat;
}

int nb_jours_mois(int mois, int annee){
	int jours = 0;										//variable locale pour la sortie 
	if (mois == 2) {									//Detecter Fevrier pour son traitement different
		if (est_bissextile(annee)) jours = 29;
		else jours = 28;								//si annee bissextile Fevrier contient 29 jours. 	
	}
	else if(mois >= 1 && mois <= 7) {					//Dans cet ensemble les mois impairs ont 31 jours 
		if (mois % 2 != 0) jours = 31;
		else jours = 30;
	}
	else if(mois >= 8 && mois <= 12){					//Dans cet ensemble les mois impairs ont 30 jours
		if (mois % 2 != 0) jours = 30;
		else jours = 31;
	}
	return jours;
}

int valider_entier(const char* message, int borne_min, int borne_max) {
	while (1) {
		int nbr_validation;
		printf(message);
		scanf("%d", &nbr_validation);																		//scanf combine avec fflush() 
		FFLUSH();
		if (nbr_validation == 0) return 0;																	//0 pour briser la loupe d'ou la fonction a ete lancee
		else if (nbr_validation >= borne_min && nbr_validation <= borne_max) return nbr_validation;			//valeur verifiee entre les bornes
		else {
			printf("\nErreur\n");																			//message d'erreur
			printf("Entrez une valeur entre %d et %d\n", borne_min, borne_max);
		}
	}
}

int main() {
#if !defined(MODE_TEST)
	printf("test mode");


#else	
printf("\n Entrez une date en format AAAA,MM,JJ\n");														//Titre du programme
while (1) {																									//sous-Loupe 			
	int joursMax = 0;																						//variable locale pour jours du mois maximum
	//annee
	nbr_annee = valider_entier("\nAnnee (entre 1900 et 2024), 0 pour annuler: ", 1900, 2024);				//Saisie Annee 
	if (nbr_annee == 0) break;
	//mois
	if (nbr_annee == 2024) nbr_mois = valider_entier("\nMois (entre 1 et 8), 0 pour annuler: ", 1, 8);		// Limite a septembre 2024
	else nbr_mois = valider_entier("\nMois (entre 1 et 12), 0 pour annuler: ", 1, 12);						// 1900 a 2023			
	if (nbr_mois == 0) break;
	//jour
	joursMax = nb_jours_mois(nbr_mois, nbr_annee);															//obtient jours totals contenus dans le mois
	char message[50];																						//concatenation du message saisis des jours qui est variable			
	sprintf(message, "\nJour (entre 1 et %d), 0 pour annuler: ", joursMax);
	nbr_jour = valider_entier(message, 1, joursMax);
	if (nbr_jour == 0) break;
	//affichage																								La date a ete saisie par l'utilisateur
	if (nbr_jour == 1) printf("\nLe 1er ");																	//Affichage de la date en 3 segments, jour, mois, annee
	else printf("\nLe %d ", nbr_jour);
	printf(nom_mois[nbr_mois]);
	printf(" %d.", nbr_annee);
	break;																									//fin
}
#endif
return;
}