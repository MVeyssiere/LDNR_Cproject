#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "ProjetC_EquipeMarine_fichiers_fonctions.h"

char Menu_Jeremie()
{
	char saisieMenu;

	printf("---------- MENU ---------");
	printf("\n A: Inscrire un élève");
	printf("\n B: Rechercher un élève");
	printf("\n C: Afficher les informations d'un élève");
	printf("\n D: Modifier les informations d'un élève");
	printf("\n E: Afficher une classe");
	printf("\n F: Afficher l'école");
	printf("\n S: Sauvegarde des informations des élèves");
	printf("\n Q: Quitter le programme\n\n");

	printf("Saisissez une fonction: ");
	scanf(" %c",&saisieMenu);
	saisieMenu=toupper(saisieMenu);

	return saisieMenu;
}

// pour calculer l'âge à partir de la date de naissance fournie par l'utilisateur
int anniversaire(date aujourdhui,date naissance)
{
	int tmp;
	tmp = (aujourdhui.annee)-(naissance.annee);
    if(((naissance.mois)*31 + (naissance.jour)) > ((aujourdhui.mois)*31 + (aujourdhui.jour))){
	    tmp=tmp-1;
    }
	//printf("%d, %d, %d, %d, %d, %d", a.annee, n.annee,a.mois,n.mois,a.jour,n.jour);
	return tmp;      
}

int Affichage(int jour_naissance, int mois_naissance, int annee_naissance, date aujourdhui, date naissance)
{
    printf("Entrez date de naissance de l'élève (JJ MM AAAA): \n");
    scanf ("%d %d %d", &(jour_naissance), &(mois_naissance), &(annee_naissance));
    naissance.jour=jour_naissance;
    naissance.mois=mois_naissance;
    naissance.annee=annee_naissance;
    //printf("L'élève a %d ans \n",anniversaire(aujourdhui,naissance));
    return anniversaire(aujourdhui,naissance);
}

