#include <stdio.h>
#include <stdlib.h>
#include "mesFonctions.h"
#include <assert.h>
#include <wchar.h>
#include <windows.h>
int main()
{
    parametresConsole();

    /* Affichage de la partie
    afficherPartie(Croupier, Joueur1, Joueur2, Joueur3); */

    /* Liste des etats de joueurs : 'e' en_jeu , 'h' hors_jeu , 'p' = perdant , 'n' = null, 'g' = gagnant , 'b' = blackjack */

// Debut partie
char instructionNouvellePartie = 'o';
while (instructionNouvellePartie != 'n')
{
    if (instructionNouvellePartie == 'o')
    {
        // Variable jeu de carte
        int taille = 52;
        carte jeu_de_carte[52];

        // Initialisation du croupier

        joueur Croupier;
        Croupier.tailleMain = 0;
        Croupier.score = 0;
        Croupier.nbAs = 0;


        // Initialisation du Joueur 1

        joueur Joueur1;
        Joueur1.tailleMain = 0;
        Joueur1.solde = 500;
        Joueur1.mise = 0;
        Joueur1.score = 0;
        Joueur1.nbAs = 0;
        Joueur1.etat = 'e';



        // Initialisation du Joueur 2

        joueur Joueur2;
        Joueur2.tailleMain = 0;
        Joueur2.solde = 500;
        Joueur2.mise = 0;
        Joueur2.score = 0;
        Joueur2.nbAs = 0;
        Joueur2.etat = 'e';


        // Initialisation du Joueur 3

        joueur Joueur3;
        Joueur3.tailleMain = 0;
        Joueur3.solde = 500;
        Joueur3.mise = 0;
        Joueur3.score = 0;
        Joueur3.nbAs = 0;
        Joueur3.etat = 'e';


        int tabMeilleursGains[5] = {0,0,0,0,0};

        // Debut du tour

        while ((Joueur1.etat != 'h') || (Joueur2.etat != 'h') || (Joueur3.etat != 'h'))
        {
            creation_jeu_de_carte(jeu_de_carte,&taille);

        // Demande de la mise du Joueur 1
            Sleep(1);
            int instructionMiseJoueur1 = 0;
            while (((instructionMiseJoueur1 < 2) || (instructionMiseJoueur1 > 100)) && (Joueur1.etat == 'e'))
            {
                clearConsole();
                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
                printf("\nMise min : 2 | Mise max : 100");
                printf("\nQuel est votre mise ? ");

                if (scanf("%d", &instructionMiseJoueur1)!= 1)
                {
                    puts("Erreur de saisie");
                    purge();
                }

                if ((instructionMiseJoueur1 >= 2) && (instructionMiseJoueur1 <= 100))
                {
                    if (Joueur1.solde >= instructionMiseJoueur1)
                    {
                        Joueur1.solde = Joueur1.solde - instructionMiseJoueur1;
                        Joueur1.mise = instructionMiseJoueur1;
                    }
                    else
                    {
                        instructionMiseJoueur1 = 0;
                    }
                }
                else
                {
                    instructionMiseJoueur1 = 0;
                }
            }

        // Demande de la mise du Joueur 2

            int instructionMiseJoueur2 = 0;
            while (((instructionMiseJoueur2 < 2) || (instructionMiseJoueur2 > 100)) && (Joueur2.etat == 'e'))
            {
                clearConsole();
                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
                printf("\n\t\t\t\t\t\t\tMise min : 2 | Mise max : 100");
                printf("\n\t\t\t\t\t\t\tQuel est votre mise ? ");

                if (scanf("%d", &instructionMiseJoueur2)!= 1)
                {
                    puts("Erreur de saisie");
                    purge();
                }

                if ((instructionMiseJoueur2 >= 2) && (instructionMiseJoueur2 <= 100))
                {
                    if (Joueur2.solde >= instructionMiseJoueur2)
                    {
                        Joueur2.solde = Joueur2.solde - instructionMiseJoueur2;
                        Joueur2.mise = instructionMiseJoueur2;
                    }
                    else
                    {
                        instructionMiseJoueur2 = 0;
                    }
                }
            }

        // Demande de la mise du Joueur 3

            int instructionMiseJoueur3 = 0;
            while (((instructionMiseJoueur3 < 2) || (instructionMiseJoueur3 > 100)) && (Joueur3.etat == 'e'))
            {
                clearConsole();
                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tMise min : 2 | Mise max : 100");
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tQuel est votre mise ? ");

                if (scanf("%d", &instructionMiseJoueur3)!= 1)
                {
                    puts("Erreur de saisie");
                    purge();
                }

                if ((instructionMiseJoueur3 >= 2) && (instructionMiseJoueur3 <= 100))
                {
                    if (Joueur3.solde >= instructionMiseJoueur3)
                    {
                        Joueur3.solde = Joueur3.solde - instructionMiseJoueur3;
                        Joueur3.mise = instructionMiseJoueur3;
                    }
                    else
                    {
                        instructionMiseJoueur3 = 0;
                    }
                }
            }



        // Nouvelle donne

            clearConsole();
            afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);

            if (Joueur1.etat == 'e')
            {
                sleep(1);
                clearConsole();

                Joueur1.main[Joueur1.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
                Joueur1.score = Joueur1.score + Joueur1.main[Joueur1.tailleMain].valeur;
                if (Joueur1.main[Joueur1.tailleMain].nom == 'A')
                {
                    Joueur1.nbAs = Joueur1.nbAs + 1;
                }
                Joueur1.tailleMain ++;


                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
            }


            if (Joueur2.etat == 'e')
            {
                sleep(1);
                clearConsole();

                Joueur2.main[Joueur2.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
                Joueur2.score = Joueur2.score + Joueur2.main[Joueur2.tailleMain].valeur;
                if (Joueur2.main[Joueur2.tailleMain].nom == 'A')
                {
                    Joueur2.nbAs = Joueur2.nbAs + 1;
                }
                Joueur2.tailleMain ++;

                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
            }


            if (Joueur3.etat == 'e')
            {
                sleep(1);
                clearConsole();

                Joueur3.main[Joueur3.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
                Joueur3.score = Joueur3.score + Joueur3.main[Joueur3.tailleMain].valeur;
                if (Joueur3.main[Joueur3.tailleMain].nom == 'A')
                {
                    Joueur3.nbAs = Joueur3.nbAs + 1;
                }
                Joueur3.tailleMain ++;

                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
            }


            if (Joueur1.etat == 'e')
            {
                sleep(1);
                clearConsole();

                Joueur1.main[Joueur1.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
                Joueur1.score = Joueur1.score + Joueur1.main[Joueur1.tailleMain].valeur;
                if (Joueur1.main[Joueur1.tailleMain].nom == 'A')
                {
                    Joueur1.nbAs = Joueur1.nbAs + 1;
                }
                if ((Joueur1.score == 21) && (Joueur1.nbAs > 0))
                {
                    Joueur1.etat = 'b';
                    Joueur1.solde = Joueur1.solde + (Joueur1.mise*2.5);
                    meilleursGains(tabMeilleursGains, (Joueur1.mise*2.5));
                    Joueur1.mise = 0;
                }
                if ((Joueur1.score > 21) && (Joueur1.nbAs > 0))
                {
                    Joueur1.nbAs = Joueur1.nbAs - 1;
                    Joueur1.score = Joueur1.score - 10;
                }
                Joueur1.tailleMain ++;

                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
            }


            if (Joueur2.etat == 'e')
            {
                sleep(1);
                clearConsole();

                Joueur2.main[Joueur2.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
                Joueur2.score = Joueur2.score + Joueur2.main[Joueur2.tailleMain].valeur;
                if (Joueur2.main[Joueur2.tailleMain].nom == 'A')
                {
                    Joueur2.nbAs = Joueur2.nbAs + 1;
                }
                if ((Joueur2.score == 21) && (Joueur2.nbAs > 0))
                {
                    Joueur2.etat = 'b';
                    Joueur2.solde = Joueur2.solde + (Joueur2.mise*2.5);
                    meilleursGains(tabMeilleursGains, Joueur2.mise*2.5);
                    Joueur2.mise = 0;
                }
                if ((Joueur2.score > 21) && (Joueur2.nbAs > 0))
                {
                    Joueur2.nbAs = Joueur2.nbAs - 1;
                    Joueur2.score = Joueur2.score - 10;
                }
                Joueur2.tailleMain ++;

                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
            }


            if (Joueur3.etat == 'e')
            {
                sleep(1);
                clearConsole();

                Joueur3.main[Joueur3.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
                Joueur3.score = Joueur3.score + Joueur3.main[Joueur3.tailleMain].valeur;
                if (Joueur3.main[Joueur3.tailleMain].nom == 'A')
                {
                    Joueur3.nbAs = Joueur3.nbAs + 1;
                }
                if ((Joueur3.score == 21) && (Joueur3.nbAs > 0))
                {
                    Joueur3.etat = 'b';
                    Joueur3.solde = Joueur3.solde + (Joueur3.mise*2.5);
                    meilleursGains(tabMeilleursGains, Joueur3.mise*2.5);
                    Joueur3.mise = 0;
                }
                if ((Joueur3.score > 21) && (Joueur3.nbAs > 0))
                {
                    Joueur3.nbAs = Joueur3.nbAs - 1;
                    Joueur3.score = Joueur3.score - 10;
                }
                Joueur3.tailleMain ++;

                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
            }

            sleep(1);
            clearConsole();

            Croupier.main[Croupier.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
            Croupier.score = Croupier.score + Croupier.main[Croupier.tailleMain].valeur;
            if (Croupier.main[Croupier.tailleMain].nom == 'A')
            {
                Croupier.nbAs = Croupier.nbAs + 1;
            }
            Croupier.tailleMain ++;

            afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);

            sleep(1);

        // Debut distribution joueurs

            // Demande de carte Joueur 1
            char instructionJoueur1 = NULL;
            while ((instructionJoueur1 != '-') && (Joueur1.etat == 'e'))
            {
                clearConsole();
                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
                printf("\n\nTirer : + | Se coucher : -\n");

                scanf("%c",&instructionJoueur1);

                if (instructionJoueur1 == '+')
                {
                    instructionJoueur1 = NULL;

                    Joueur1.main[Joueur1.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
                    Joueur1.score = Joueur1.score + Joueur1.main[Joueur1.tailleMain].valeur;
                    if (Joueur1.main[Joueur1.tailleMain].nom == 'A')
                    {
                        Joueur1.nbAs = Joueur1.nbAs + 1;
                    }
                    if ((Joueur1.score > 21) && (Joueur1.nbAs > 0))
                    {
                        Joueur1.nbAs = Joueur1.nbAs - 1;
                        Joueur1.score = Joueur1.score - 10;
                    }
                    if (Joueur1.score == 21)

                    {
                        instructionJoueur1 = '-';
                    }
                    if (Joueur1.score > 21)
                    {
                        Joueur1.etat = 'p';
                    }

                    Joueur1.tailleMain ++;
                }
            }

            // Demande de carte Joueur 2
            char instructionJoueur2 = NULL;
            while ((instructionJoueur2 != '-') && (Joueur2.etat == 'e'))
            {
                clearConsole();
                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
                printf("\n\n\t\t\t\t\t\t\tTirer : + | Se coucher : -\n");

                scanf("%c",&instructionJoueur2);

                if (instructionJoueur2 == '+')
                {
                    instructionJoueur2 = NULL;
                    Joueur2.main[Joueur2.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
                    Joueur2.score = Joueur2.score + Joueur2.main[Joueur2.tailleMain].valeur;
                    if (Joueur2.main[Joueur2.tailleMain].nom == 'A')
                    {
                        Joueur2.nbAs = Joueur2.nbAs + 1;
                    }
                    if ((Joueur2.score > 21) && (Joueur2.nbAs > 0))
                    {
                        Joueur2.nbAs = Joueur2.nbAs - 1;
                        Joueur2.score = Joueur2.score - 10;
                    }
                    if (Joueur2.score == 21)
                    {
                        instructionJoueur2 = '-';
                    }
                    if (Joueur2.score > 21)
                    {
                        Joueur2.etat = 'p';
                    }

                    Joueur2.tailleMain ++;
                }
            }

            // Demande de carte Joueur 3
            char instructionJoueur3 = NULL;
            while ((instructionJoueur3 != '-') && (Joueur3.etat == 'e'))
            {
                clearConsole();
                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tTirer : + | Se coucher : -\n");

                scanf("%c",&instructionJoueur3);

                if (instructionJoueur3 == '+')
                {
                    instructionJoueur3 = NULL;
                    Joueur3.main[Joueur3.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
                    Joueur3.score = Joueur3.score + Joueur3.main[Joueur3.tailleMain].valeur;
                    if (Joueur3.main[Joueur3.tailleMain].nom == 'A')
                    {
                        Joueur3.nbAs = Joueur3.nbAs + 1;
                    }
                    if ((Joueur3.score > 21) && (Joueur3.nbAs > 0))
                    {
                        Joueur3.nbAs = Joueur3.nbAs - 1;
                        Joueur3.score = Joueur3.score - 10;
                    }
                    if (Joueur3.score == 21)
                    {
                        instructionJoueur3 = '-';
                    }
                    if (Joueur3.score > 21)
                    {
                        Joueur3.etat = 'p';
                    }

                    Joueur3.tailleMain ++;
                }
            }

        // Fin distribution Joueurs

        // Distribution croupier

            while (Croupier.score < 17)
            {
                sleep(1);
                clearConsole();
                afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
                Croupier.main[Croupier.tailleMain] = recuperation_carte(jeu_de_carte, &taille);
                Croupier.score = Croupier.score + Croupier.main[Croupier.tailleMain].valeur;
                if (Croupier.main[Croupier.tailleMain].nom == 'A')
                {
                    Croupier.nbAs = Croupier.nbAs + 1;
                }
                if (((Croupier.score > 21) || (Croupier.score == 17)) && (Croupier.nbAs > 0))
                {
                    Croupier.nbAs = Croupier.nbAs - 1;
                    Croupier.score = Croupier.score - 10;
                }
                Croupier.tailleMain ++;
            }
            sleep(1);
            clearConsole();
            afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);

        // Comparaison des scores Joueur1

            if (Joueur1.etat == 'e')
            {
                if (Croupier.score > 21)
                {
                    Joueur1.etat = 'g';
                }
                else
                {
                    if (Croupier.score > Joueur1.score)
                    {
                        Joueur1.etat = 'p';
                    }
                    if (Croupier.score == Joueur1.score)
                    {
                        Joueur1.etat = 'n';
                    }
                    if (Croupier.score < Joueur1.score)
                    {
                        Joueur1.etat = 'g';
                    }
                }
            }


        // Comparaison des scores Joueur2

            if (Joueur2.etat == 'e')
            {
                if (Croupier.score > 21)
                {
                    Joueur2.etat = 'g';
                }
                else
                {
                    if (Croupier.score > Joueur2.score)
                    {
                        Joueur2.etat = 'p';
                    }
                    if (Croupier.score == Joueur2.score)
                    {
                        Joueur2.etat = 'n';
                    }
                    if (Croupier.score < Joueur2.score)
                    {
                        Joueur2.etat = 'g';
                    }
                }
            }


        // Comparaison des scores Joueur3

            if (Joueur3.etat == 'e')
            {
                if (Croupier.score > 21)
                {
                    Joueur3.etat = 'g';
                }
                else
                {
                    if (Croupier.score > Joueur3.score)
                    {
                        Joueur3.etat = 'p';
                    }
                    if (Croupier.score == Joueur3.score)
                    {
                        Joueur3.etat = 'n';
                    }
                    if (Croupier.score < Joueur3.score)
                    {
                        Joueur3.etat = 'g';
                    }
                }
            }

        // Gestion des mises

            if (Joueur1.etat == 'g')
            {
                Joueur1.solde = Joueur1.solde + (Joueur1.mise*2);
                meilleursGains(tabMeilleursGains, Joueur1.mise*2);
            }
            if (Joueur1.etat == 'n')
            {
                Joueur1.solde = Joueur1.solde + Joueur1.mise;
                meilleursGains(tabMeilleursGains, Joueur1.mise);
            }
            Joueur1.mise = 0;


            if (Joueur2.etat == 'g')
            {
                Joueur2.solde = Joueur2.solde + (Joueur2.mise*2);
                meilleursGains(tabMeilleursGains, Joueur2.mise*2);
            }
            if (Joueur2.etat == 'n')
            {
                Joueur2.solde = Joueur2.solde + Joueur2.mise;
                meilleursGains(tabMeilleursGains, Joueur2.mise);
            }
            Joueur2.mise = 0;


            if (Joueur3.etat == 'g')
            {
                Joueur3.solde = Joueur3.solde + (Joueur3.mise*2);
                meilleursGains(tabMeilleursGains, Joueur3.mise*2);
            }
            if (Joueur3.etat == 'n')
            {
                Joueur3.solde = Joueur3.solde + Joueur3.mise;
                meilleursGains(tabMeilleursGains, Joueur3.mise);
            }
            Joueur3.mise = 0;


            clearConsole();
            afficherPartie(Croupier, Joueur1, Joueur2, Joueur3, tabMeilleursGains);
            sleep(3);

            Croupier.tailleMain = 0;
            Croupier.score = 0;
            Croupier.nbAs = 0;

        // Mise a jour des stats des joueurs encore en jeu

            if (Joueur1.etat != 'h')
            {
                Joueur1.score = 0;
                Joueur1.nbAs = 0;
                Joueur1.tailleMain = 0;
                Joueur1.etat = 'e';
            }

            if (Joueur2.etat != 'h')
            {
                Joueur2.score = 0;
                Joueur2.nbAs = 0;
                Joueur2.tailleMain = 0;
                Joueur2.etat = 'e';
            }

            if (Joueur3.etat != 'h')
            {
                Joueur3.score = 0;
                Joueur3.nbAs = 0;
                Joueur3.tailleMain = 0;
                Joueur3.etat = 'e';
            }

        // Verification du solde necessaire pour jouer

            if (Joueur1.solde < 2 )
            {
                Joueur1.etat = 'h';
            }

            if (Joueur2.solde < 2 )
            {
                Joueur2.etat = 'h';
            }

            if (Joueur3.solde < 2 )
            {
                Joueur3.etat = 'h';
            }
        }
    instructionNouvellePartie = NULL;
    }
    clearConsole();
    printf("Voulez-vous rejouer ? (oui = o | non = n) ");
    scanf("%c",&instructionNouvellePartie);
}
}
