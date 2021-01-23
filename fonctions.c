#include "headers.h"


void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //Calculer combien espace qu'il faut placer
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //placer les espaces
        printf(" ");
    }
    //placer le message
    printf("%s",message);
}

void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Mini-Projet de systeme de gestion en C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void welcomeMessage()
{
    headMessage("UNIVERSITE QUISQUEYA");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==");
    printf("\n\t\t\t        =                BIENVENUE                 =");
    printf("\n\t\t\t        =                   AU                     =");
    printf("\n\t\t\t        =                 SYSTEME                  =");
    printf("\n\t\t\t        =                   DE                     =");
    printf("\n\t\t\t        =                 GESTION                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Appuyer un bouton pour continuer.....");
    getch();
}

int AjouterUtilisateur()
{
    struct User NewUser;
    struct Bibliothecaire NewBiblio;
    struct Etudiant NewStud;
    struct Professeur NewTeacher;
    struct PersonnelAdministratif NewPers;

    struct AdmEtudiant AdmE;
    struct AdmProf AmdP;
    struct AdmPersonnel AmdPers;
    headMessage("AJOUTER NOUVEL UTILISATEUR");
    printf("\n\n\t\t\tRENTRER LES DETAILS SUR L'UTILISATEUR:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    FILE *outfile;
    int choix = 0;
    float prix;
    NewUser.Code = 1 + GetLastID(1);
    printf("NOM                 :");
    strcpy(NewUser.Nom, GetString());
    printf("Prenom              :");
    strcpy(NewUser.Prenom, GetString());
    printf("NIF/CIN             :");
    strcpy(NewUser.NIF, GetString());
    printf("Mot de passe        :");
    strcpy(NewUser.Password, GetString());
    printf("Categorie           :\n");
    printf(" 1:Administrateur 2:Etudiant 3:Professeur 4:Comptable 5:Agent Administratif 6:Biblithecaire");
    printf("\n>> ");
    choix = Choix(1, 6, "Choisissez par la liste");
    switch (choix)
    {
    case 1:
        strcpy(NewUser.Categorie, "Administrateur");
        strcpy(NewUser.Type, "Administrateur");
        NewUser.Module = choix;
        break;
    case 2:
        strcpy(NewUser.Categorie, "Etudiant");
        strcpy(NewUser.Type, "Utilisateur");
        NewUser.Module = choix;
        break;
    case 3:
        strcpy(NewUser.Categorie, "Professeur");
        strcpy(NewUser.Type, "Utilisateur");
        NewUser.Module = choix;
        break;
    case 4:
        strcpy(NewUser.Categorie, "Comptable");
        strcpy(NewUser.Type, "Utilisateur");
        NewUser.Module = choix;
        break;
    case 5:
        strcpy(NewUser.Categorie, "Agent Administratif");
        strcpy(NewUser.Type, "Utilisateur");
        NewUser.Module = choix;
        break;
    case 6:
        strcpy(NewUser.Categorie, "Biblithecaire");
        strcpy(NewUser.Type, "Utilisateur");
        NewUser.Module = choix;
        break;
    }

    strcpy(NewUser.Date, Today());

    if (NewUser.Module == 2)
    { //Student
        printf("Faculte             :\n");
        printf("1 :FS - ECONOMIE ET ADMINISTRATION \n2 :FS - GENIE ET ARCHITECTURE \n3 :FS - AGRICULTURE ET ENVIRONNEMENT\n4 :FS - JURIDIQUES ET POLITIQUES\n5 :FS - EDUCATION\n6 :FS - SANTE");
        printf("\n>> ");
        choix = Choix(1, 6, "Choissir parmis les facultes");
        switch (choix)
        {
        case 1:
            strcpy(NewStud.Faculte, "FSEA");
            break;
        case 2:
            strcpy(NewStud.Faculte, "FSGA");
            break;
        case 3:
            strcpy(NewStud.Faculte, "FSAE");
            break;
        case 4:
            strcpy(NewStud.Faculte, "FSJP");
            break;
        case 5:
            strcpy(NewStud.Faculte, "FSED");
            break;
        case 6:
            strcpy(NewStud.Faculte, "FSSA");
            break;
        }

        printf("Section             :");

        strcpy(NewStud.Section, GetString());
        printf("Session             :");
        choix = Choix(1, 20, "Choisissez entre 1 et 20");
        NewStud.Session = choix;
        printf("Annee Admission     :");
        choix = Choix(1988, 2021, "Saisissez une annee de 1988 a nos jours");
        NewStud.AnneeAdm = choix;
        NewStud.Code = NewUser.Code;
        AdmE.Code = NewUser.Code;
        strcpy(AdmE.Nom, NewUser.Nom);
        strcpy(AdmE.Prenom, NewUser.Prenom);
      strcpy(AdmE.Faculte, NewStud.Faculte);

        printf("Balance             :");
        scanf("%f", &prix);
        AdmE.Montant = prix;

        system("clear");
        //print header
        printf("                      Confirmation \n\n");
        printf("ID                  :%d\n", NewUser.Code);
        printf("NOM                 :%s\n", NewUser.Nom);
        printf("Prenom              :%s\n", NewUser.Prenom);
        printf("NIF/CIN             :%s\n", NewUser.NIF);
        printf("Mot de passe        :%s\n", NewUser.Password);
        printf("Type                :%s\n", NewUser.Type);
        printf("Date de Creation    :%s\n", NewUser.Date);
        printf("Categorie           :%s\n", NewUser.Categorie);
        printf("Faculte             :%s\n", NewStud.Faculte);
        printf("Section             :%s\n", NewStud.Section);
        printf("Session             :%d\n", NewStud.Session);
        printf("Annee Admission     :%d\n", NewStud.AnneeAdm);
        printf("Balance             :%f $\n", AdmE.Montant);

        printf("Pressez ENTER pour confirmer");
        //getch();
        //save Etudiant
        // open file for writing
        outfile = fopen("Etudiant.bin", "ab");
        if (outfile == NULL)
        {
            fprintf(stderr, "\nErreur dans l'ouverture du fichier\n");
            exit(1);
        }
        // write struct to file
        fwrite(&NewStud, sizeof(struct Etudiant), 1, outfile);
        // close file
        fclose(outfile);

        outfile = fopen("AdministrationPers.bin", "ab");
        if (outfile == NULL)
        {
            fprintf(stderr, "\nErreur dans l'ouverture du fichier\n");
            exit(1);
        }
        // write struct to file
        fwrite(&AdmE, sizeof(struct AdmEtudiant), 1, outfile);
        fclose(outfile);
    }
    else if (NewUser.Module == 3)
    { //Teacher
        printf("Faculte             :\n");
        printf("1 :FS - ECONOMIE ET ADMINISTRATION \n2 :FS - GENIE ET ARCHITECTURE \n3 :FS - AGRICULTURE ET ENVIRONNEMENT\n4 :FS - JURIDIQUES ET POLITIQUES\n5 :FS - EDUCATION\n6 :FS - SANTE");
        printf("\n>> ");
        choix = Choix(1, 6, "Choissir parmis les facultes");
        switch (choix)
        {
        case 1:
            strcpy(NewTeacher.Faculte, "FSEA");
            break;
        case 2:
            strcpy(NewTeacher.Faculte, "FSGA");
            break;
        case 3:
            strcpy(NewTeacher.Faculte, "FSAE");
            break;
        case 4:
            strcpy(NewTeacher.Faculte, "FSJP");
            break;
        case 5:
            strcpy(NewTeacher.Faculte, "FSED");
            break;
        case 6:
            strcpy(NewTeacher.Faculte, "FSSA");
            break;
        }

        printf("Section             :");

        strcpy(NewTeacher.Section, GetString());

        printf("Type                :\n");
        printf("1 :Professeur Titulaire 2 :Professeur Travaux Pratiques 3 :Professeur Travaux Dirigees");
        printf("\n>> ");
        choix = Choix(1, 3, "Choisissez parmis les types");

        switch (choix)
        {
        case 1:
            strcpy(NewTeacher.Type, "Titulaire");
            break;
        case 2:
            strcpy(NewTeacher.Type, "TP");
            break;
        case 3:
            strcpy(NewTeacher.Type, "TD");
            break;
        }
        printf("Nombre Cours        :");
        choix = Choix(1, 20, "Choisissez un nombre de cours entre 1 et 20");
        NewTeacher.Nbcours = choix;
        printf("Cours               :\n");
        printf("Entrez les cours separees par des '-' \n");
        strcpy(NewTeacher.Cours, GetString());
        printf("Nombre de Credit    :");
        choix = Choix(1, 20, "Choisissez un nombre entre 1 et 20");
        AmdP.Nbcredit = choix;
        NewTeacher.Code = NewUser.Code;
        AmdP.Code = NewUser.Code;
        AmdP.Nbcours = NewTeacher.Nbcours;
        strcpy(AmdP.Nom, NewUser.Nom);
        strcpy(AmdP.Prenom, NewUser.Prenom);

        printf("Salaire             :");
        scanf("%f", &prix);
        AmdP.Salaire = prix;

        system("clear");
        //print header
        printf("                      Confirmation \n\n");
        printf("ID                  :%d\n", NewUser.Code);
        printf("NOM                 :%s\n", NewUser.Nom);
        printf("Prenom              :%s\n", NewUser.Prenom);
        printf("NIF/CIN             :%s\n", NewUser.NIF);
        printf("Mot de passe        :%s\n", NewUser.Password);
        printf("Type                :%s\n", NewUser.Type);
        printf("Date de Creation    :%s\n", NewUser.Date);
        printf("Categorie           :%s\n", NewUser.Categorie);
        printf("Faculte             :%s\n", NewTeacher.Faculte);
        printf("Section             :%s\n", NewTeacher.Section);
        printf("Type                :%s\n", NewTeacher.Type);
        printf("Nombre Cours        :%d\n", AmdP.Nbcours);
        printf("Nombre de Credit    :%d\n", AmdP.Nbcredit);
        printf("Salaire             :%f $\n", AmdP.Salaire);

        printf("Pressez ENTER pour confirmer");
        //getch();
        //save Prof
        // open file for writing
        outfile = fopen("Professeur.bin", "ab");
        if (outfile == NULL)
        {
            fprintf(stderr, "\nErreur dans l'ouverture du fichier\n");
            exit(1);
        }
        // write struct to file
        fwrite(&NewTeacher, sizeof(struct Professeur), 1, outfile);
        // close file
        fclose(outfile);

        outfile = fopen("AdministrationProf.bin", "ab");
        if (outfile == NULL)
        {
            fprintf(stderr, "\nErreur dans l'ouverture du fichier\n");
            exit(1);
        }
        // write struct to file
        fwrite(&AmdP, sizeof(struct AdmProf), 1, outfile);
        fclose(outfile);
    }
    else if (NewUser.Module == 5)
    { //PersAdmin
        printf("Affectation         :");
        strcpy(NewPers.Affectation, GetString());
        printf("Poste               :");
        strcpy(NewPers.Poste, GetString());
        printf("Annee               :");
        NewPers.Annee = Choix(1988, 2021, "Choissizez une date de 1988 a nos jours");
        printf("Superieur           :");
        strcpy(NewPers.Superieur, GetString());
        printf("Direction           :");
        strcpy(AmdPers.Direction, GetString());
        printf("Fonction            :");
        strcpy(AmdPers.Fonction, GetString());
        printf("Salaire             :");
        scanf("%f", &prix);
        AmdPers.Salaire = prix;

        strcpy(AmdPers.Nom, NewUser.Nom);
        strcpy(AmdPers.Prenom, NewUser.Prenom);
        AmdPers.Code = NewUser.Code;
        NewPers.Code = NewUser.Code;

        system("clear");
        //print header
        printf("                      Confirmation \n\n");
        printf("ID                  :%d\n", NewUser.Code);
        printf("NOM                 :%s\n", NewUser.Nom);
        printf("Prenom              :%s\n", NewUser.Prenom);
        printf("NIF/CIN             :%s\n", NewUser.NIF);
        printf("Mot de passe        :%s\n", NewUser.Password);
        printf("Type                :%s\n", NewUser.Type);
        printf("Date de Creation    :%s\n", NewUser.Date);
        printf("Categorie           :%s\n", NewUser.Categorie);
        printf("Affectation         :%s\n", NewPers.Affectation);
        printf("Poste               :%s\n", NewPers.Poste);
        printf("Annee               :%d\n", NewPers.Annee);
        printf("Superieur           :%s\n", NewPers.Superieur);
        printf("Direction           :%s\n", AmdPers.Direction);
        printf("Fonction            :%s\n", AmdPers.Fonction);
        printf("Salaire             :%f $\n", AmdPers.Salaire);

        printf("Pressez ENTER pour confirmer");
        //getch();
        //save Personnel
        // open file for writing
        outfile = fopen("PersonnelAdministratif.bin", "ab");
        if (outfile == NULL)
        {
            fprintf(stderr, "\nErreur dans l'ouverture du fichier\n");
            exit(1);
        }
        // write struct to file
        fwrite(&NewPers, sizeof(struct PersonnelAdministratif), 1, outfile);
        // close file
        fclose(outfile);

        outfile = fopen("AdministrationPers.bin", "ab");
        if (outfile == NULL)
        {
            fprintf(stderr, "\nErreur dans l'ouverture du fichier\n");
            exit(1);
        }
        // write struct to file
        fwrite(&AmdPers, sizeof(struct AdmPersonnel), 1, outfile);
        fclose(outfile);
    }
    else if (NewUser.Module == 6)
    { //Biblio

        printf("Affectation         :");
        strcpy(NewBiblio.Affectation, GetString());
        printf("Niveau              : ");
        choix = Choix(1, 2, "Choisissez parmis les niveaux");
        switch (choix)
        {
        case 1:
            strcpy(NewBiblio.Niveau, "N1");
            break;

        case 2:
            strcpy(NewBiblio.Niveau, "N2");
            break;
        }
        printf("Annee               :");
        NewPers.Annee = Choix(1988, 2021, "Choissizez une date de 1988 a nos jours");
        printf("Superieur           :");
        strcpy(NewBiblio.Superieur, GetString());

        system("clear");
        //print header
        printf("                      Confirmation \n\n");
        printf("ID                  :%d\n", NewUser.Code);
        printf("NOM                 :%s\n", NewUser.Nom);
        printf("Prenom              :%s\n", NewUser.Prenom);
        printf("NIF/CIN             :%s\n", NewUser.NIF);
        printf("Mot de passe        :%s\n", NewUser.Password);
        printf("Type                :%s\n", NewUser.Type);
        printf("Date de Creation    :%s\n", NewUser.Date);
        printf("Categorie           :%s\n", NewUser.Categorie);
        printf("Affectation         :%s\n", NewBiblio.Affectation);
        printf("Superieur           :%s\n", NewBiblio.Superieur);
        printf("Niveau              :%s\n", NewBiblio.Niveau);
        printf("Annee               :%d\n", NewBiblio.Annee);
        printf("Superieur           :%s\n", NewBiblio.Superieur);
        printf("Pressez ENTER pour confirmer");
        getchar();
        //save bibliothecaire
        // open file for writing
        outfile = fopen("Bibliothecaire.bin", "ab");
        if (outfile == NULL)
        {
            fprintf(stderr, "\nErreur dans l'ouverture du fichier\n");
            exit(1);
        }
        // write struct to file
        fwrite(&NewBiblio, sizeof(struct Bibliothecaire), 1, outfile);

        if (fwrite != 0)
        {

            printf("\n      Votre utilisateur a ete enregistre avec succes. Code : %d", NewUser.Code);
        }
        else
        {
            printf("\n Erreurs lors de l'enregistrement.");
        }

        // close file
        fclose(outfile);
    }
    //save user

    // open file for writing
    outfile = fopen("Utilisateur.bin", "ab");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nErreur dans l'ouverture du fichier\n");
        exit(1);
    }

    // write struct to file
    fwrite(&NewUser, sizeof(struct User), 1, outfile);

    // close file
    fclose(outfile);
}
void jsw_flush(void)
{
    int ch; /* getchar returns an int */
            /* Read characters until there are none left */
    do
        ch = getchar();
    while(ch != EOF && ch != '\n' );
    clearerr(stdin);    /* Clear EOF state */
}
char *GetString()
{

    static char input[100];
    //fflush(stdin);
   // __fpurge(stdin);

    fgets(input, 100, stdin);

    if (input[0] == '\n' && input[1] == '\0')
    {
        printf("\nCe champ est obligatoire .");
        printf("\n>>");
        jsw_flush();
        GetString();
    }
    strtok(input, "\n");
    return input;
}