void inscription_cedric_et_zine(struct classes *Classes,date *aujourdhui,date *naissance, int *ptr_compteurCP, int *ptr_compteurCE1, int *ptr_compteurCE2, int *ptr_compteurCM1, int *ptr_compteurCM2)
{
	char saisie_nom[20];
	char saisie_prenom[20];
	struct ecole ecole;
	char saisiefonction='\0';
	int compteurtotal=0;
	int condition=0;

	printf("INSCRIPTION ÉLÈVE:\n");

	while (saisiefonction!='Q' && saisiefonction!='q')
	{			
		condition=1;
		if (saisiefonction!='Q')
		{

			printf("Nom de l'élève à inscrire: ");
			scanf("%s",saisie_nom);
			
			for (int low=0; low<strlen(saisie_nom); low++){
				saisie_nom[low]=tolower(saisie_nom[low]);
			}

			printf("Prénom de l'élève à inscrire: ");
			scanf("%s",saisie_prenom);
			
			for (int low=0; low<strlen(saisie_prenom); low++){
				saisie_prenom[low]=tolower(saisie_prenom[low]);
			}
			compteurtotal=compteurtotal+1; // s'incrémente quand un nouvel élève est inscrit dans l'école	

			if(compteurtotal>0)
			{
				for (int j = 0; j <=5 ; ++j)
				{						
					for (int i = 0; i <= 24; ++i)
					{						
						if(strcmp(Classes[j].Eleves[i].nom,saisie_nom)==0) // vérifie que le nom entré est bien présent parmi les élèves
						{
							if(strcmp(Classes[j].Eleves[i].prenom,saisie_prenom)==0) // vérifie que le prénom associé au nom correspond à un élève de l'école
							{
								printf("Cet élève existe déja, recommencez la saisie.\n"); // si c'est le cas, on n'inscrit pas cet élève puisqu'il est déjà inscrit.
								condition=0;
							}
						}
					}	
				}
			}

			// calcul de l'âge à partir de la date de naissance
			if (condition!=0)
			{
				int agecalcule=Affichage(naissance->jour,naissance->mois,naissance->annee, *aujourdhui, *naissance);
				printf("Âge calculé: %d ans.\n", agecalcule);
				if (agecalcule<6){
					printf("L'élève est trop jeune pour intégrer l'école\n");
				}	
				if (agecalcule==6){
					printf("L'élève est désormais inscrit en CP.\n");
				}
				if (agecalcule==7){
					printf("L'élève est désormais inscrit en CE1.\n");
				}
				if (agecalcule==8){
					printf("L'élève est désormais inscrit en CE2.\n");
				}
				if (agecalcule==9){
					printf("L'élève est désormais inscrit en CM1.\n");
				}
				if (agecalcule==10){
					printf("L'élève est désormais inscrit en CM2.\n");
				}
				if(agecalcule>10){
					printf("L'élève est trop âgé pour intégrer l'école\n");
				}
			// si l'élève n'est pas déjà inscrit dans l'école, on va l'intégrer à une classe
				if(agecalcule==6) // si l'élève a 6 ans, il intégre la classe de CP
				{
					strcpy(Classes[0].Eleves[*ptr_compteurCP].nom,saisie_nom); // ajout de son nom dans le tableau des élèves de la classe de CP
					strcpy(Classes[0].Eleves[*ptr_compteurCP].prenom,saisie_prenom); // de son prénom
					Classes[0].Eleves[*ptr_compteurCP].age=agecalcule; // de son âge
					*ptr_compteurCP=*ptr_compteurCP+1; // incrémentation du nombre d'élèves dans la classe de CP
				}
				else if(agecalcule==7) // si l'élève a 7 ans, il intégre la classe de CE1
				{
					strcpy(Classes[1].Eleves[*ptr_compteurCE1].nom,saisie_nom);
					strcpy(Classes[1].Eleves[*ptr_compteurCE1].prenom,saisie_prenom);
					Classes[1].Eleves[*ptr_compteurCE1].age=agecalcule;
					*ptr_compteurCE1=*ptr_compteurCE1+1;
				}
				else if(agecalcule==8) // si l'élève a 8 ans, il intégre la classe de CE2
				{
					strcpy(Classes[2].Eleves[*ptr_compteurCE2].nom,saisie_nom);
					strcpy(Classes[2].Eleves[*ptr_compteurCE2].prenom,saisie_prenom);
					Classes[2].Eleves[*ptr_compteurCE2].age=agecalcule;
					*ptr_compteurCE2=*ptr_compteurCE2+1;
				}
				else if(agecalcule==9) // si l'élève a 9 ans, il intégre la classe de CM1
				{
					strcpy(Classes[3].Eleves[*ptr_compteurCM1].nom,saisie_nom);
					strcpy(Classes[3].Eleves[*ptr_compteurCM1].prenom,saisie_prenom);
					Classes[3].Eleves[*ptr_compteurCM1].age=agecalcule;
					*ptr_compteurCM1=*ptr_compteurCM1+1;
				}
				else if(agecalcule==10) // si l'élève a 10 ans, il intégre la classe de CM2
				{
					strcpy(Classes[4].Eleves[*ptr_compteurCM2].nom,saisie_nom);
					strcpy(Classes[4].Eleves[*ptr_compteurCM2].prenom,saisie_prenom);
					Classes[4].Eleves[*ptr_compteurCM2].age=agecalcule;
					*ptr_compteurCM2=*ptr_compteurCM2+1;
				}
			}	
			//while(saisiefonction!='C' && saisiefonction!='Q')
			//{
				printf("Continuer(C) ou Quitter(Q)?");	
				scanf(" %c",&saisiefonction);
				saisiefonction=toupper(saisiefonction);
				//if(saisiefonction!='C' && saisiefonction!='Q')
				//{
				//	printf("Saisie invalide. Veuillez réssayer.\n");
				//}		
			//}
		}
		// incrémentation du nombre total d'élèves dans l'école (toutes classes confondues)	
		compteurtotal=*ptr_compteurCP+*ptr_compteurCE1+*ptr_compteurCE2+*ptr_compteurCM1+*ptr_compteurCM2;
	}	

	printf("Nombre d'élève(s) en CP %d. \n",*ptr_compteurCP);
	printf("Nombre d'élève(s) en CE1 %d. \n",*ptr_compteurCE1);
	printf("Nombre d'élève(s) en CE2 %d. \n",*ptr_compteurCE2);
	printf("Nombre d'élève(s) en CM1 %d. \n",*ptr_compteurCM1);
	printf("Nombre d'élève(s) en CM2 %d. \n",*ptr_compteurCM2);
	printf("Nombre total d'élève(s) dans l'école %d. \n",compteurtotal);	
}

