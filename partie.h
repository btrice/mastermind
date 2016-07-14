#ifndef _PARTIE_H
#define _PARTIE_H
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define NB_SECRET 4 /*Nombre de couleur secret */
#define MAX_NIVEAU 10 /*Nombre maximal d'éssai*/
#define NB_COULEUR 8 /*Nombre de couleur différents*/
#define PARTIE_1 1 /* partie contre ordinateur*/
#define PARTIE_2 2 /* partie à deux joueurs*/

/*Déclarations des fonctions*/
int regleDuJeu();
void lanceLapartie(int partie);
char * genererSolutionSecret(char* lesCouleurs);
int verificationCouleurDoublon(char *couleur); 
int verificationCouleurSaisir(char c, char* lesCouleurs);
char * couleurAutoriser();
void nomDeLaCouleur(char c);
void couleurChoisir(char* choix);
int verification(char* choix,char* solution);
void afficheSolution(char *solution);
void afficheCouleur();
char* ControlsaisirJoueur(char* lesCouleurs);
#endif