char *Today()
{
    time_t t;
    struct tm *tmp;
    static char MY_TIME[50];
    time(&t);

    tmp = localtime(&t);
    strftime(MY_TIME, sizeof(MY_TIME), "%x - %I:%M%p", tmp);

    return MY_TIME;
}

int Choix(int inf, int mex, char *warning)
{
    char term;
    int input;
    fflush(stdin);
    //clean_stdin();
    if (scanf("%d%c", &input, &term) == 2 && term == '\n' && input >= inf && input <= mex)
    {
        return input;
    }
    else
    {
        printf("%s", warning);
        Choix(inf, mex, warning);
    }
}

int GetLastID(int fileCode)
{
    int id;
    FILE *infile;
    char file[20];

    struct User input;
    char fichier1[] = "Utilisateur.bin";
    int size1 = sizeof(struct User);

    struct Cours input2;
    char fichier2[] = "Cours.bin";
    int size2 = sizeof(struct Cours);

    struct Ouvrage input3;
    char fichier3[] = "Ouvrage.bin";
    int size3 = sizeof(struct Ouvrage);

    if (fileCode == 1)
    {
        infile = fopen(fichier1, "rb");
        if (infile == NULL)
        {
            fprintf(stderr, "\nError opening file\n");
            exit(1);
        }

        while (fread(&input, size1, 1, infile))
            id = input.Code;
    }
    else if (fileCode == 2)
    {
        infile = fopen(fichier2, "rb");
        if (infile == NULL)
        {
            fprintf(stderr, "\nError opening file\n");
            exit(1);
        }

        while (fread(&input2, size2, 1, infile))
            id = input2.Code;
    }
    else if (fileCode == 3)
    {
        infile = fopen(fichier3, "rb");
        if (infile == NULL)
        {
            fprintf(stderr, "\nError opening file\n");
            exit(1);
        }

        while (fread(&input3, size3, 1, infile))
            id = input3.Code;
    }

    fclose(infile);
    return id;
}