void RechercheDuDossier_Lorenzo(struct classes *Classes, int *ptr_compteurCP, int *ptr_compteurCE1, int *ptr_compteurCE2, int *ptr_compteurCM1, int *ptr_compteurCM2)
{
	char nom_recherche[20];
	char prenom_recherche[20];

	printf("RECHERCHE DOSSIER ÉLÈVE:\n");

	printf("De quel élève recherchez-vous les informations?\nNom de l'élève: ");
	scanf(" %s",nom_recherche);

	for (int low=0; low<strlen(nom_recherche); low++){
		nom_recherche[low]=tolower(nom_recherche[low]);
	}

	printf("Prénom de l'élève: ");
	scanf(" %s",prenom_recherche);

	for (int low=0; low<strlen(prenom_recherche); low++){
		prenom_recherche[low]=tolower(prenom_recherche[low]);
	}

	printf("\nDOSSIER DE L'ÉLÈVE:\n");

	int verification=0;
	for (int y_AffInfo=0; y_AffInfo<5;y_AffInfo++) // parcours de toutes les classes de l'école
	{
		if (y_AffInfo==0) // dans la classe de CP
		{
			for (int a_AffInfo = 0; a_AffInfo< *ptr_compteurCP; a_AffInfo++) // parcours de tous les élèves de la classe de CP
			{
				if (strcmp(Classes[0].Eleves[a_AffInfo].nom,nom_recherche)==0 && strcmp(Classes[0].Eleves[a_AffInfo].prenom,prenom_recherche)==0) // si l'élève est dans la classe de CP
				{
					// affichage de son dossier
					Classes[0].Eleves[a_AffInfo].nom[0]=toupper(Classes[0].Eleves[a_AffInfo].nom[0]);
					Classes[0].Eleves[a_AffInfo].prenom[0]=toupper(Classes[0].Eleves[a_AffInfo].prenom[0]);
					printf("Nom: %s\nPrénom: %s\nÂge: %d ans\n",Classes[0].Eleves[a_AffInfo].nom,Classes[0].Eleves[a_AffInfo].prenom,Classes[0].Eleves[a_AffInfo].age);
					Classes[0].Eleves[a_AffInfo].nom[0]=tolower(Classes[0].Eleves[a_AffInfo].nom[0]);
					Classes[0].Eleves[a_AffInfo].prenom[0]=tolower(Classes[0].Eleves[a_AffInfo].prenom[0]);
					verification=1;
				}
			} 
		}
		else
		{ 
			if (y_AffInfo==1)
			{
				for (int b_AffInfo = 0; b_AffInfo< *ptr_compteurCE1; b_AffInfo++)
				{
					if (strcmp(Classes[1].Eleves[b_AffInfo].nom,nom_recherche)==0 && strcmp(Classes[1].Eleves[b_AffInfo].prenom,prenom_recherche)==0)
					{
						Classes[1].Eleves[b_AffInfo].nom[0]=toupper(Classes[1].Eleves[b_AffInfo].nom[0]);
						Classes[1].Eleves[b_AffInfo].prenom[0]=toupper(Classes[1].Eleves[b_AffInfo].prenom[0]);
						printf("Nom: %s\nPrénom: %s\nÂge : %d ans\n",Classes[1].Eleves[b_AffInfo].nom,Classes[1].Eleves[b_AffInfo].prenom,Classes[1].Eleves[b_AffInfo].age);
						Classes[1].Eleves[b_AffInfo].nom[0]=tolower(Classes[1].Eleves[b_AffInfo].nom[0]);
						Classes[1].Eleves[b_AffInfo].prenom[0]=tolower(Classes[1].Eleves[b_AffInfo].prenom[0]);
						verification=1;
					}
				} 
			}
			else
			{
				if (y_AffInfo==2)
				{
					for (int c_AffInfo = 0; c_AffInfo< *ptr_compteurCE2; c_AffInfo++)
					{
						if (strcmp(Classes[2].Eleves[c_AffInfo].nom,nom_recherche)==0 && strcmp(Classes[2].Eleves[c_AffInfo].prenom,prenom_recherche)==0)
						{
							Classes[2].Eleves[c_AffInfo].nom[0]=toupper(Classes[2].Eleves[c_AffInfo].nom[0]);
							Classes[2].Eleves[c_AffInfo].prenom[0]=toupper(Classes[2].Eleves[c_AffInfo].prenom[0]);
							printf("Nom: %s\nPrénom: %s\nÂge: %d ans\n",Classes[2].Eleves[c_AffInfo].nom,Classes[2].Eleves[c_AffInfo].prenom,Classes[2].Eleves[c_AffInfo].age);
							Classes[2].Eleves[c_AffInfo].nom[0]=tolower(Classes[2].Eleves[c_AffInfo].nom[0]);
							Classes[2].Eleves[c_AffInfo].prenom[0]=tolower(Classes[2].Eleves[c_AffInfo].prenom[0]);
							verification=1;
						}	
					}
				}
				else
				{
					if (y_AffInfo==3)
					{
						for (int d_AffInfo = 0; d_AffInfo< *ptr_compteurCM1; d_AffInfo++)
						{
							if (strcmp(Classes[3].Eleves[d_AffInfo].nom,nom_recherche)==0 && strcmp(Classes[3].Eleves[d_AffInfo].prenom,prenom_recherche)==0)
							{
								Classes[3].Eleves[d_AffInfo].nom[0]=toupper(Classes[3].Eleves[d_AffInfo].nom[0]);
								Classes[3].Eleves[d_AffInfo].prenom[0]=toupper(Classes[3].Eleves[d_AffInfo].prenom[0]);
								printf("Nom: %s\nPrénom: %s\nÂge: %d ans\n",Classes[3].Eleves[d_AffInfo].nom,Classes[3].Eleves[d_AffInfo].prenom,Classes[3].Eleves[d_AffInfo].age);
								Classes[3].Eleves[d_AffInfo].nom[0]=tolower(Classes[3].Eleves[d_AffInfo].nom[0]);
								Classes[3].Eleves[d_AffInfo].prenom[0]=tolower(Classes[3].Eleves[d_AffInfo].prenom[0]);
								verification=1;
							}		
						}
					}
					else
					{
						if (y_AffInfo==4)
						{
							for (int e_AffInfo = 0; e_AffInfo< *ptr_compteurCM2; e_AffInfo++)
							{
								if (strcmp(Classes[4].Eleves[e_AffInfo].nom,nom_recherche)==0 && strcmp(Classes[4].Eleves[e_AffInfo].nom,nom_recherche)==0)
								{
									Classes[4].Eleves[e_AffInfo].nom[0]=toupper(Classes[4].Eleves[e_AffInfo].nom[0]);
									Classes[4].Eleves[e_AffInfo].prenom[0]=toupper(Classes[4].Eleves[e_AffInfo].prenom[0]);
									printf("Nom: %s\nPrénom: %s\nÂge: %d ans\n",Classes[4].Eleves[e_AffInfo].nom,Classes[4].Eleves[e_AffInfo].prenom,Classes[4].Eleves[e_AffInfo].age);
									Classes[4].Eleves[e_AffInfo].nom[0]=tolower(Classes[4].Eleves[e_AffInfo].nom[0]);
									Classes[4].Eleves[e_AffInfo].prenom[0]=tolower(Classes[4].Eleves[e_AffInfo].prenom[0]);
									verification=1;
								}			
							} 
						}
					}
				}	
			}
		}
	}

	// if(verification==0) //si l'élève n'est pas trouvé dans une classe, c'est qu'il n'est pas inscrit
	// {
	// 	printf("Cet élève n'est pas inscrit dans cette école.\n");
	// }
}


