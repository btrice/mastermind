#include"partie.h"
/*Définitions des fonctions*/
int regleDuJeu(){
	int partie = 0;
	printf("Mastermind est un jeu de société dont le but est :\n");
	printf("Trouver un code secret ( 4 couleurs différentes)\n");
	printf("Vous avez %d essais pour trouver le code secret\n",MAX_NIVEAU); 
	printf("Le nombre de couleurs est de 8 :\n");
	afficheCouleur();
	printf("############# CHOIX ############\n\n");
	printf("\t\t 1 - Jouer contre Ordinateur\n");
	printf("\t\t 2 - Jouer à deux joueurs\n");
	printf("\t\t Votre choix : ");
	scanf(" %d",&partie);
	while((partie != PARTIE_1) && (partie != PARTIE_2)){
	  printf("\t\t Choix entre (1 et 2) : ");
	  scanf(" %d",&partie);
	} 
	system("clear");
	return partie;
}

/* Affiche les couleurs du jeu*/
void afficheCouleur(){
	printf("r = ");
	nomDeLaCouleur('r');
	printf("\n");
	printf("j = ");
	nomDeLaCouleur('j');
	printf("\n");
	printf("v = ");
	nomDeLaCouleur('v');
	printf("\n");
	printf("b = ");
	nomDeLaCouleur('b');
	printf("\n");
	printf("o = ");
	nomDeLaCouleur('o');
	printf("\n");
	printf("B = ");
	nomDeLaCouleur('B');
	printf("\n");
	printf("V = ");
	nomDeLaCouleur('V');
	printf("\n");
	printf("f = ");
	nomDeLaCouleur('f');
	printf("\n");
}
/* Contrôle le choix des couleurs du joueurs*/
char* ControlsaisirJoueur(char* lesCouleurs){
		char *choix = NULL;
		choix = (char *)malloc(sizeof(char) * NB_SECRET);
		printf("\t\tCouleur 1 :");
		scanf(" %c", &choix[0]);
		/* Vérification de la couleur 1 */
		while(verificationCouleurSaisir(choix[0],lesCouleurs) == 0){
			printf("\t\tErreur Couleur 1 Inconnue\n");
			printf("\t\tCouleur 1 :");
			scanf(" %c", &choix[0]);
			
		}
		printf("\t\tCouleur 2 :");
		scanf(" %c", &choix[1]);
		/* Vérification de la couleur 2 */
		while(verificationCouleurSaisir(choix[1],lesCouleurs) == 0){
			printf("\t\tErreur Couleur 2 Inconnue\n");
			
			printf("\t\tCouleur 2 :");
			scanf(" %c", &choix[1]);
		}
		printf("\t\tCouleur 3 :");
		scanf(" %c", &choix[2]);
		/* Vérification de la couleur 3*/
		while(verificationCouleurSaisir(choix[2],lesCouleurs) == 0){
			printf("\t\tErreur Couleur 3 Inconnue\n");
			printf("\t\tCouleur 3 :");
			scanf(" %c", &choix[2]);
		}
		printf("\t\tCouleur 4 :");
		scanf(" %c", &choix[3]);
		/* Vérification de la couleur 4*/
		while(verificationCouleurSaisir(choix[3],lesCouleurs) == 0){
			printf("\t\tErreur Couleur 4 Inconnue\n");
			printf("\t\tCouleur 4 :");
			scanf(" %c", &choix[3]);
		}
	return choix;
}
/* lance la partie*/
void lanceLapartie(int partie){
        char *solution = NULL;
	char *lesCouleurs = NULL;
	char *choix = NULL;
	int Nbpartie = 0;
	int fin = 0;
	lesCouleurs = couleurAutoriser();
	if(partie == PARTIE_1){  /* partie contre ordinateur*/
		solution = genererSolutionSecret(lesCouleurs);
	} else {
		printf("\t\tJoueur 1 code secret: 4 couleurs différentes\n");
		afficheCouleur();
		solution = (char *)malloc(sizeof(char) * NB_SECRET);
		solution = ControlsaisirJoueur(lesCouleurs);  /* Couleur choisi comme solution paar le joueur 1*/
                /* vérifie qu'il existe pas deux couleurs identiques*/
		while(verificationCouleurDoublon(solution)==0){
			printf("\t\tCouleur choisie : ");
			couleurChoisir(solution);
			printf("\t\tERREUR: Couleur en doubon\n");
			solution = ControlsaisirJoueur(lesCouleurs); 
		}
		system("clear");
		
	}
	printf("################ DEBUT DU JEU ####################\n");
	while(Nbpartie < MAX_NIVEAU && fin == 0) {
		printf("# Partie %d / %d:\n",Nbpartie + 1,MAX_NIVEAU);
		afficheCouleur();
		choix = ControlsaisirJoueur(lesCouleurs);
		/* vérifie qu'il existe pas deux couleurs identiques*/
		while(verificationCouleurDoublon(choix)==0){
			printf("\t\tCouleur choisie : ");
			couleurChoisir(choix);
			printf("\t\tERREUR: Couleur en doublon\n");
			choix = ControlsaisirJoueur(lesCouleurs);
		}
		printf("\t\tCouleur choisie : ");
		couleurChoisir(choix);  /*affiche les couleurs*/
		Nbpartie = Nbpartie + 1;
		fin = verification(choix,solution); /* vérification de la partie*/
		/*afficheSolution(solution);*/
	}
	if(fin == 1 ) {
		printf("Bravo! Vous avez gagné\n");
		
	} else {
		printf("Vous avez perdu ! \n");
	}
	
	afficheSolution(solution);
	/* On libère la mémoire*/
        free(solution);
	free(lesCouleurs);
	free(choix);
	printf("\n");
	
}
/* verification des couleurs*/
int verificationCouleurSaisir(char c, char* lesCouleurs){
	int i;
	int existe = 0;
	for(i = 0 ; i < NB_COULEUR && existe == 0 ; i = i +1){
		if(lesCouleurs[i]==c)
		  existe = 1;
	}
	return existe;
}
/* Génération aléatoire d'une solution */
char * genererSolutionSecret(char * lesCouleurs){
	char * solutionsecret = NULL;
	int i;
	int verification ;
	verification = 0;
	srand(time(NULL));
	solutionsecret = (char *)malloc(sizeof(char) * NB_SECRET); /* tableau contenant la solution */
	while(verification == 0){
		for(i = 0 ; i < NB_SECRET ; i = i +1){
		solutionsecret[i] = lesCouleurs[rand()%NB_COULEUR];	
		} 
		/*afficheSolution(solutionsecret);*/
		verification = verificationCouleurDoublon(solutionsecret);
	}
	
	return solutionsecret;
}