int AjouterCours()
{
    headMessage("AJOUTER NOUVEAU COURS");
    printf("\n\n\t\t\tRENTRER LES DETAILS SUR LE COURS:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    FILE *outfile;
    struct Cours NewCourse;
    int choix;
    NewCourse.Code = 1 + GetLastID(2);
    printf("Titre               :");
    strcpy(NewCourse.Titre, GetString());
    printf("Faculte             :\n");
    printf("1 :FS - ECONOMIE ET ADMINISTRATION \n2 :FS - GENIE ET ARCHITECTURE \n3 :FS - AGRICULTURE ET ENVIRONNEMENT\n4 :FS - JURIDIQUES ET POLITIQUES\n5 :FS - EDUCATION\n6 :FS - SANTE");
    printf("\n>> ");
    choix = Choix(1, 6, "Choissir parmis les facultes");
    switch (choix)
    {
    case 1:
        strcpy(NewCourse.Faculte, "FSEA");
        break;
    case 2:
        strcpy(NewCourse.Faculte, "FSGA");
        break;
    case 3:
        strcpy(NewCourse.Faculte, "FSAE");
        break;
    case 4:
        strcpy(NewCourse.Faculte, "FSJP");
        break;
    case 5:
        strcpy(NewCourse.Faculte, "FSED");
        break;
    case 6:
        strcpy(NewCourse.Faculte, "FSSA");
        break;
    }
    printf("Type                :\n");
    printf("1:Obligatoire\n2:Optionel\n>>");
    choix = Choix(1, 2, "Choisissez 1 ou 2");
    switch (choix)
    {
    case 1:
        strcpy(NewCourse.Type, "Obligatoire");
        break;

    case 2:
        strcpy(NewCourse.Type, "Optionel");
        break;
    }

    printf("Nombre de Credit    :");
    choix = Choix(1, 20, "Choisissez un nombre entre 1 et 20");
    NewCourse.NbCredit = choix;

    printf("Nombre de Prof      : ");
    choix = Choix(1, 2, "Choisissez 1 ou 2");
    switch (choix)
    {
    case 1:
        printf("Professeur          :");
        strcpy(NewCourse.Prof1, GetString());
        strcpy(NewCourse.Prof2, "");
        break;

    case 2:
        printf("Professeur 1        :");
        strcpy(NewCourse.Prof1, GetString());
        printf("Professeur 2        :");
        strcpy(NewCourse.Prof2, GetString());
        break;
    }

    system("clear");
    printf("ID                  :%d\n", NewCourse.Code);
    printf("Titre               :%s\n", NewCourse.Titre);
    printf("Faculte             :%s\n", NewCourse.Faculte);
    printf("Type                :%s\n", NewCourse.Type);
    printf("Nombre de Credit    :%d\n", NewCourse.NbCredit);
    printf("Professeur 1        :%s\n", NewCourse.Prof1);
    printf("Professeur 2        :%s\n", NewCourse.Prof2);
    printf("Pressez ENTER pour confirmer");
    //getch();
    //save Etudiant
    // open file for writing
    outfile = fopen("Cours.bin", "ab");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nErreur dans l'ouverture du fichier\n");
        exit(1);
    }
    // write struct to file
    fwrite(&NewCourse, sizeof(struct Cours), 1, outfile);
    // close file
    fclose(outfile);
}