void AfficherEcole_Cedric(int *ptr_compteurCP, int *ptr_compteurCE1, int *ptr_compteurCE2, int *ptr_compteurCM1, int *ptr_compteurCM2, struct classes *mon_ecole)
{

	printf("AFFICHAGE ÉCOLE:\n");
	int nombre_eleve_total=*ptr_compteurCP+*ptr_compteurCE1+*ptr_compteurCE2+*ptr_compteurCM1+*ptr_compteurCM2;
	printf("L'école est composée de 5 classes: ");
	printf("%s %s %s %s %s\n",mon_ecole->rang,(mon_ecole+1)->rang,(mon_ecole+2)->rang,(mon_ecole+3)->rang,(mon_ecole+4)->rang);
	printf("Il y a %d élève(s) dans cette école.",nombre_eleve_total);
}

void AfficherClasse_Cedric(int *ptr_compteurCP, int *ptr_compteurCE1, int *ptr_compteurCE2, int *ptr_compteurCM1, int *ptr_compteurCM2)  
{
	struct classes CP={"CP",6};
	struct classes CE1={"CE1",7};
	struct classes CE2={"CE2",8};
	struct classes CM1={"CM1",9};
	struct classes CM2={"CM2",10};

	struct classes tab[4];

	tab[0]=CP;
	tab[1]=CE1;
	tab[2]=CE2;
	tab[3]=CM1;
	tab[4]=CM2;
	
	int choix;

	printf("AFFICHAGE CLASSE:\n");

	printf("Choisissez la classe que vous voulez afficher: (Tapez 0 pour CP, 1 pour CE1, 2 pour CE2, 3 pour CM1, 4 POUR CM2)\n");
	scanf(" %d",&choix);

	if (choix==0)
	{
		printf("La classe sélectionnée est:  %s\n",tab[choix].rang);
		//recupérer compteur de la fonction inscription 
		printf("L'âge requis pour être dans cette classe est de %d ans.\n",tab[choix].age);
		printf("Il y a %d élève(s) dans cette classe.",*ptr_compteurCP);
	}
	else if (choix==1)
	{
		printf("La classe sélectionnée est: %s\n",tab[choix].rang);
		//recupérer compteur de la fonction inscription 
		printf("L'âge requis pour être dans cette classe est de %d ans.\n",tab[choix].age);
		printf("Il y a %d élève(s) dans cette classe.",*ptr_compteurCE1);
	}
	else if (choix==2)
	{
		printf("La classe sélectionnée est: %s\n",tab[choix].rang);
		//recupérer compteur de la fonction inscription 
		printf("L'âge requis pour être dans cette classe est de %d ans.\n",tab[choix].age);
		printf("Il y a %d élève(s) dans cette classe.",*ptr_compteurCE2);
	}
	else if (choix==3)
	{
		printf("La classe sélectionnée est: %s\n",tab[choix].rang);
		//recupérer compteur de la fonction inscription 
		printf("L'âge requis pour être dans cette classe est de %d ans.\n",tab[choix].age);
		printf("Il y a %d élève(s) dans cette classe.",*ptr_compteurCM1);
	}
	else if (choix==4)
	{
		printf("La classe sélectionnée est: %s\n",tab[choix].rang);
		//recupérer compteur de la fonction inscription 
		printf("L'âge requis pour être dans cette classe est de %d ans.\n",tab[choix].age);
		printf("Il y a %d élève(s) dans cette classe.",*ptr_compteurCM2);
	}
}

