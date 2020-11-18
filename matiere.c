#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "principal.h"
#include <unistd.h>


int i, n, nb, j, choix, netudiant;
typedef struct matiere matiere;
struct matiere
{
    int reference , coef;
    char libelle[30];
};

matiere t;
matiere *tM;

void saisieUneMatiere()

{

    printf("\n\n");
    printf("Saisir les information de la matiere :  ");
    printf("reference de la matiere : ");
    scanf("%d", &t.reference);
    printf("Libelle : ");
    scanf("%s", t.libelle);
    printf("Coefficient : ");
    scanf("%d", &t.coef);
        FILE *fic = fopen("matiere.csv", "a+");
    if(fic==NULL)
    exit(1);
    fprintf(fic,"%d,%s,%d\n",t.reference, t.libelle,t.coef);
    fclose(fic);
    n = n + 1;
}

void saisiePlusieursMatiere()
{
    printf("Entrer le nombre de matiere que vous voulez : ");
    scanf("%d", &nb);
    printf("\n\n");

    for (i = 1; i <= nb; i++)
    {
        printf("Saisir les information de la matiere:  \n\n" );
        printf("Reference : ");
        scanf("%d", &t.reference);
        printf("Libelle: ");
        scanf("%s", t.libelle);
        printf("Coefficient : ");
        scanf("%d", &t.coef);
                FILE *fic = fopen("matiere.csv", "a+");
    if(fic==NULL)
    exit(1);
    fprintf(fic,"%d,%s,%d\n",t.reference, t.libelle,t.coef);
    fclose(fic);
        n = n + 1;
    }
}

void afficherMatiere()
{
    int lettre;
    FILE *fic = fopen("matiere.csv", "r");
    if(fic==NULL)
    exit(1);
  
  while((lettre = fgetc(fic))!=EOF){
      printf("%c",lettre);

  }
  fclose(fic);
}


void rechercheMatiere()
{
    int num;
    printf(" Saisir une reference : ");
    scanf("%d", &num);

    for (i = 1; i <= n; i++)
    {

        if (tM[i].reference == num)
        {
            printf(" Information etudie : \n");
            printf("Refernce  numero : %d\n", num);
            printf("Reference : %d\n", tM[i].reference);
            printf("Prenom : %s\n", tM[i].libelle);
            printf("Email : %d\n", tM[i].coef);
        }
      
    }
}

void modifierMatiere(){
     int num,k;
     printf("Saisir la refernce de la matiere que vous voulez modifier  : ");
     scanf("%d",&num);

     for(i=1;i<=n;i++){
           if(tM[i].reference==num){
                   k=i;
      }}
    printf("Reference : ");
    scanf("%d",&tM[k].reference);
    printf("Libelle : ");
    scanf("%s",tM[k].libelle);
    printf("coefficient : ");
    scanf("%d",&tM[k].coef);

    
 }

 void supprimerMatiere(){

     int j,num,k;
     printf("Saisir la refernce de la matiere: ");
     scanf("%d",&num);

     for(i=1;i<=n;i++){
         if(tM[i].reference==num){
                k=i;
                n=n-1;
                for(j=k;j<=n;j++){
                            tM[j]=tM[j+1];
                 }
     }}}


void menuMatiere(){
    int choi;
    printf("+_+_+_+_+ Gestion des matieres  +_+_+_+_+\n");
    printf("1.Saisir une matiere\n");
    printf("2.Saisir plusieurs matieres\n");
    printf("3.liste des matieres\n");
    printf("4.Rechercher une matiere \n");
    printf("5. Modifier une matiere\n");
    printf("6.Supprimer une matiere\n");
    printf("7. precedent\n");
    printf("Que voulez vous faire: \n");
    printf(">");
    scanf("%d", &choi);
    printf("\n\n");
    switch (choi)
    {
    case 1:
        saisieUneMatiere();
        break;
    case 2:
        saisiePlusieursMatiere();
        break;
    case 3:
        afficherMatiere();
        break;
    case 4:
        rechercheMatiere();
        break;
    case 5:
        modifierMatiere();

        break;
    case 6:
        supprimerMatiere();
        break;
    case 7:
        menuPrincipal();
        break;
    default:
        printf("votre choix n'est pas valide !!!\n");
           }


 }