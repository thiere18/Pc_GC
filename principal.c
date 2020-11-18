#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant.h"
#include "matiere.h"
#include "classe.h"
#include "note.h"
void menuPrincipal()
{
    int choix;
    printf("_+_+_+_+ mini logiciel de gestion de claase _+_+_+_+_\n");
    printf("que voulez vous faire\n");
    printf(" 1 . Gestion des etudiants\n");
    printf(" 2 . Gestion des matieres\n");
    printf(" 3 . Gestion des classes \n");
    printf(" 4 . Gestion des notes\n");
    printf(" 5 . Quitter \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        menuEtudiant();
        break;
    case 2:
        menuMatiere();
        break;
    case 3:
        menuClasse();
        break;
    case 4:
        menuNote();
    default:
        exit(0);
        break;
    }
}