struct classes *ModificationDossier_Marine(struct classes *Classes, int classe_AffInfo, int eleve_AffInfo, char nom[20], char prenom[20]){
	char reponse;
	int verification=0;
	
	// si l'utilisateur saisi un nom et prénom d'un élève existant.
	if(strcmp(Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom, nom)==0 && strcmp(Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom, prenom)==0){
		verification = 1;
		Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]=toupper(Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]);
		Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]=toupper(Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]);
		printf("\nQuelle information de l'élève %s %s souhaitez-vous modifier?\n", Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom, Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom);
		printf("Son nom? (O=Oui ou N=Non) ");
		scanf(" %c", &reponse);

		reponse=toupper(reponse);

		// si l'utilisateur veut modifier le nom de l'élève
		if(reponse=='O'){
			char newNom[20];
			printf("Entrez le nouveau nom: ");
			scanf("%s", newNom);

			for (int low=0; low<strlen(newNom); low++){
				newNom[low]=tolower(newNom[low]);
			}

			strcpy(Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom, newNom);
			nom[0]=toupper(nom[0]);
			prenom[0]=toupper(prenom[0]);
			Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]=toupper(Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]);
			Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]=toupper(Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]);
			printf("L'élève %s %s a été renommé %s %s.\n", nom, prenom, Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom, Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom);
			Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]=tolower(Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]);
			Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]=tolower(Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]);
		}

		// si l'utilisateur ne veut pas modifier le nom de l'élève...
		else if(reponse=='N'){
			printf("Son prénom? (O=Oui ou N=Non) ");
			scanf(" %c", &reponse);
			reponse=toupper(reponse);

			//...veut-il modifier le prénom de l'élève?
			if(reponse == 'O'){
				char newPrenom[20];
				printf("Entrez le nouveau prénom: ");
				scanf("%s", newPrenom);
				
				for (int low=0; low<strlen(newPrenom); low++){
					newPrenom[low]=tolower(newPrenom[low]);
				}

				strcpy(Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom, newPrenom);
				nom[0]=toupper(nom[0]);
				prenom[0]=toupper(prenom[0]);
				Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]=toupper(Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]);
				Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]=toupper(Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]);
				printf("L'élève %s %s a été renommé %s %s.\n", nom, prenom, Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom, Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom);
				Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]=tolower(Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]);
				Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]=tolower(Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]);
			}

			//s'il ne veut changer ni le nom ni le prénom, veut-il modifier l'âge?
			else if(reponse=='N'){
				printf("Son age? (O=Oui ou N=Non) ");
				scanf(" %c", &reponse);
				reponse=toupper(reponse);
				if (reponse=='O'){
					verification == 1;
					int newAge;
					printf("Entrez le nouvel âge: ");
					scanf("%d", &newAge);
					//printf("%d", newAge);
					Classes[classe_AffInfo].Eleves[eleve_AffInfo].age = newAge;
					//printf("%d", MonEleve[i].age);
					Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]=toupper(Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]);
					Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]=toupper(Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]);
					printf("L'élève %s %s a %d ans maintenant.\n", Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom, Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom, Classes[classe_AffInfo].Eleves[eleve_AffInfo].age);
					Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]=tolower(Classes[classe_AffInfo].Eleves[eleve_AffInfo].nom[0]);
					Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]=tolower(Classes[classe_AffInfo].Eleves[eleve_AffInfo].prenom[0]);
				}
					
				// si l'utilisateur mais non à chaque étape, quit avec message d'erreur.
				else if(reponse=='N'){
					verification==1;
					nom[0]=toupper(nom[0]);
					prenom[0]=toupper(prenom[0]);
					printf("\nIl semblerait que vous ne souhaitiez pas modifier d'information sur l'élève %s %s.\n", nom, prenom);
				}
			}
		}
	}
	// if(verification==0){ //si l'élève n'est pas trouvé dans une classe, c'est qu'il n'est pas inscrit
	// 	printf("Cet élève n'est pas inscrit dans cette école.\n");
	// }
}