/* Vérifi qu'il existe pas deux fois la même couleurs*/
int verificationCouleurDoublon(char *couleur){
	int i;
	int j;
	for(i = 0 ; i < NB_SECRET ; i = i +1){
		for(j = 0 ; j != i ; j = j +1){
			if(couleur[i] == couleur[j])
				return 0; /* couleur en doublon*/
		} 	
	} 
	return 1;
}
/*Initialisation des couleurs autorisées*/
char * couleurAutoriser(){
	char * couleurs = NULL;
	couleurs = (char *)malloc(sizeof(char) * NB_COULEUR);
	couleurs[0]='r'; /* Couleur rouge */
	couleurs[1]='j'; /* Couleur jaune */
	couleurs[2]='v'; /* Couleur vert */ 
	couleurs[3]='b'; /*  Couleur bleu */
	couleurs[4]='o'; /*  Couleur orange */
	couleurs[5]='B'; /*  Couleur Blanc */ 
	couleurs[6]='V'; /*  Couleur Violet */ 
	couleurs[7]='f'; /*  Couleur fuschia */
	
	return couleurs;
	
}

/*Vérification des couleurs */
void couleurChoisir(char* choix){
	int i;
	for(i = 0 ; i < NB_SECRET ; i = i +1){
		nomDeLaCouleur(choix[i]);
	}
	printf("\n");
}

/*affiche le nom de couleur */
void nomDeLaCouleur(char c){
	if(c=='r') printf("rouge ");
        else if(c=='j') printf("jaune ");
	else if(c=='v') printf("vert ");
	else if(c=='b') printf("bleu ");
	else if(c=='o') printf("orange ");
	else if(c=='B') printf("Blanc ");
	else if(c=='V') printf("Violet ");
	else if(c=='f') printf("fuschia ");
        else printf("Iconnue ");
}

/*Vérification de la partie*/
int verification(char* choix,char* solution){
	int mal_place = 0;
	int bien_place = 0;
	int bonne_couleur = 0;
	int i = 0;
	int j =0;
	/* Vérifications des couleurs bien placé*/
	for(i = 0 ; i < NB_SECRET; i = i + 1){
		if(solution[i] == choix[i]){
			bien_place = bien_place + 1;	
		}
	}
	if(bien_place == NB_SECRET){
		return 1;               /*partie terminée le code secret trouvé*/
	} else {
		/*vérifications des bonnes couleurs indépendamment de leur place*/
		for(i = 0 ; i < NB_SECRET; i = i + 1){
			for(j = 0 ; j < NB_SECRET; j = j + 1){
				if(choix[i] == solution[j]){
					bonne_couleur = bonne_couleur + 1;
				}	
			}
		}
	}
	mal_place = bonne_couleur - bien_place;
	printf("\t\t## Bien places %d , mal places %d\n",bien_place,mal_place);
	return 0;
	
}
/* Affihe la solution*/
void afficheSolution(char *solution){
	int i;
	printf("La Solution : ");
	for(i = 0 ; i < NB_SECRET; i = i + 1){
		nomDeLaCouleur(solution[i]);
	}
	printf("\n");
}

