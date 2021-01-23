#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 250



struct User
{
int Code;
char NIF[MAX];
char Nom[MAX];
char Prenom[MAX];
char Password[MAX];
char Date[MAX];
char Type[MAX];
char Categorie[MAX];
int Module;
};

struct Etudiant
{
int Code;
char Faculte[MAX];
char Section[MAX];
int Session;
int AnneeAdm;
};

struct Professeur
{
int Code;
char Faculte[MAX];
char Section[MAX];
char Type[MAX];
int Nbcours;
char Cours[MAX];
};

struct PersonnelAdministratif
{
int Code ;
char Affectation[MAX];
char Poste[MAX];
int Annee;
char Superieur[MAX];
};


struct Bibliothecaire
{
int Code ;
char Affectation[MAX];
char Niveau[MAX];
int Annee;
char Superieur[MAX];
};



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct Cours
{
int Code;
char Titre[MAX];
char Faculte[MAX];
char Type[MAX]; // 1: Obligatoire  0: optionel
int NbCredit;
char Prof1[MAX];
char Prof2[MAX];
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct AdmProf
{
int Code;
char Nom[MAX];
char Prenom[MAX];
int Nbcours;
int Nbcredit;
float Salaire;
};

struct AdmEtudiant
{
int Code;
char Nom[MAX];
char Prenom[MAX];
char Faculte[MAX];
float Montant;
char Date[MAX];
};

struct AdmPersonnel
{
int Code ;
char Nom[MAX];
char Prenom[MAX];
char Direction[MAX];
char Fonction[MAX];
float Salaire;
};

struct AdmCours
{
int Code;
char Titre[MAX];
char Faculte[MAX];
int NbCredit;
char Cout[MAX];
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct Ouvrage
{
int Code;
char Categorie[MAX];
char Titre[MAX];
char Edition[MAX];
int AnneeEdition;
char Auteur1[MAX];
char Auteur2[MAX];
int NbPage;
char DateEntre[MAX];
char DateSortie[MAX];
char DateRetour[MAX];
int CodeEmp;
char NomEmp[MAX];
char PrenomEmp[MAX];
int Statut; //1: Disponible 0:Indisponible
};

struct NomComplet
{
    char nom[100];
    char prenom[100];
};

//______________________________________________________________________________

char *GetString();
char *Today ();
int AjouterUtilisateur();
int AjouterCours();
int AjouterLivre();
int GetLastID(int fileCode);
int AfficherUnLivre();
int AfficherUnCours();
int AfficherCours();
int AfficherLivre();
int AfficherCategorie();
char *GetString2();
void jsw_flush();
int Choix(int inf, int mex, char *warning);
void printMessageCenter(const char *message);
void headMessage(const char *message);
int CheckUserAvailability (int id);
void welcomeMessage();
int AfficherEtudiant();
int AfficherBibliothecaire();
int AfficherProfesseur();
int AfficherPersonnelAdministratif();
int AfficherAdministrateur();
int CheckBookAvailableR(int code);
int Retour (int codeUser ,int codeBook);
int Emprunt(int codeUser, int codeBook);
int ChangePassword(int id);
char * GetPassword();
int GetAccess ( );
void GestionAcces(int choix);
void GestionCours(int choix);
void GestionBibliotheque(int id ,int choix);
int main_window(int id);
//int ModifierCours();