struct classes *ModifierInfoEleve_Marine(struct classes *MaClasse, int *ptr_compteurCP, int *ptr_compteurCE1, int *ptr_compteurCE2, int *ptr_compteurCM1, int *ptr_compteurCM2){
	
	printf("MODIFICATION DES INFORMATIONS DU DOSSIER ÉLÈVE:\n");

	//saisie utilisateur de l'élève dont les infos doivent être modifiées
	char prenom[30];
	char nom[30];
	printf("Saisissez le nom de l'élève: ");
	scanf("%s", nom);
	
	for (int low=0; low<strlen(nom); low++){
		nom[low]=tolower(nom[low]);
	}

	printf("Saisissez le prénom de l'élève: ");
	scanf("%s", prenom);

	for (int low=0; low<strlen(prenom); low++){
		prenom[low]=tolower(prenom[low]);
	}

	// Parcours des classes pour trouver l'élève
	for (int classe_AffInfo=0; classe_AffInfo<5;classe_AffInfo++){ // parcours de toutes les classes de l'école
		if (classe_AffInfo==0){ // dans la classe de CP
			for (int eleve_AffInfo = 0; eleve_AffInfo< *ptr_compteurCP; eleve_AffInfo++){ // parcours de tous les élèves de la classe de CP
				ModificationDossier_Marine(MaClasse, classe_AffInfo, eleve_AffInfo, nom, prenom); // modif des infos de l'élève si l'utilisateur le souhaite
			}		
		}
		else if (classe_AffInfo==1){
			for (int eleve_AffInfo = 0; eleve_AffInfo< *ptr_compteurCE1; eleve_AffInfo++){
				ModificationDossier_Marine(MaClasse, classe_AffInfo, eleve_AffInfo, nom, prenom);
			}		
		}
		else if (classe_AffInfo==2){
			for (int eleve_AffInfo = 0; eleve_AffInfo< *ptr_compteurCE2; eleve_AffInfo++){
				ModificationDossier_Marine(MaClasse, classe_AffInfo, eleve_AffInfo, nom, prenom);
			}		
		}
		else if (classe_AffInfo==3){
			for (int eleve_AffInfo = 0; eleve_AffInfo< *ptr_compteurCM1; eleve_AffInfo++){
				ModificationDossier_Marine(MaClasse, classe_AffInfo, eleve_AffInfo, nom, prenom);
			}		
		}
		else if (classe_AffInfo==4){
			for (int eleve_AffInfo = 0; eleve_AffInfo< *ptr_compteurCM2; eleve_AffInfo++){
				ModificationDossier_Marine(MaClasse, classe_AffInfo, eleve_AffInfo, nom, prenom);
			}		
		}
	}
}
void AfficherClasseEleve_Lorenzo(struct classes *Classes, int *ptr_compteurCP, int *ptr_compteurCE1, int *ptr_compteurCE2, int *ptr_compteurCM1, int *ptr_compteurCM2)
{

	char nom_rechercheClasse[20];
	char prenom_rechercheClasse[20];

	printf("RECHERCHE CLASSE ÉLÈVE:\n");

	printf("Entrez le nom de l'élève: ");
	scanf(" %s",nom_rechercheClasse);

	for (int low=0; low<strlen(nom_rechercheClasse); low++){
		nom_rechercheClasse[low]=tolower(nom_rechercheClasse[low]);
	}

	printf("\nEntrez le prénom de l'élève: ");
	scanf(" %s",prenom_rechercheClasse);

	for (int low=0; low<strlen(prenom_rechercheClasse); low++){
		prenom_rechercheClasse[low]=tolower(prenom_rechercheClasse[low]);
	}

	int verification=0;
	for (int y_AffClasseEleve=0; y_AffClasseEleve<5;y_AffClasseEleve++) // parcours de toutes les classes de l'école
	{
		if (y_AffClasseEleve==0) // dans la classe de CP
		{
			for (int a_AffClasseEleve = 0; a_AffClasseEleve< *ptr_compteurCP; a_AffClasseEleve++) // parcours de tous les élèves de la classe de CP
			{
				if (strcmp(Classes[0].Eleves[a_AffClasseEleve].nom,nom_rechercheClasse)==0 && strcmp(Classes[0].Eleves[a_AffClasseEleve].prenom,prenom_rechercheClasse)==0) // si l'élève est dans la classe de CP
				{
					// affichage de sa classe
					printf("L'élève appartient à la classe CP.");
					verification=1;
				}
			} 
		}
		else
		{ 
			if (y_AffClasseEleve==1)
			{
				for (int b_AffClasseEleve = 0; b_AffClasseEleve< *ptr_compteurCE1; b_AffClasseEleve++)
				{
					if (strcmp(Classes[1].Eleves[b_AffClasseEleve].nom,nom_rechercheClasse)==0 && strcmp(Classes[1].Eleves[b_AffClasseEleve].prenom,prenom_rechercheClasse)==0)
					{
						printf("L'élève appartient à la classe CE1.");
						verification=1;
					}
				} 
			}
			else
			{
				if (y_AffClasseEleve==2)
				{
					for (int c_AffClasseEleve = 0; c_AffClasseEleve< *ptr_compteurCE2; c_AffClasseEleve++)
					{
						if (strcmp(Classes[2].Eleves[c_AffClasseEleve].nom,nom_rechercheClasse)==0 && strcmp(Classes[2].Eleves[c_AffClasseEleve].prenom,prenom_rechercheClasse)==0)
						{
							printf("L'élève appartient à la classe CE2.");
							verification=1;
						}	
					}
				}
				else
				{
					if (y_AffClasseEleve==3)
					{
						for (int d_AffClasseEleve = 0; d_AffClasseEleve< *ptr_compteurCM1; d_AffClasseEleve++)
						{
							if (strcmp(Classes[3].Eleves[d_AffClasseEleve].nom,nom_rechercheClasse)==0 && strcmp(Classes[3].Eleves[d_AffClasseEleve].prenom,prenom_rechercheClasse)==0)
							{
								printf("L'élève appartient à la classe CM1.");
								verification=1;
							}		
						}
					}
					else
					{
						if (y_AffClasseEleve==4)
						{
							for (int e_AffClasseEleve = 0; e_AffClasseEleve< *ptr_compteurCM2; e_AffClasseEleve++)
							{
								if (strcmp(Classes[4].Eleves[e_AffClasseEleve].nom,nom_rechercheClasse)==0 && strcmp(Classes[4].Eleves[e_AffClasseEleve].nom,nom_rechercheClasse)==0)
								{
									printf("L'élève appartient à la classe CM2.");
									verification=1;
								}			
							} 
						}
					}
				}	
			}
		}
	}
	
	if(verification==0) //si l'élève n'est pas trouvé dans une classe, c'est qu'il n'est pas inscrit
	{
		printf("Cet élève n'est pas inscrit dans cette école et n'appartient donc à aucune classe.\n");
	}
}


