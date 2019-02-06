typedef struct date
{
	int jour;
	int mois;
	int annee;
}date;

struct eleves
{
	char nom[20];
	char prenom[20];
	int age;
};

struct classes
{
	char rang[4];
	int age;
	struct eleves Eleves[24];
};

struct ecole
{
	int nbclasse;
	struct classes Classes[4];	
};

char Menu_Jeremie();
void AfficherEcole_Cedric();
void AfficherClasse_Cedric();
int anniversaire(date a,date n);
int Affichage(int jour_naissance,int mois_naissance,int annee_naissance, date aujourdhui, date naissance);
void inscription_cedric_et_zine(struct classes *Classes, date *, date *,int *,int *,int *,int *,int *);
void RechercheDuDossier_Lorenzo(struct classes *Classes,int *,int *,int *,int *,int *);
void AfficherClasseEleve_Lorenzo(struct classes *Classes, int *, int *, int *, int *, int *);
struct classes *ModificationDossier_Marine(struct classes *Classes, int classe_AffInfo, int eleve_AffInfo, char nom[20], char prenom[20]);
struct classes *ModifierInfoEleve_Marine(struct classes *MaClasse, int *ptr_compteurCP,int *ptr_compteurCE1,int *ptr_compteurCE2,int *ptr_compteurCM1,int *ptr_compteurCM2);
struct classes *SauvegardeFile_CedricMarine(struct classes *TabClasse, int *ptr_compteurCP, int *ptr_compteurCE1, int *ptr_compteurCE2, int *ptr_compteurCM1, int *ptr_compteurCM2);