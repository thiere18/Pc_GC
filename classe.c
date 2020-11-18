#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "principal.h"
#include <unistd.h>

int i, n, nb, j, choix, netudiant;
typedef struct classe classe;

struct classe
{
    int code;
    char nom[30];
    enum nivea{ licence,master }
    niveau;
};
 classe t;
 classe *tc;
 void saisieUneClasse()
 {

     printf("\n\n");
     printf("Saisir les informations de la classe :  ");
     printf("Code : ");
     scanf("%d", &t.code);
     printf("Nom : ");
     scanf("%s", t.nom);
     printf("Prenom : ");
     scanf("%u", &t.niveau);

     n = n + 1;
     printf("\n\n");
}

void saisiePlusieursClasse()
{
    printf("Entrer le nombre de classe que vous voulez saisir : ");
    scanf("%d", &nb);
    printf("\n\n");

    for (i = 1; i <= nb; i++)
    {

        printf("Saisir les information de la classe :  \n\n" );
        printf("Code classe : ");
        scanf("%d", &t.code);
        printf("Nom : ");
        scanf("%s", t.nom);
        printf("Niveau : ");
        scanf("%u", &t.niveau);
        
        n = n + 1;
    }
}

void afficherClasse()
{
    int lettre;
    FILE *fic = fopen("classe.csv", "r");
    if(fic==NULL)
    exit(1);
  
  while((lettre = fgetc(fic))!=EOF){
      printf("%c",lettre);

  }
  fclose(fic);
}
void rechercheClasse()
{
    int num;
    printf(" Saisir un code : ");
    scanf("%d", &num);

    for (i = 1; i <= n; i++)
    {


        if (t.code == num)
        {
            printf(" Information classe : \n");
            printf("Code : %d\n", num);
            printf("Nom : %s\n", t.nom);
            printf("Niveau : %u\n", t.niveau);
            
        }
    }
}

void modifierClasse()
{
    int num, k;
    printf("Saisir le code de la classe que vous voulez modifer : ");
    scanf("%d", &num);

    for (i = 1; i <= n; i++)
    {
        if (t.code== num)
        {
            k = i;
        }
    }
    printf("Code : ");
    scanf("%d", &tc[k].code);
    printf("Nom : ");
    scanf("%s", tc[k].nom);
    printf("Niveau : ");
    scanf("%u", &tc[k].niveau);
 
}

void supprimerClasse()
{

    int j, num, k;
    printf("Saisir le code  : ");
    scanf("%d", &num);

    for (i = 1; i <= n; i++)
    {
        if (t.code == num)
        {
            k = i;
            n = n - 1;
            for (j = k; j <= n; j++)
            {
                tc[j] = tc[j + 1];
            }
        }
    }
}

void menuClasse()
{
    
    
        printf("_+_+_+_+ Gestion des Classe +_+_+_+_\n");
        printf("1.Saisir une classe\n");
        printf("2.Saisir plusieurs classe\n");
        printf("3.liste des classes\n");
        printf("4.Rechercher une classe \n");
        printf("5. Modifier une classe \n");
        printf("6.Supprimer une classe \n");
        printf("7. precedent");
        printf("Que voulez vous faire\n");
                printf(">");
        scanf("%d", &choix);
        printf("\n\n");
        switch (choix)
        {
        case 1:
            saisieUneClasse();
            break;
        case 2:
            saisiePlusieursClasse();
            break;
        case 3:
            afficherClasse();
            break;
        case 4:
            rechercheClasse();
            break;
        case 5:
            modifierClasse();

            break;
        case 6:
            supprimerClasse();
            break;
        case 7:
            menuPrincipal();
            break;
        default:
            printf("votre choix n'est pas valide !!!\n");
        }

}