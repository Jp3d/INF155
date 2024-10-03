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
#define MODE_TEST 0														
//L'annee 2024 est l'annee maximale.
#define ANNEE_MAX 2024
//L'annee 1900 est l'annee minimale.
#define ANNEE_MIN 1900
//Douze mois dans une annee
#define DOUZE_MOIS 12
//Mois limite pour l'annee max, par defaut 8 
#define MOIS_MAX 8
//Anne de Reference pour calcul des jours de semaine
#define ANNEE_REFERENCE 2024
//Mois de Reference pour calcul des jours de semaine
#define MOIS_REFERENCE 9
//Jour de Reference pour calcul des jours de semaine
#define JOUR_REFERENCE 1


#include <stdio.h>
#include <assert.h>

//Section des variables globales.
//Une variable pour année, mois et jours, stocke une saisie vérifiée valide. 
int nb_annee, nb_mois, nb_jour;
//Enumération stocke de 0 à 6 les jours de la semaine.
enum jours_semaine{DIMANCHE, LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI};
static const char* nom_mois[] = {"Janvier","Fevrier","Mars",			//Liste nom des mois 
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
	int jours = 0;									//Variable locale pour stocker le resultat retourné en sortie. 
	if (mois == 2) {								//Détecter Février pour son traitement special.
		if (est_bissextile(annee)) jours = 29;
		else jours = 28;							//Si l'annee est bissextile, Fevrier contient 29 jours. Autrement 28. 	
	}
	else if(mois >= 1 && mois <= 7) {				//Dans cet ensemble, les mois impairs ont 31 jours.Jan à Jul
		if (mois % 2 != 0) jours = 31;
		else jours = 30;							//Si le mois en pair il en a 30.
	}
	else{											//Dans cet ensemble, les mois impairs ont 30 jours. (Aout à Décembre)
		if (mois % 2 != 0) jours = 30;
		else jours = 31;							//Si le mois en pair il en a 31.
	}
	return jours;									//Retourne la variable locale avec la valeur obtenue.
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
		//Stockage de la saisie utilisateur.
		int nbr_validation;																				
		printf(message);
		//Utilise scanf en combinaison avec fflush() pour éviter bug de saisie.
		scanf("%d", &nbr_validation);																	 
		FFLUSH();
		//Zéro pour briser la loupe d'ou la fonction a ete lancee et quitter le programme.
		if (nbr_validation == 0) return 0;
		//Valeur verifiee entre les bornes.
		else if (nbr_validation >= borne_min && nbr_validation <= borne_max) return nbr_validation;		
		else {
			//Le message d'erreur.
			printf("\nErreur\n");
			//Il indique les bornes à nouveau en guise de rappel.
			printf("Entrez une valeur entre %d et %d\n", borne_min, borne_max);								
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
	//(valeur multiple de 4 mais pas de 100) OU (tout multiples de 400 est bon)
	if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0) resultat++;		
	return resultat;
}

/*--------------------------------------------------------------------------------------
	NB_JOURS_DIFF

	DESCRIPTION: Cette fonction calcule le nombre de jours entre une date arbitraire 
				et une date reference.

	PARAMÈTRES:
		-annee (Type INT): Année pour comparaison avec la date reference
		-mois (Type INT): Mois "
		-jour (Type INT): Jour " 

	VALEUR DE RETOUR: (INT) nombre de jours

	EXEMPLE D'APPEL: -nb_jours_diff(2022, 9, 1) retourne 731
--------------------------------------------------------------------------------------*/

int nb_jours_diff(int annee, int mois, int jour) {
	int diff_jours = 0;
	int annee_0 = ANNEE_REFERENCE;
	int mois_0 = MOIS_REFERENCE;
	int jour_0 = JOUR_REFERENCE;

	while (annee_0 > annee) {
		if ((annee_0 > (annee + 1)) || mois < 9) {
			if (est_bissextile(annee_0)) diff_jours += 366;
			else diff_jours += 365;
	}
	annee_0--;
	}
	if (mois >= 9) annee_0++;
	do {
		mois_0--;
		if (mois_0 < 1) {
			mois_0 = 12;
			annee_0--;
		} //Le mois est decremente
		if (mois_0 != mois) {
			diff_jours += nb_jours_mois(mois_0, annee_0);
		}
	}
	while (mois_0 != mois);
	// les mois sont compt
	diff_jours += ((nb_jours_mois(mois, annee) - jour) + 1);
	return diff_jours;
}

int quel_jour(int nb_jours) {
	return(nb_jours % 7);
}

//Condition d'activation des tests unitaires.
#if MODE_TEST
int main() {
	printf("test unitaires:");		//Zone des tests unitaires.
	assert(est_bissextile(1912) == 1);
	assert(est_bissextile(1911) == 0);

	assert(nb_jours_mois(8, ANNEE_MAX) == 31);
	assert(nb_jours_mois(2, ANNEE_MAX) == 29);

	assert(nb_jours_diff(2024, 8, 1) == 31);
	assert(nb_jours_diff(2023, 9, 1) == 366);
	assert(nb_jours_diff(2022, 9, 1) == 731);
	assert(nb_jours_diff(2000, 1, 1) == 9010);
	assert(nb_jours_diff(1900, 1, 1) == 45534);

	printf(" terminés avec succès");
	}

#else
int main(){		//Si les tests unitaires sont inactifs, cette fonction main est active.	

	printf("\n Entrez une date en format AAAA MM JJ\n");			//Titre 

	while(1) {						//Structure de controle while, interromp avec des instructions break.  			
		int joursMax = 0;			//Variable locale pour stocker jours du mois maximum pour concatenation message.
		char message[50];		    //Variable de concatenation des messages.
	
		//Section saisie de l'annee.
		sprintf(message, "\nAnnee (entre %d et %d), 0 pour annuler: ", ANNEE_MIN, ANNEE_MAX);	//Le message doit est concatene d'avance
		nb_annee = valider_entier(message, ANNEE_MIN, ANNEE_MAX);				 
		if (nb_annee == 0) break;
	
		//Section saisie du mois.
		if (nb_annee == ANNEE_MAX) nb_mois = valider_entier("\nMois (entre 1 et 8), 0 pour annuler: ", 1, 8);		//Detecte l'an 2024 pour limiter les mois à 8.
		else nb_mois = valider_entier("\nMois (entre 1 et 12), 0 pour annuler: ", 1, DOUZE_MOIS);					//Tout autres années entre 1900 et 2023.			
		if (nb_mois == 0) break;
	
		//Section saisie du jour.
		joursMax = nb_jours_mois(nb_mois, nb_annee);								//Obtient jours totals contenus dans le mois selon l'année.		
		sprintf(message, "\nJour (entre 1 et %d), 0 pour annuler: ", joursMax);		//Le message doit etre completé d'avance pour etre passé en parametre ici.
		nb_jour = valider_entier(message, 1, joursMax);
		if (nb_jour == 0) break;
	
		//Section affichage de la date saisie.		La date a ete saisie par l'utilisateur.
		if (nb_jour == 1) printf("\nLe 1er ");		//Affichage de la date en 3 segments, jour, mois et annee.
		else printf("\nLe %d ", nb_jour);
		printf(nom_mois[nb_mois - 1]);				//Repere le mois dans le tableau à partir de 0. 
		printf(" %d.", nb_annee);
		joursMax = nb_jours_diff(nb_annee, nb_mois, nb_jour);
		printf("\n diff: %d ", joursMax);

	break;		//La fin du programme.
	}

	return;		//Ce retour cloture la fonction main.
}
#endif