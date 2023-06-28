#ifndef MESFONCTIONS_H
#define MESFONCTIONS_H


typedef struct
{
    char nom;
    int couleur;
    int valeur;

} carte;

typedef struct
{
    carte main[10];
    int tailleMain;
    int score;
    int nbAs;
    int solde;
    int mise;
    char etat;

} joueur;

void parametresConsole();
void clearConsole();

void setColor(int ForgC);
void ClearConsoleToColors(int ForgC, int BackC);
void creation_jeu_de_carte(carte *jeu_de_carte, int *taille);
carte recuperation_carte(carte *jeu_de_carte, int *taille);

void couleurAffichage(carte carte);
void afficherPartie(joueur Croupier, joueur Joueur1, joueur Joueur2, joueur Joueur3, int meilleursGains[]);

void purge(void);
void meilleursGains(int meilleursGains[], int mise);


#endif // MESFONCTIONS_H