struct classes *SauvegardeFile_CedricMarine(struct classes *TabClasse, int *ptr_compteurCP, int *ptr_compteurCE1, int *ptr_compteurCE2, int *ptr_compteurCM1, int *ptr_compteurCM2)
{
	FILE *ptr_file=NULL;
	ptr_file =fopen("liste1.txt","w");

	for (int i=0; i<5; i++){
		if (i==0) // dans la classe de CP
		{
			for(int j=0; j<*ptr_compteurCP; j++){
				fprintf(ptr_file, "%s;%s;%d\n",TabClasse[i].Eleves[j].nom,TabClasse[i].Eleves[j].prenom,TabClasse[i].Eleves[j].age);
			}
		}
		if (i==1) // dans la classe de CE1
		{
			for(int j=0; j<*ptr_compteurCE1; j++){
				fprintf(ptr_file, "%s;%s;%d\n",TabClasse[i].Eleves[j].nom,TabClasse[i].Eleves[j].prenom,TabClasse[i].Eleves[j].age);
			}
		}
		if (i==2) // dans la classe de CE2
		{
			for(int j=0; j<*ptr_compteurCE2; j++){
				fprintf(ptr_file, "%s;%s;%d\n",TabClasse[i].Eleves[j].nom,TabClasse[i].Eleves[j].prenom,TabClasse[i].Eleves[j].age);
			}
		}
		if (i==3) // dans la classe de CM1
		{
			for(int j=0; j<*ptr_compteurCM1; j++){
				fprintf(ptr_file, "%s;%s;%d\n",TabClasse[i].Eleves[j].nom,TabClasse[i].Eleves[j].prenom,TabClasse[i].Eleves[j].age);
			}
		}
		if (i==4) // dans la classe de CM2
			{
			for(int j=0; j<*ptr_compteurCM2; j++){
				fprintf(ptr_file, "%s;%s;%d\n",TabClasse[i].Eleves[j].nom,TabClasse[i].Eleves[j].prenom,TabClasse[i].Eleves[j].age);
			}
		}
	}
}
