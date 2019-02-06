#include<stdlib.h>
#include<stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "ProjetC_EquipeMarine_fichiers_fonctions.h"

// déclaration des structures
struct classes TabClasses[4];
struct ecole MonEcole;
	
int main(int argc, char ** argv){

	// déclaration et initialisation de pointeurs pour les compteurs d'élèves par classe
	int compteurCP=0;
	int compteurCE1=0;
	int compteurCE2=0;
	int compteurCM1=0;
	int compteurCM2=0;

	int *ptr_compteurCP=NULL;
	int *ptr_compteurCE1=NULL;
	int *ptr_compteurCE2=NULL;
	int *ptr_compteurCM1=NULL;
	int *ptr_compteurCM2=NULL;
	int *ptr_compteurtotal=NULL;

	ptr_compteurCP=&compteurCP;
	ptr_compteurCE1=&compteurCE1;
	ptr_compteurCE2=&compteurCE2;
	ptr_compteurCM1=&compteurCM1;
	ptr_compteurCM2=&compteurCM2;

	strcpy(TabClasses[0].rang,"CP"); 
	strcpy(TabClasses[1].rang,"CE1");
	strcpy(TabClasses[2].rang,"CE2");
	strcpy(TabClasses[3].rang,"CM1");
	strcpy(TabClasses[4].rang,"CM2");

	// Lecture des informations depuis un fichier
	char c='\0';
	int nb_eleve=0;
	FILE *ptr_file=NULL;

	ptr_file =fopen("liste1.txt","r+");

	if(ptr_file==NULL)
	{
		printf("Le fichier rencontre une erreur");
	}
	else
	{
		while(c!=EOF)
		{
			c=fgetc(ptr_file);
			if(c=='\n')
			{
				nb_eleve++;
			}
		}
		
		fseek(ptr_file,0,SEEK_SET);
		
		for(int i=0;i<nb_eleve;i++)
		{
			char nom_trouve[50]={'\0'};
			fscanf(ptr_file,"%[^;]s",nom_trouve);
			fseek(ptr_file,1,SEEK_CUR);
			char prenom_trouve[50]={'\0'};
			fscanf(ptr_file,"%[^;]s",prenom_trouve);
			fseek(ptr_file,1,SEEK_CUR);
			int age;
			fscanf(ptr_file,"%d",&age);
			struct eleves mon_eleve;
			strcpy(mon_eleve.nom,nom_trouve);
			strcpy(mon_eleve.prenom,prenom_trouve);
			mon_eleve.age=age;
						

			if(age==6){
				
				TabClasses[0].Eleves[compteurCP]=mon_eleve;
				printf("%s ",TabClasses[0].Eleves[compteurCP].nom);
				printf("%s ",TabClasses[0].Eleves[compteurCP].prenom);
				printf(" %d\n",TabClasses[0].Eleves[compteurCP].age);
				printf("%d",compteurCP);
				char nom_trouve[50]={'\0'};
				char prenom_trouve[50]={'\0'};
				fscanf(ptr_file,"%d",&age);
				compteurCP++;
			}
			if(age==7){
				
				TabClasses[1].Eleves[compteurCE1]=mon_eleve;
				printf("%s",TabClasses[1].Eleves[compteurCE1].nom);
				printf("%s",TabClasses[1].Eleves[compteurCE1].prenom);
				printf("%d\n",TabClasses[1].Eleves[compteurCE1].age);
				char nom_trouve[50]={'\0'};
				char prenom_trouve[50]={'\0'};
				fscanf(ptr_file,"%d",&age);
				compteurCE1++;
			}
			if(age==8){
				
				TabClasses[2].Eleves[compteurCE2]=mon_eleve;
				printf("%s",TabClasses[2].Eleves[compteurCE2].nom);
				printf("%s",TabClasses[2].Eleves[compteurCE2].prenom);
				printf("%d\n",TabClasses[2].Eleves[compteurCE2].age);
				char nom_trouve[50]={'\0'};
				char prenom_trouve[50]={'\0'};
				fscanf(ptr_file,"%d",&age);
				compteurCE2++;
			}
			if(age==9){
				
				TabClasses[3].Eleves[compteurCM1]=mon_eleve;
				printf("%s",TabClasses[3].Eleves[compteurCM1].nom);
				printf("%s",TabClasses[3].Eleves[compteurCM1].prenom);
				printf("%d\n",TabClasses[3].Eleves[compteurCM1].age);
				char nom_trouve[50]={'\0'};
				char prenom_trouve[50]={'\0'};
				fscanf(ptr_file,"%d",&age);
				compteurCM1++;
			}
			if(age==10){
				
				TabClasses[4].Eleves[compteurCM2]=mon_eleve;
				printf("%s",TabClasses[4].Eleves[compteurCM2].nom);
				printf("%s",TabClasses[4].Eleves[compteurCM2].prenom);
				printf("%d\n",TabClasses[4].Eleves[compteurCM2].age);
				char nom_trouve[50]={'\0'};
				char prenom_trouve[50]={'\0'};
				fscanf(ptr_file,"%d",&age);
				compteurCM2++;
			}
		}
	}



	/////////////////////////////////Menu - JEREMIE/////////////////////////////////
	// Lancement du programme
	system("clear");
	printf("Bienvenue dans le logiciel de gestion d'élèves de l'école !\n");
	printf("*********************************************************\n\n");
	char menu;

	// proposer le menu tant que l'utilisateur ne saisi pas 'Q'
	do{
		menu = Menu_Jeremie();	

		if(menu == 'A'){
			system("clear");
			struct tm *infos;
			date aujourdhui,naissance;
			date*ptr_aujourdhui=NULL;
			ptr_aujourdhui=&aujourdhui;
			date*ptr_naissance=NULL;
			ptr_naissance=&naissance;
			time_t temps_act;
			time(&temps_act);   // Déterminer le temps actuel en secondes
			infos = localtime(&temps_act);

			aujourdhui.jour=infos->tm_mday;
			aujourdhui.mois=1+(infos->tm_mon);
			aujourdhui.annee=1900+(infos->tm_year);			
			
			inscription_cedric_et_zine(TabClasses, ptr_aujourdhui, ptr_naissance,ptr_compteurCP,ptr_compteurCE1,ptr_compteurCE2,ptr_compteurCM1,ptr_compteurCM2);
			int c;
			while ((c = getchar()) != '\n' && c != EOF){}
			printf("\nAppuyez sur (ENTRÉE) pour retourner sur le menu." );
			while(getchar()!='\n'){}
			system("clear");
		}
		else if(menu == 'B'){
			system("clear");
			AfficherClasseEleve_Lorenzo(TabClasses,ptr_compteurCP,ptr_compteurCE1,ptr_compteurCE2,ptr_compteurCM1,ptr_compteurCM2);
			printf("\nAppuyez sur (ENTRÉE) pour retourner sur le menu." );
			getchar();
			while(getchar()!='\n');
			system("clear");
		}
		else if(menu=='C'){
			system("clear");
			RechercheDuDossier_Lorenzo(TabClasses,ptr_compteurCP,ptr_compteurCE1,ptr_compteurCE2,ptr_compteurCM1,ptr_compteurCM2);
			printf("\nAppuyez sur (ENTRÉE) pour retourner sur le menu." );
			getchar();
			while(getchar()!='\n');
			system("clear");
		}
		else if(menu == 'D'){
			system("clear");
			ModifierInfoEleve_Marine(TabClasses, ptr_compteurCP,ptr_compteurCE1,ptr_compteurCE2,ptr_compteurCM1,ptr_compteurCM2);
			printf("\nAppuyez sur (ENTRÉE) pour retourner sur le menu." );
			getchar();
			while(getchar()!='\n');
			system("clear");
		}
		else if(menu == 'E'){
			system("clear");
			AfficherClasse_Cedric(ptr_compteurCP,ptr_compteurCE1,ptr_compteurCE2,ptr_compteurCM1,ptr_compteurCM2);
			printf("\nAppuyez sur (ENTRÉE) pour retourner sur le menu." );
			getchar();
			while(getchar()!='\n');
			system("clear");
		}
		else if	(menu =='F'){
			system("clear");
			AfficherEcole_Cedric(ptr_compteurCP,ptr_compteurCE1,ptr_compteurCE2,ptr_compteurCM1,ptr_compteurCM2,TabClasses);
			printf("\nAppuyez sur (ENTRÉE) pour retourner sur le menu." );
			getchar();
			while(getchar()!='\n');
			system("clear");
		}
		else if	(menu =='S'){
			system("clear");
			SauvegardeFile_CedricMarine(TabClasses, ptr_compteurCP,ptr_compteurCE1,ptr_compteurCE2,ptr_compteurCM1,ptr_compteurCM2);
		}

	} while(menu!='Q');

	return 0;	
}