int AjouterLivre()
{
    headMessage("AJOUTER NOUVEAU LIVRE");
    printMessageCenter("RENTRER LES DETAILS SUR LE LIVRE:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    struct Ouvrage Book;
    FILE *outfile;
    int choix;
    printf("Categorie           :");
    strcpy(Book.Categorie, GetString());
    printf("Titre               :");
    strcpy(Book.Titre, GetString());
    printf("Edition             :");
    strcpy(Book.Edition, GetString());
    printf("AnneeEdition        :");
    Book.AnneeEdition = Choix(1500, 2021, "Entrez une annee valable");

    printf("Nombre d'Auteurs    :");
    choix = Choix(1, 2, "Choisissez 1 ou 2");
    switch (choix)
    {
    case 1:
        printf("Auteur 1            :");
        strcpy(Book.Auteur1, GetString());
        strcpy(Book.Auteur2, "");
        break;

    case 2:
        printf("Auteur 1            :");
        strcpy(Book.Auteur1, GetString());
        printf("Auteur 2            :");
        strcpy(Book.Auteur2, GetString());
        break;
    }

    printf("NbPage              :");
    Book.NbPage = Choix(1, 10000, "Entrez une valeur entiere");
    printf("DateEntre           :");
    strcpy(Book.DateEntre, Today());
    strcpy(Book.DateSortie, "");
    strcpy(Book.DateRetour, "");
    Book.CodeEmp = 0;
    strcpy(Book.NomEmp, "");
    strcpy(Book.PrenomEmp, "");
    Book.Statut = 1;

    Book.Code = 1 + GetLastID(3);
    system("clear");
    printf("Code                :%d\n", Book.Code);
    printf("Categorie           :%s\n", Book.Categorie);
    printf("Titre               :%s\n", Book.Titre);
    printf("Edition             :%s\n", Book.Edition);
    printf("AnneeEdition        :%d\n", Book.AnneeEdition);
    printf("Auteur 1            :%s\n", Book.Auteur1);
    printf("Auteur 2            :%s\n", Book.Auteur2);
    printf("NbPage              :%d\n", Book.NbPage);
    printf("DateEntre           :%s\n", Book.DateEntre);
    // open file for writing
    outfile = fopen("Ouvrage.bin", "ab");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nErreur dans l'ouverture du fichier\n");
        exit(1);
    }
    // write struct to file
    fwrite(&Book, sizeof(struct Ouvrage), 1, outfile);
    // close file
    fclose(outfile);
}

int AfficherUnLivre()
{
    FILE *infile;
    struct Ouvrage Book;
    int choix;
    printf("Entrez le code du livre a rechercher : ");
    choix = Choix(1, 10000, "Veuillez verifier le format du code");

    infile = fopen("Ouvrage.bin", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nErreur d'ouverture du fichier\n");
        exit(1);
    }
    headMessage("DETAILS SUR UN LIVRE");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");

    while (fread(&Book, sizeof(struct Ouvrage), 1, infile))
    {
        if (choix == Book.Code)
        {
            printf("Categorie           :%s\n", Book.Categorie);
            printf("Titre               :%s\n", Book.Titre);
            printf("Edition             :%s\n", Book.Edition);
            printf("AnneeEdition        :%d\n", Book.AnneeEdition);
            printf("Auteur 1            :%s\n", Book.Auteur1);
            printf("Auteur 2            :%s\n", Book.Auteur2);
            printf("NbPage              :%d\n", Book.NbPage);
            printf("DateEntre           :%s\n", Book.DateEntre);
            fclose(infile);
            return 1;
        }
    }

    printf("Le livre n'est pas a la bibliotheque.");

    fclose(infile);
    return 0;
}

int AfficherUnCours()
{
    FILE *infile;
    struct Cours NewCourse;
    int choix;
    printf("Entrez le code du cours a rechercher : ");
    choix = Choix(1, 10000, "Veuillez verifier le format du code");

    infile = fopen("Cours.bin", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nErreur d'ouverture du fichier\n");
        exit(1);
    }
    headMessage("DETAILS SUR UN COURS");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");

    while (fread(&NewCourse, sizeof(struct Cours), 1, infile))
    {
        if (choix == NewCourse.Code)
        {
            printf("Titre               :%s\n", NewCourse.Titre);
            printf("Faculte             :%s\n", NewCourse.Faculte);
            printf("Type                :%s\n", NewCourse.Type);
            printf("Nombre de Credit    :%d\n", NewCourse.NbCredit);
            printf("Professeur 1        :%s\n", NewCourse.Prof1);
            printf("Professeur 2        :%s\n", NewCourse.Prof2);
            fclose(infile);
            return 1;
        }
    }

    printf("Ce cours n'a pas ete enregistre");

    fclose(infile);
    return 0;
}

