#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "principal.h"
#include <unistd.h>

int i, n, nb, j, choix;
char* ligne = NULL;
char strId[200];
struct etudiants
{
    int numero;
    char nom[30], prenom[30], email[30], date_naissance[30];
};
typedef struct etudiants etudiants;
etudiants e;
etudiants *te;
void saisieUneEtudiant()
{

    printf("\n\n");
    printf("Saisir les informations de votre etudiant :  ");
    printf("Numero etudiant : ");
    scanf("%d", &e.numero);
    printf("Nom : ");
    scanf("%s", e.nom);
    printf("Prenom : ");
    scanf("%s", e.prenom);
    printf("Email : ");
    scanf("%s", e.email);
    printf("Date de naissance: ");
    scanf("%s", e.date_naissance);
    FILE *fic = fopen("etudiant.csv", "a+");
    if (fic == NULL)
        exit(1);
    fprintf(fic, "%d,%s,%s,%s,%s\n", e.numero, e.nom, e.prenom, e.email, e.date_naissance);
    fclose(fic);
    n = n + 1;
    printf("\n\n");
}

void saisiePlusieursEtudiants()
{
    printf("Entrer le nombre des etudiants que vous voulez saisir : ");
    scanf("%d", &nb);
    printf("\n\n");

    for (i = 1; i <= nb; i++)
    {

        printf("Saisir les information de l'etudiant numero %d :  \n\n", n + 1);
        printf("Numero etudiant : ");
        scanf("%d", &e.numero);
        printf("Nom : ");
        scanf("%s", e.nom);
        printf("Prenom : ");
        scanf("%s", e.prenom);
        printf("Email : ");
        scanf("%s", e.email);
        printf("Date naissance : ");
        scanf("%s", e.date_naissance);
        FILE *fic = fopen("etudiant.csv", "a+");
        if (fic == NULL)
            exit(1);
        fprintf(fic, "%d,%s,%s,%s,%s\n", e.numero, e.nom, e.prenom, e.email, e.date_naissance);
        fclose(fic);
        n = n + 1;
    }
}

void afficherEtudiant()
{
    int lettre;
    FILE *fic = fopen("etudiant.csv", "r");
    if (fic == NULL)
        exit(1);

    while ((lettre = fgetc(fic)) != EOF)
    {
        printf("%c", lettre);
    }
    fclose(fic);
}

// void rechercheEtudiant()
// {
//     int num;
//     printf(" Saisir un numero : ");
//     scanf("%d", &num);

//     for (i = 1; i <= n; i++)
//     {

//         if (te[i].numero == num)
//         {
//             printf(" Information etudie : \n");
//             printf("Numero : %d\n", num);
//             printf("Nom : %s\n", te[i].nom);
//             printf("Prenom : %s\n", te[i].prenom);
//             printf("Email : %s\n", te[i].email);
//             printf("Date naissance : %s\n", te[i].date_naissance);
//         }
//     }
// }

void modifierEtudiant()
{
    int num, k;
    printf("Saisir le numero de l'etudiant que vous voulez modifier  : ");
    scanf("%d", &num);

    for (i = 1; i <= n; i++)
    {
        if (te[i].numero == num)
        {
            k = i;
        }
    }
    printf("Numero : ");
    scanf("%d", &te[k].numero);
    printf("Nom : ");
    scanf("%s", te[k].nom);
    printf("Prenom : ");
    scanf("%s", te[k].prenom);
    printf("Email : ");
    scanf("%s", te[k].email);
    printf("Date naissance : ");
    scanf("%s", te[k].date_naissance);
}

void supprimerEtudiant()
{

    int j, num, k;
    printf("Saisir le numero  : ");
    scanf("%d", &num);

    for (i = 1; i <= n; i++)
    {
        if (te[i].numero == num)
        {
            k = i;
            n = n - 1;
            for (j = k; j <= n; j++)
            {
                te[j] = te[j + 1];
            }
        }
    }
}



void rechercheEtudiant()
{
    int num, ret;
   char va[200], nu[200];
    printf("N° Etudiant à rechercher : \n");
    scanf("%d", &num);
    FILE *fic = fopen("etudiant.csv", "r+");
    ret = 0;
    while (fgets(va, 200, fic) != NULL)
    {
        int i = 0;
        while (va[i] != ',')
        {
            nu[i] = va[i];
            i++;
        }
        if (e.numero == num)
        {
            ret = 1;
            printf("Etudiant trouve :\n");
            printf("%s\n", va);
        }
    }
    fclose(fic);
    if (ret == 0)
    {
        printf("Etudiant Introuvable :/\n");
    }
}

void menuEtudiant()
{

    printf("+_+_+_+_+ Gestion des etudiants +_+_+_+\n");
    printf("1.Saisir un etudiant\n");
    printf("2.Saisir plusieurs etudiants\n");
    printf("3.liste des etudiants\n");
    printf("4.Rechercher un etudiant \n");
    printf("5. Modifier un etudiant \n");
    printf("6.Supprimer un etudiant \n");
    printf("7. precedent\n");
    printf("Que voulez vous faire\n");
    printf(">");
    scanf("%d", &choix);
    printf("\n\n");
    switch (choix)
    {
    case 1:
        saisieUneEtudiant();
        break;
    case 2:
        saisiePlusieursEtudiants();
        break;
    case 3:
        afficherEtudiant();
        break;
    case 4:
        rechercheEtudiant();
        break;
    case 5:
        modifierEtudiant();

        break;
    case 6:
        supprimerEtudiant();
        break;
    case 7:
        menuPrincipal();
        break;
    default:
        printf("votre choix n'est pas valide !!!\n");
    }
}
