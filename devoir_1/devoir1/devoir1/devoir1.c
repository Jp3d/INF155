/*********************************************************
Par: Jean-Philippe Toutant
Date: 19 Septembre 2024

Contient une fonction main(): 
Saisi une date, la valide en etape anne, mois, et jours
et l'affiche.

*********************************************************/

//Permet d'effectuer des scanf.
#define _CRT_SECURE_NO_WARNINGS
//Macro FFLUSH() pour libérer le tampon de saisie. 
#define FFLUSH()   while (getchar() != '\n') {}
//1 pour activer test unitaires; 0 pour le fonctionnement normal.
#define MODE_TEST 0;															
//L'annee 2024 est l'annee maximale.
#define ANNEE_MAX 2024;
//L'annee 1900 est l'annee minimale.
#define ANNEE_MIN 1900;
//Il y a douze mois dans une annee
#define MOIS_MAX 12;

#include <stdio.h>
#include <assert.h>

//Section des variables globales.
int nbr_annee, nbr_mois, nbr_jour;												
static const char* nom_mois[] = { "Janvier","Fevrier","Mars",					//Liste nom des mois  *devra etre changé pour une Enum en partie 2. 
"Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre",
"Novembre", "Decembre" };

/*--------------------------------------------------------------------------------------
	EST_BISSEXTILE

	DESCRIPTION: Cette fonction prend une année est teste les conditions 
	qui en font une année bissextile ou pas.

	PARAMÈTRES: 
		-annee (Type INT): Année pour vérification 

	VALEUR DE RETOUR: (INT) 1 pour oui; 0 pour non

	EXEMPLE D'APPEL: -est_bissextile(2024) retourne 1 
--------------------------------------------------------------------------------------*/

int est_bissextile(int annee) {
	int resultat = 0;
	//(valeur multiple de 4 mais pas de 100) OU (tout multiples de 400 est bon)
	if ((annee %4 == 0 && annee %100 != 0) || annee % 400 == 0) resultat++;		
	return resultat;
}

/*--------------------------------------------------------------------------------------  
	NB_JOURS_MOIS

	DESCRIPTION: Cette fonction retrouve le nombre de jours dans un mois. Selon une année
	et un mois donné. 

	PARAMÈTRES: -mois (INT)
				-annee (INT)

	VALEUR DE RETOUR: (INT) le nombre de jours

	EXEMPLE D'APPEL:
					-nb_jours_mois(1,2024) retourne 31
					-nb_jours_mois(2,2024) retourne 29
---------------------------------------------------------------------------------------*/

int nb_jours_mois(int mois, int annee){
	int jours = 0;										//Variable locale pour stocker le resultat retourné en sortie. 
	if (mois == 2) {									//Détecter Février pour son traitement special.
		if (est_bissextile(annee)) jours = 29;
		else jours = 28;								//Si l'annee est bissextile, Fevrier contient 29 jours. Autrement, il en a 28. 	
	}
	else if(mois >= 1 && mois <= 7) {					//Dans cet ensemble, les mois impairs ont 31 jours. (Janvier à Juillet)
		if (mois % 2 != 0) jours = 31;
		else jours = 30;								//Si le mois en pair il en a 30.
	}
	else{												//Dans cet ensemble, les mois impairs ont 30 jours. (Aout à Décembre)
		if (mois % 2 != 0) jours = 30;
		else jours = 31;								//Si le mois en pair il en a 31.
	}
	return jours;										//Retourne la variable locale avec la valeur obtenue.
}

/*-----------------------------------------------------------------------------------------
	VALIDER_ENTIER

	DESCRIPTION: Cette fonction obtient l'entré utilisateur d'un INT valide. Elle 
	saisit avec scanf, ensuite test si cette entrée existe entre des bornes min et max. Si
	l'utilisateur inscrit une donnée invalide, on lui affiche un message d'erreur et loupe 
	pour qu'il essaie de nouveau. Si il incrit 0, ceci annule l'entré d'une date et quitte
	le programme. 

	PARAMÈTRES: -message (const char*): Affiche à l'utilisateur ce qui est attendu. 
										ex:"entrez un mois de 1 à 12"
				-borne_min (INT): Valeur pour validation plus grand ou egale à un minimum.

				-borne_max (INT): Valeur pour validation plus petit ou egale à un maximum.
			
	VALEUR DE RETOUR: (INT) entier validé, ou (INT) 0 pour annulation
------------------------------------------------------------------------------------------*/