int AfficherCours()
{
    FILE *infile;
    struct Cours NewCourse;

    infile = fopen("Cours.bin", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nErreur d'ouverture du fichier\n");
        exit(1);
    }
    headMessage("COURS");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");

    while (fread(&NewCourse, sizeof(struct Cours), 1, infile))
    {

        printf("Code                :%d\n", NewCourse.Code);
        printf("Titre               :%s\n", NewCourse.Titre);
        printf("Faculte             :%s\n", NewCourse.Faculte);
        printf("Type                :%s\n", NewCourse.Type);
        printf("Nombre de Credit    :%d\n", NewCourse.NbCredit);
        printf("Professeur 1        :%s\n", NewCourse.Prof1);
        printf("Professeur 2        :%s\n", NewCourse.Prof2);

        printf("------------------------------------------------------------------------------------\n");
    }

    fclose(infile);
    return 0;
}

int AfficherLivre()
{
    FILE *infile;
    struct Ouvrage Book;

    infile = fopen("Ouvrage.bin", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nErreur d'ouverture du fichier\n");
        exit(1);
    }
    headMessage("LES LIVRES DE L'UNIVERSITE");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    while (fread(&Book, sizeof(struct Ouvrage), 1, infile))
    {
        printf("Code                :%d\n", Book.Code);
        printf("Categorie           :%s\n", Book.Categorie);
        printf("Titre               :%s\n", Book.Titre);
        printf("Edition             :%s\n", Book.Edition);
        printf("AnneeEdition        :%d\n", Book.AnneeEdition);
        printf("Auteur 1            :%s\n", Book.Auteur1);
        printf("Auteur 2            :%s\n", Book.Auteur2);
        printf("NbPage              :%d\n", Book.NbPage);
        printf("DateEntre           :%s\n", Book.DateEntre);
        printf("------------------------------------------------------------------------------------\n");
    }

    fclose(infile);
    return 0;
}

int AfficherEtudiant()
{
    FILE *fichier;
        FILE *fichier_etudiant;
    struct User student ;
    struct Etudiant etu;

    fichier = fopen("Utilisateur.bin", "rb");
    fichier_etudiant=fopen("Etudiant.bin", "rb");
    if (fichier == NULL || fichier_etudiant==NULL )
    {
        fprintf(stderr, "\nErreur d'ouverture du fichier\n");
        exit(1);
    }
    headMessage("LES ETUDIANTS DE L'UNIVERSITE");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    while (fread(&student, sizeof(struct User), 1, fichier))
    {
        if (student.Module==2){

        printf("Code                :%d\n", student.Code);
        printf("NIF                 :%s\n", student.NIF);
        printf("Nom                 :%s\n", student.Nom);
        printf("Prenom              :%s\n", student.Prenom);
        }


    }
    while (fread(&etu, sizeof(struct Etudiant), 1, fichier_etudiant))
    {

        printf("Faculte             :%s\n", etu.Faculte);
        printf("Section             :%s\n", etu.Section);
        printf("Session             :%d\n", etu.Session);
        printf("Anne admission      :%d\n", etu.AnneeAdm);

        printf("------------------------------------------------------------------------------------\n");
    }

    fclose(fichier);
    fclose(fichier_etudiant);
    return 0;
}

int AfficherProfesseur()
{
    FILE *fichier;
        FILE *fichier_prof;
    struct User prof ;
    struct Professeur professeur;

    fichier = fopen("Utilisateur.bin", "rb");
    fichier_prof=fopen("Professeur.bin", "rb");
    if (fichier == NULL || fichier_prof==NULL )
    {
        fprintf(stderr, "\nErreur d'ouverture du fichier\n");
        exit(1);
    }
    headMessage("LES PROFESSEURS DE L'UNIVERSITE");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    while (fread(&prof, sizeof(struct User), 1, fichier))
    {
        if (prof.Module==3){

        printf("Code                :%d\n", prof.Code);
        printf("NIF                 :%s\n", prof.NIF);
        printf("Nom                 :%s\n", prof.Nom);
        printf("Prenom              :%s\n", prof.Prenom);
        }


    }
    while (fread(&professeur, sizeof(struct Professeur), 1, fichier_prof))
    {

        printf("Faculte             :%s\n", professeur.Faculte);
        printf("Section             :%s\n", professeur.Section);
        printf("Type                :%s\n", professeur.Type);
        printf("Nombre de cours     :%d\n", professeur.Nbcours);
        printf("Cours               :%s\n", professeur.Cours);
        printf("------------------------------------------------------------------------------------\n");
    }

    fclose(fichier);
    fclose(fichier_prof);
    return 0;
}

int AfficherBibliothecaire()
{
    FILE *fichier;
        FILE *fichier_biblio;
    struct User biblio ;
    struct Bibliothecaire bibliothecaire;

    fichier = fopen("Utilisateur.bin", "rb");
    fichier_biblio=fopen("Bibliothecaire.bin", "rb");
    if (fichier == NULL || fichier_biblio==NULL )
    {
        fprintf(stderr, "\nErreur d'ouverture du fichier\n");
        exit(1);
    }
    headMessage("LES BIBLIOTHECAIRES DE L'UNIVERSITE");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    while (fread(&biblio, sizeof(struct User), 1, fichier))
    {
        if (biblio.Module==6){

        printf("Code                :%d\n", biblio.Code);
        printf("NIF                 :%s\n", biblio.NIF);
        printf("Nom                 :%s\n", biblio.Nom);
        printf("Prenom              :%s\n", biblio.Prenom);
        }


    }
    while (fread(&bibliothecaire, sizeof(struct Bibliothecaire), 1, fichier_biblio))
    {

        printf("Affectation         :%s\n", bibliothecaire.Affectation);
        printf("Niveau              :%s\n", bibliothecaire.Niveau);
        printf("Annee               :%d\n", bibliothecaire.Annee);
        printf("Superieur           :%s\n", bibliothecaire.Superieur);

        printf("------------------------------------------------------------------------------------\n");
    }

    fclose(fichier);
    fclose(fichier_biblio);
    return 0;
}

