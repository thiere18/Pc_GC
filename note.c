#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "principal.h"

int i, n, nb, j, choix, netudiant;
typedef struct note note;

struct note
{
    int Netu , Rmat;
    float noteCC, noteDS;
};

note t;
note *tN;

void saisieNoteEtudiantUneMatiere()
{
    int ref;
    ref = t.Rmat;
    printf("Numero de l'etudiant : ");
    scanf("%d", &t.Netu);
    printf("saisir la reference de la matiere :");
    scanf("%d", &ref);
    printf("note CC :");
    scanf("%f", &tN[n+1].noteCC);
    printf("note DS :");
    scanf("%f", &tN[n+1].noteDS);
        FILE *fic = fopen("note.csv", "a+");
    if(fic==NULL)
    exit(1);
    fprintf(fic,"%d,%d,%.2f,%.2f\n",t.Netu,ref, t.noteCC,t.noteDS);
    fclose(fic);

   printf("les notes de l'etudiant %d ont ete ajoute\n",tN[n+1].Netu);
}
void modifierNote();
void supprimerNote();
void afficherNote();
void saisieAllNote()
{
    for (int i = 0; i < 3; i++)
    {
        printf("Numero de l'etudiant :");
        scanf("%d", &t.Netu);
        printf("reference matiere : ");
        scanf("%d", &t.Rmat);
        printf("Note cc : ");
        scanf("%f", &t.noteCC);
        printf("Niveau : ");
        scanf("%f", &t.noteDS);
           FILE *fic = fopen("note.csv", "a+");
    if(fic==NULL)
    exit(1);
    fprintf(fic,"%d,%d,%.2f,%.2f\n",t.Netu,t.Rmat, t.noteCC,t.noteDS);
    fclose(fic);
        n = n + 1;
    }
    printf("Les note ont ete ajoute \n");
}

void saisieNoteClasse(){
    int code;
    printf("Renseignez le code de la classe\n");
    scanf("%d", &code);
    for(int i = 0; i < code; i++){
         printf("Note cc : ");
        scanf("%f", &t.noteCC);
        printf("Note DS : ");
        scanf("%f", &t.noteDS);
         FILE *fic = fopen("note.csv", "a+");
    if(fic==NULL)
    exit(1);
    fprintf(fic,"%d,%f,%f\n",code, t.noteCC,t.noteDS);
    fclose(fic);
        n = n + 1;
    }
    printf("les notes de la classe ont ete ajoute\n");
}
void menuNote(){
    int choix;
    printf("+_+_+_+_+ Gestion Des Notes +_+_+_+_\n");
    printf("1.note etudiant dans une matiere\n");
    printf("2.note etudiant dans toute ses matiere\n");
    printf("3.note d'une classe\n");
    printf("4.modifer une note \n");
    printf("5.supprimer une note\n");
    printf("6.afficher les notes \n");
    printf("7.Precedent\n ");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            saisieNoteEtudiantUneMatiere();
            break;
        case 2:
            saisieAllNote();
            break;
        case 3:
            saisieNoteClasse();
            break;
        case 4:
            modifierNote();
            break;
        case 5:
            supprimerNote();
            break;
        case 6:
            afficherNote();
            break;
        case 7: 
            menuPrincipal();
            break;
        default:
            printf("pas de choix\n");
            break;
        }
}


void modifierNote()
{
    int num, k;
    printf("Saisir le numero de l'etudiant que vous voulez modifier les  notes : ");
    scanf("%d", &num);

    for (i = 1; i <= n; i++)
    {
        if (tN[i].Netu== num)
        {
            k = i;
        }
 
    }
    printf("refernece matiere : ");
    scanf("%d", &tN[k].Rmat);
    printf("NoteCC: ");
    scanf("%f", &tN[k].noteCC);
    printf("NoteDS : ");
    scanf("%f", &tN[k].noteDS);
 
}

void supprimerNote()
{

    int j, num, k, nuEtu;

    printf("Saisir le numero de l'etudiant  : ");
    scanf("%d", &nuEtu);


    printf("Saisir la reference de la matiere  : ");
    scanf("%d", &num);
    for (i = 1; i <= n; i++)
    {
        if (tN[i].Rmat == num)
        {
            k = i;
            n = n - 1;
            for (j = k; j <= n; j++)
            {
                tN[j] = tN[j + 1];
            }
        }
    }
    printf("la note a ete supprime\n");
}



void afficherNote()
{
    int lettre;
    FILE *fic = fopen("note.csv", "r");
    if(fic==NULL)
    exit(1);
  
  while((lettre = fgetc(fic))!=EOF){
      printf("%c",lettre);

  }
  fclose(fic);
}