int valider_entier(const char* message, int borne_min, int borne_max) {
	while (1) {
		int nbr_validation;																				//Stockage de la saisie utilisateur.
		printf(message);
		scanf("%d", &nbr_validation);																	//Utilise scanf en combinaison avec fflush() pour éviter bug de saisie. 
		FFLUSH();
		if (nbr_validation == 0) return 0;																//Zéro pour briser la loupe d'ou la fonction a ete lancee et quitter le programme.
		else if (nbr_validation >= borne_min && nbr_validation <= borne_max) return nbr_validation;		//Valeur verifiee entre les bornes.
		else {
			printf("\nErreur\n");																		//Ceci est un message d'erreur.
			printf("Entrez une valeur entre %d et %d\n", borne_min, borne_max);							//Il indique les bornes à nouveau en guise de rappel.	
		}
	}
}

/*--------------------------------------------------------------------------------------
	EST_BISSEXTILE

	DESCRIPTION: Cette fonction prend une année est teste les conditions
	qui en font une année bissextile ou pas.

	PARAMÈTRES:
		-annee (Type INT): Année pour vérification

	VALEUR DE RETOUR: (INT) 1 pour oui; 0 pour non

	EXEMPLE D'APPEL: -est_bissextile(2024) retourne 1
--------------------------------------------------------------------------------------*/

int jours_bissextile(int annee) {
	int resultat = 0;
	if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0) resultat++;		//(valeur multiple de 4 mais pas de 100) OU (tout multiples de 400 est bon)
	return resultat;
}

#if MODE_TEST													//Ceci est la condition d'activation des tests unitaires. 			
	printf("test unitaires:");									//Ceci est la zone des tests unitaires.
	assert(est_bissextile(1912) == 1);
	assert(est_bissextile(1911) == 0);
	
	assert(nb_jours_mois(8, ANNEE_MAX) == 31);
	assert(nb_jours_mois(2, ANNEE_MAX) == 29);
	printf(" terminés avec succès");

#else															//Si les tests unitaires sont inactifs, le programme se déroule à partir d'ici.		
printf("\n Entrez une date en format AAAA,MM,JJ\n");			//Titre 
while (1) {														//Structure de controle while, interromp avec des instructions break.  			
	int joursMax = 0;											//Variable locale pour stocker jours du mois maximum pour concatenation message.(dans section jours)
	
	//Section saisie de l'annee.
	nbr_annee = valider_entier("\nAnnee (entre 1900 et 2024), 0 pour annuler: ", 
		                        ANNEE_MIN, ANNEE_MAX);				 
	if (nbr_annee == 0) break;
	
	//Section saisie du mois.

	if (nbr_annee == ANNEE_MAX) nbr_mois = valider_entier("\nMois (entre 1 et 8), 0 pour annuler: ", 1, 8);			// Detecte l'an 2024 pour limiter les mois à 8.
	else nbr_mois = valider_entier("\nMois (entre 1 et 12), 0 pour annuler: ", 1, MOIS_MAX);						// Tout autres années entre 1900 et 2023.			
	if (nbr_mois == 0) break;
	
	//Section saisie du jour.
	joursMax = nb_jours_mois(nbr_mois, nbr_annee);								//Obtient jours totals contenus dans le mois selon l'année.
	char message[50];															//Concatenation du message pour les jours valides.			
	sprintf(message, "\nJour (entre 1 et %d), 0 pour annuler: ", joursMax);		//Le message doit etre completé d'avance pour etre passé en parametre ici.
	nbr_jour = valider_entier(message, 1, joursMax);
	if (nbr_jour == 0) break;
	
	//Section affichage de la date saisie.				La date a ete saisie par l'utilisateur.
	if (nbr_jour == 1) printf("\nLe 1er ");				//Affichage de la date en 3 segments, jour, mois et annee.
	else printf("\nLe %d ", nbr_jour);
	printf(nom_mois[nbr_mois - 1]);
	printf(" %d.", nbr_annee);
	break;												//La fin du programme.
}
#endif
return;																										//Ce retour cloture la fonction main.
}