int AfficherPersonnelAdministratif()
{
    FILE *fichier;
        FILE *fichier_personnel;
    struct User personnel;
    struct PersonnelAdministratif personnelAdm;

    fichier = fopen("Utilisateur.bin", "rb");
    fichier_personnel=fopen("PersonnelAdministratif.bin", "rb");
    if (fichier == NULL || fichier_personnel==NULL )
    {
        fprintf(stderr, "\nErreur d'ouverture du fichier\n");
        exit(1);
    }
    headMessage("LES AGENTS AADMINISTRATIFS DE L'UNIVERSITE");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    while (fread(&personnel, sizeof(struct User), 1, fichier))
    {
        if (personnel.Module==5){

        printf("Code                :%d\n", personnel.Code);
        printf("NIF                 :%s\n", personnel.NIF);
        printf("Nom                 :%s\n", personnel.Nom);
        printf("Prenom              :%s\n", personnel.Prenom);
        }


    }
    while (fread(&personnelAdm, sizeof(struct PersonnelAdministratif), 1, fichier_personnel))
    {

        printf("Affectation         :%s\n", personnelAdm.Affectation);
        printf("Poste               :%s\n", personnelAdm.Poste);
        printf("Annee               :%d\n", personnelAdm.Annee);
        printf("Superieur           :%s\n", personnelAdm.Superieur);

        printf("------------------------------------------------------------------------------------\n");
    }

    fclose(fichier);
    fclose(fichier_personnel);
    return 0;
}

int AfficherAdministrateur()
{
    FILE *fichier;
    struct User admin ;

    fichier = fopen("Utilisateur.bin", "rb");
       if (fichier == NULL)
    {
        fprintf(stderr, "\nErreur d'ouverture du fichier\n");
        exit(1);
    }
    headMessage("LES ADMINISTRATEURSS DE L'UNIVERSITE");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    while (fread(&admin, sizeof(struct User), 1, fichier))
    {
        if (admin.Module==1){

        printf("Code                :%d\n", admin.Code);
        printf("NIF                 :%s\n", admin.NIF);
        printf("Nom                 :%s\n", admin.Nom);
        printf("Prenom              :%s\n", admin.Prenom);
        }

        printf("------------------------------------------------------------------------------------\n");
    }


    fclose(fichier);
    return 0;
}
int AfficherCategorie()
{
    FILE *infile;
    struct Ouvrage Book;

    infile = fopen("Ouvrage.bin", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nErreur d'ouverture du fichier\n");
        exit(1);
    }
    //printf("Categories\n");
    headMessage("CATEGORIES");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");

    while (fread(&Book, sizeof(struct Ouvrage), 1, infile))
    {
        printf("%s\n", Book.Categorie);
    }
    fclose(infile);
    return 0;
}
char *GetString2()
{

    static char input[100];
    //fflush(stdin);
   // __fpurge(stdin);
   jsw_flush();
    fgets(input, 100, stdin);
    strtok(input, "\n");
    return input;
}


char * GetPassword() {
  static char password[128];
  unsigned long we;
  char c;
   int index = 0;

   /* 13 is ASCII value of Enter key */
   while((c = getch()) != 13){
       if(index < 0)
           index = 0;
       /* 8 is ASCII value of BACKSPACE character */
       if(c == 8){
           putch('\b');
           putch(NULL);
           putch('\b');
           index--;
       continue;
       }
       password[index++] = c;
       putch('*');
   }
   password[index] = '\0';
	//we = hash(password);
	//strcpy(password,"");
	//sprintf(password,"%ld",we);
   return password;
}


int GetAccess (  )
//returns the module ,ie access level
{
	FILE *infile;
	struct User input;

	char code[100];
	int user,id, val ;
    //clearWindow();

        //print_heading("Connection");
        headMessage("Connexion");
        printf("\n");

        printf("Code Utilisateur  : ");
        val = scanf("%d",&id);

        printf("Mot de Passe      : ");

        strcpy(code,GetPassword());
        if (val == 0)
        {
            printf("ID ou mot de Passe incorrect");
            printf("Pressez 'Enter' pour reesayer");
            getch();
            GetAccess();
            return 0;
        }



	infile = fopen ("Utilisateur.bin", "rb");
	if (infile == NULL)
	{
		fprintf(stderr, "\nError opening file\n");
		exit (1);
	}

	while(fread(&input,sizeof(struct User), 1, infile))
	{


		if (id ==input.Code )
		{
			if (strcmp(code, input.Password)== 0)
			{
               // clearWindow();
				//return input.Module;
				main_window(input.Module);
			}
		}

	}
            printf("\nID ou mot de Passe incorrect\n");
            printf("Pressez 'Enter' pour reesayer");
            getch();
	 GetAccess();
		return 0;
}


//Logique lan c que map gade si livre lan la ,
// int ModifierCours()
// {
//       int choix=0;
//       struct Cours ModedCourse;

//  FILE *infile;
//     struct Cours NewCourse;
//     int choix;
//     printf("Entrez le code du cours a modifier : ");
//     choix = Choix(1, 10000, "Veuillez verifier le format du code");

//     infile = fopen("Cours.bin", "rb");
//     if (infile == NULL)
//     {
//         fprintf(stderr, "\nErreur d'ouverture du fichier\n");
//         exit(1);
//     }

//     while (fread(&NewCourse, sizeof(struct Cours), 1, infile))
//     {
//         if (choix == NewCourse.Code)
//         {
//             printf("Titre               :%s\n", NewCourse.Titre);
//             printf("Faculte             :%s\n", NewCourse.Faculte);
//             printf("Type                :%s\n", NewCourse.Type);
//             printf("Nombre de Credit    :%d\n", NewCourse.NbCredit);
//             printf("Professeur 1        :%s\n", NewCourse.Prof1);
//             printf("Professeur 2        :%s\n", NewCourse.Prof2);
//             fclose(infile);
//             return 1;
//         }
//     }

//     printf("Ce cours n'a pas ete enregistre");

//     fclose(infile);
//     return 0;
// }









// //    choix = AfficherUnCours();

// //    if (choix == 0) //sil pa jwenn li
// //    return 0;
//    do{
//     printf("\nChoissir le champs a mofifier\n");
//     printf("1 :Titre  2 :Nombre de credit 3 :Professeur 1  4 :Professeur 2  5 :Sotir\n>>");
//     choix = Choix(1,5,"Choisissez parmis la liste");
//     switch (choix)
//     {
//     case 1:
//         printf("Entrez le nouveau titre :");
//         strcpy(ModedCourse.Titre,GetString());
//         break;
//     case 2:
//         printf("Entrez le nombre de credit :");
//         ModedCourse.NbCredit=Choix(1,20,'Choisissez entre 1 et 20');

//         break;
//         case 3:
//         printf("Entrez le Professeur 1:");
//         strcpy(ModedCourse.Prof1,GetString());
//         break;
//      case 4:
//         printf("Entrez le Professeur 2:");
//         strcpy(ModedCourse.Prof2,GetString());
//         break;
//     }
//    }
//    while (choix !=5);

//    printf("We are out");


// }

void Report (int fileCode)
{
    FILE *fichier,*tempon;
	struct User us;


    fichier = fopen ("Utilisateur.bin", "rb");
    tempon = fopen("Report.txt","w");
	if (fichier == NULL)
	{
		fprintf(stderr, "\nError opening file\n");
		exit (1);
	}
	fprintf(tempon,"Code\tPrenom\tNom\t\n");

	while(fread(&us,sizeof(struct User), 1, fichier))
    {
        if (us.Module == fileCode)
        {
            fprintf(tempon,"%d\t\t%s\t\t%s\n",us.Code,us.Prenom,us.Nom);
        }

    }
    fclose(fichier);
    fclose(tempon);
    switch (fileCode)
    {
    case 0:
        rename("Report.txt","ReportAdmin.txt");
        break;
    case 1:
        rename("Report.txt","ReportEtudiant.txt");
        break;
    case 2:
        rename("Report.txt","ReportProfesseurs.txt");
        break;
    case 3:
        rename("Report.txt","ReportPersonnelAdministratif.txt");
        break;
    case 4:
        rename("Report.txt","ReportBibliothecaire.txt");
        break;
    }

}

int CheckUserAvailability (int id)
{
    FILE *fichier;

    struct User user;

    fichier = fopen ("Utilisateur.bin", "rb");

    if (fichier == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    while(fread(&user,sizeof(struct User), 1, fichier))
    {


        if(id == user.Code)
        {
            fclose (fichier);

            return id;
        }

    }

    fclose (fichier);
    return 0;

}

int ChangePassword(int id)
{
    struct User user;
    FILE *fichier,*temp;

    fichier = fopen ("Utilisateur.bin", "rb");
    temp = fopen ("Temp.bin", "ab");

    if (fichier == NULL || temp == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    while(fread(&user,sizeof(struct User), 1, fichier))
    {
        if (id == user.Code)
        {
            printf("Entrez le nouveau mot de passe ");
            strcpy(user.Password,GetPassword()) ;
        }
        fwrite(&user,sizeof(struct User), 1, temp) ;

    }

    fclose (fichier);
    fclose(temp);
    remove("Utilisateur.bin");
    rename("Temp.bin","Utilisateur.bin");
    printf("                                                           ");
    printf("Succes!Pressez 'Entrer' pour continuer");
    getch();
    printf("                                                   ");
    return 0;

}

void GestionAcces(int choix)
{
    switch(choix)
        {

        case 3:
            printf("Liste Administrateurs \n");
            AfficherAdministrateur();
            Report(0);
            break;
        case 6:
            printf("Liste Etudiants \n");
            AfficherEtudiant();
            Report(1);
            break;
        case 7:
            printf("Liste Professeurs \n");
            AfficherProfesseur();
            Report(2);
            break;
        case 4:
            printf("Liste Personnel Administratif \n");
            AfficherPersonnelAdministratif();
            Report(3);
            break;

        case 5:
             printf("Liste Bibliothecaire \n");
            AfficherBibliothecaire();
            Report(4);
            break;
        case 2:
             printf("Modifier Mot de Passe \n");
             printf("Entrez le Code de l'utilisateur : \n");

             int test2;
              test2 = Choix(1,9999,"Verifiez le format du Code!");

              if (CheckUserAvailability (test2)== 0)
              {
                printf("Cet Utilisateur n'est pas dans la base de donnees\n");

              }
              else
              {

                 ChangePassword(test2);
              }


            break;
            case 1:
                AjouterUtilisateur ();

            break;

        }

         printf("Pressez 'Enter' pour retourner");
        getch();
        printf("                                                           ");
        printf("                                                      ");



}

void GestionCours(int choix)
{
 int k=0;
    switch(choix)
    {

    case 1:
        AfficherCours(0);
        break;
    case 2:

        printf("Veuillez entrer le code du cours : \n");
        k = Choix(1,9999,"Verifiez le format du code");
        AfficherCours(k);
        break;
    case 3:
        AjouterCours();
        printf("                                                                       ");

        break;
    case 4:
            printf("Veuillez entrer le code du cours a modifier: ");
            k = Choix(1,9999,"Verifiez le format du code");
            //modifierCours(cod);
        break;

    }
    printf("Pressez 'Enter' pour retourner");
    getch();
    printf("                                 ");
}

struct NomComplet getFullName(int code)
{
    FILE *infile;

    struct NomComplet user;
    struct User input;

    infile = fopen("Utilisateur.bin", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }

    while (fread(&input, sizeof(struct User), 1, infile))
    {
        if (code = input.Code)
        {
            strcpy(user.prenom, input.Prenom);
            strcpy(user.nom, input.Nom);
            fclose(infile);
            return user;
        }
    }
}
int CheckBookAvailable(int code)
{
    FILE *fichier;

    struct Ouvrage saisi;

    fichier = fopen("Ouvrage.bin", "rb");
    if (fichier == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }

    while (fread(&saisi, sizeof(struct Ouvrage), 1, fichier))
    {

        if (code == saisi.Code)
        {
            if (saisi.Statut == 0)
            {
                printf("Le livre a retourner est:%s", saisi.Titre);
                fclose(fichier);
                return 1;
            }
            else
            {
                printf("Ce livre a deja ete retourne !");
                return 0;
            }
        }

    }
     printf("Le livre  n'est pas a la bibliotheque.");

    return 0;
}

int Emprunt(int codeUser, int codeBook)
{
    int test;
    struct NomComplet user;
    struct Ouvrage book;
    test = CheckBookAvailable(codeBook);
    if (test==0)
    {
         printf("Erreur durant l'operation d'emprunt!");
        return 0;
    }
    user = getFullName(codeUser);

    FILE *infile,*temp;

	infile = fopen ("Ouvrage.bin", "rb");
    temp = fopen ("Temp.bin", "ab");

	if (infile == NULL || temp == NULL)
	{
		fprintf(stderr, "\nError opening file\n");
		exit (1);
	}

	while(fread(&book,sizeof(struct Ouvrage), 1, infile))
    {
        if (book.Code == codeBook)
        {
            strcpy(book.PrenomEmp,user.prenom);
            strcpy(book.NomEmp,user.nom);
            book.CodeEmp = codeUser;
            strcpy(book.DateSortie, Today());
            book.Statut = 0;
            printf("Emprunt reussi!");
        }
       fwrite(&book,sizeof(struct Ouvrage), 1, temp) ;

    }

	fclose (infile);
    fclose(temp);
    remove("Ouvrage.bin");
    rename("Temp.bin","Ouvrage.bin");
    printf("                                                                           ");
}

int Restitution (int codeUser ,int codeBook)
{
     int test;
    struct Ouvrage livre;
    test = CheckBookAvailable(codeBook);
    if (test==0)
    {
        printf("Erreur durant l'operation d'emprunt!");
        return 0;
    }

    FILE *fichier,*tempon;

	fichier = fopen ("Ouvrage.bin", "rb");
    tempon = fopen ("Temp.bin", "ab");

	if (fichier == NULL || tempon == NULL)
	{
		fprintf(stderr, "\nError opening file\n");
		exit (1);
	}

	while(fread(&livre,sizeof(struct Ouvrage), 1, fichier))
    {
        if (livre.Code == codeBook)
        {
            strcpy(livre.PrenomEmp,"");
            strcpy(livre.NomEmp,"");
            livre.CodeEmp = 0;
            strcpy(livre.DateRetour, Today());
            livre.Statut = 1;
            printf("Retour reussi!");
        }
       fwrite(&livre,sizeof(struct Ouvrage), 1, tempon) ;

    }

	fclose (fichier);
    fclose(tempon);
    remove("Ouvrage.bin");
    rename("Temp.bin","Ouvrage.bin");
    printf("                                                                           ");


}

void GestionBibliotheque(int id ,int choix)
{
 int k=0;
    switch(choix)
    {

    case 1:
        AfficherLivre();
        break;
    case 2:
         AfficherLivre();
        break;
    case 3:
        AjouterLivre();
        break;
    case 4:
        printf("Entrez le code du livre : \n");
        k = Choix(1,99999,"Verifiez le format du code\n");
        printf("                                                             ");

        Emprunt(id, k);
        break;
        case 5:
        printf("Entrez le code du livre : \n");
        k = Choix(1,99999,"Verifiez le format du code\n");
        printf("                                                             ");

        Restitution(id, k);
        break;

    }
    printf("                                                                                                                                       ");
    printf("Pressez 'Enter' pour retourner");
    getch();
    printf("                                 ");

    }



int main_window(int id)
{
    int choice;
    int code =0;
    int x = 2;
        headMessage("GESTION DE L'UNIVERSITE");
        //printf("\t\t\t\t\t\t\t\t\t[code utilisateur: %d]",id);
        printf("\n\t\t\t---------------------------------------------------------------------------\n");
        printf("1. Gestion des acces\n");
        printf("2. Cours\n");
        printf("3. Administration et Comptabilite\n");
        printf("4. Bibliotheque\n");
        printf("5. Quitter le programme\n");
        printf("Faites votre choix\n");
        printf(">>");
        choice = Choix(1,5,"Veuillez choisir entre 1 et 5");
        switch(choice){
            case 1:
                 headMessage("Gestion DES ACCES");
                printf("\n");
                printf("1. Ajouter Utilisateur\n");
                printf("2. Modifier Mot de Passe\n");
                printf("3. Afficher les Administrateurs\n");
                printf("4. Afficher Agents Administratifs\n");
                printf("5. Afficher les Bibliothecaires\n");
                printf("6. Afficher les Etudiants\n");
                printf("7. Afficher les Professeurs\n");
                printf("8. Sortir\n");
                printf("Faites votre choix\n ");
                printf(">>");
        choice = Choix(1,8,"Veuillez choisir entre 1 et 8");
                if (choice == 8)main_window(id);
        if (id != 1)
        {
            printf("Module reserve aux administrateurs !\n");
            printf("Pressez 'Enter' pour retourner\n");
            getch();
            printf("                                                           ");
            printf("                                                           ");
            main_window(id);
        }
                //print_heading("Gestion des acces");

                GestionAcces(choice);main_window(id);
                break;
            case 2:
                 headMessage("Gestion DES COURS");
                printf("\n");
                printf("1. Afficher les cours\n");
                printf("2. Afficher les infos d'un cours\n");
                printf("3. Ajouter un cours\n");
                printf("4. Modifier un cours\n");
                printf("5. Sortir\n");
                printf("Faites votre choix \n");
                printf(">>");
        choice = Choix(1,5,"Veuillez choisir entre 1 et 5");

         if (id != 1)
        {
            if (choice == 3 || choice == 4)
            {
            printf("Module reserve aux administrateurs !\n");
            printf("Pressez 'Enter' pour retourner\n");
            getch();
            printf("                                                           ");
            printf("                                                           ");
            main_window(id);
            }

        }

              //  headMessage("GESTION DES COURS");
                //printf("\n\t\t\t---------------------------------------------------------------------------\n");
                if (choice == 5)main_window(id);
                GestionCours(choice);main_window(id);

                return 0;
                break;
            case 3:
                 headMessage("ADMINISTRATION/COMPTABILITE");
                printf("\n");
                printf("1. Gestion des Professeurs\n");
                printf("2. Gestion des Etudiants\n");
                printf("3. Gestion du Personnel\n");
                printf("4. Modifier un cours\n");
                printf("5. Sortir\n");
                printf("Faites votre choix\n ");
                printf(">>");
        choice = Choix(1,5,"Veuillez choisir entre 1 et 5");
        if (id != 1 )
        {

            printf("Module reserve aux administrateurs !\n");
            printf("Pressez 'Enter' pour retourner\n");
            getch();
            printf("                                                           ");
            printf("                                                           ");
            main_window(id);


        }
        //headMessage("ADMINISTRATION/COMPTABILITE");
        //printf("\n\t\t\t---------------------------------------------------------------------------\n");

         //GAdminPerson (id ,choice);
         main_window(id);
                return 0;
                break;
            case 4:
                headMessage("BIBLIOTHEQUE");
                printf("\n");
                printf("1. Afficher les categories\n");
                printf("2. Afficher les ouvrages\n");
                printf("3. Ajouter un ouvrage\n");
                printf("4. Emprunter un ouvrage\n");
                printf("5. Retourner un ouvrage\n");
                printf("6. Sortir\n");
                printf("Faites votre choix : \n");
                choice = Choix(1,6,"Veuillez choisir entre 1 et 6\n");
                if (choice ==3 || choice==4 || choice==5 )
                {
                    if (id !=6)
                    {
                      printf("Module reserve aux bibliothecaires !\n");
                        printf("Pressez 'Enter' pour retourner");
                        getch();
                        printf("                                                           ");
                        printf("                                                           ");
                        main_window(id);
                    }
                }
              //   headMessage("BIBLIOTHEQUE");
                // printf("\n\t\t\t---------------------------------------------------------------------------\n");
                 GestionBibliotheque(id ,choice);main_window(id);
                return 0;
                break;
               //Leave
            case 5 :
                headMessage("AU REVOIR");
                printf("\n\t\t\t---------------------------------------------------------------------------\n");
                exit(1);


        }



}

