#include <stdio.h>
#include <stdlib.h>
#include "mesFonctions.h"
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <math.h>
#include <malloc.h>

/// /////////////////////////////////////////////////////////////////////// ///
/// Proc�dure pour changer l'affichage du texte dans la console             ///
/// 0 : noir        4 : rouge       8  : gris fonc�     12 : rouge clair    ///
/// 1 : bleu        5 : magenta     9  : bleu clair     13 : magenta clair  ///
/// 2 : vert        6 : brun        10 : vert clair     14 : jaune          ///
/// 3 : cyan        7 : gris clair  11 : cyan clair     15 : blanc          ///
/// source de cette fonction : https://askcodez.com/comment-changer-la-     ///
/// couleur-du-texte-et-de-la-console-de-couleur-dans-codeblocks.html       ///
/// /////////////////////////////////////////////////////////////////////// ///

void meilleursGains(int meilleursGains[], int mise)
{
    for (int indexGain1=0;indexGain1<5;indexGain1++)
    {
        if (mise > meilleursGains[indexGain1])
        {
            for (int indexGain2=4;indexGain2>indexGain1;indexGain2--)
            {;
                int gainTemp = meilleursGains[indexGain2];
                meilleursGains[indexGain2] = meilleursGains[indexGain2-1];
                meilleursGains[indexGain2-1] = gainTemp;
            }
            meilleursGains[indexGain1] = mise;
            return ;
        }
    }
}


void purge(void) // https://www.developpez.net/forums/d477652/c-cpp/c/bibliotheques-systemes-outils/bibliotheque-standard/scanf-probleme-programme-boucle/
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF); /* mange le tampon */
}

void parametresConsole() // https://codes-sources.commentcamarche.net/source/28976-console-plein-ecran
{
    keybd_event(VK_MENU,0x38,0,0);         //Simulation appuie sur ALT
    keybd_event(VK_RETURN,0x1c,0,0);        // Simulation appuie ENTREE
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);     // Relache entrée
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);       //relache ALT
    ClearConsoleToColors(0,15);
}

void clearConsole()
{
    system("cls");
}

void setColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
                 //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
}

void ClearConsoleToColors(int ForgC, int BackC)
 {
 WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                     //This is used to reset the carat/cursor to the top left.
 COORD coord = {0, 0};
                  //A return value... indicating how many chars were written
                    //  not used but we need to capture this since it will be
                      //  written anyway (passing NULL causes an access violation).
  DWORD count;

                               //This is a structure containing all of the console info
                      //it is used here to find the size of the console.
 CONSOLE_SCREEN_BUFFER_INFO csbi;
                 //Here we will set the current color
 SetConsoleTextAttribute(hStdOut, wColor);
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                          //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                          //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
 }
 return;
}

void creation_jeu_de_carte(carte *jeu_de_carte, int *taille)
{
    int tabNombre[13] = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    int tabCouleur[4] = {3,4,5,6};
    int tabValeur[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
    char *numero_de_la_carte=(char*)calloc(10,sizeof (char));

    int index = 0;

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<13;j++)
        {

            if (tabNombre[j]==11)
            {
                *numero_de_la_carte = 'J';
            }
            if (tabNombre[j]==12)
            {
                *numero_de_la_carte = 'Q';
            }
            if (tabNombre[j]==13)
            {
                *numero_de_la_carte = 'K';
            }
            if (tabNombre[j]==14)
            {
                *numero_de_la_carte = 'A';
            }
            if (tabNombre[j]<11)
            {
                itoa(tabNombre[j],numero_de_la_carte,10);
            }
            jeu_de_carte[index].nom = *numero_de_la_carte;
            jeu_de_carte[index].couleur = tabCouleur[i];
            jeu_de_carte[index].valeur = tabValeur[j];

            index = index + 1;
        }
    }
    // Melange des cartes
    srand(time (NULL));
    int index2;
    carte carteTemp;
    for (int index1=0;index1<52;index1++)
    {
        index2 = rand() % 52;
        carteTemp = jeu_de_carte[index1];
        jeu_de_carte[index1] = jeu_de_carte[index2];
        jeu_de_carte[index2] = carteTemp;
    }
    *taille = 52;
}

carte recuperation_carte(carte *jeu_de_carte, int *taille)
{
    *taille = *taille - 1;
    carte carte_a_renvoyer = jeu_de_carte[*taille];

    return carte_a_renvoyer;
}

void couleurAffichage(carte carte)
{
    if (carte.couleur == 3 || carte.couleur == 4)
    {
        setColor(12);
    }
    else
    {
        setColor(0);
    }
}

void afficherPartie(joueur Croupier, joueur Joueur1, joueur Joueur2, joueur Joueur3, int meilleursGains[])
{
    printf("Meilleurs gains : \n");
    for (int indexGain=0;indexGain<5;indexGain++)
    {
        printf("%d : %d\n",indexGain+1, meilleursGains[indexGain]);
    }
    printf("\n\n");
// Affichage croupier
    for (int i=0;i<Croupier.tailleMain;i++)
    {
        couleurAffichage(Croupier.main[i]);
        printf(" ______ ");
    }
    printf("\n");
    for (int i=0;i<Croupier.tailleMain;i++)
    {
        couleurAffichage(Croupier.main[i]);
        printf("|      |");
    }
    printf("\n");
    for (int i=0;i<Croupier.tailleMain;i++)
    {
        couleurAffichage(Croupier.main[i]);
        printf("|      |");
    }
    printf("\n");
    for (int i=0;i<Croupier.tailleMain;i++)
    {
        couleurAffichage(Croupier.main[i]);
        if (Croupier.main[i].nom != '1')
            {

                printf("|  %c%c  |",Croupier.main[i].nom,Croupier.main[i].couleur);
            }
            else
            {
                printf("| 10%c  |",Croupier.main[i].couleur);
            }
    }
    printf("\n");
    for (int i=0;i<Croupier.tailleMain;i++)
    {
        couleurAffichage(Croupier.main[i]);
        printf("|      |");
    }
    printf("\n");
    for (int i=0;i<Croupier.tailleMain;i++)
    {
        couleurAffichage(Croupier.main[i]);
        printf("|______|");
    }
    printf("\n");
    setColor(0);
    printf("Croupier : %d",Croupier.score);

 // Affichage joueurs
    joueur joueurs[3]={Joueur1,Joueur2,Joueur3};

    printf("\n\n\n\n\n\n\n\n\n");
    for (int indexJoueur=0;indexJoueur<3;indexJoueur++)
    {
        setColor(0);
        if (joueurs[indexJoueur].etat == 'b')
        {
            printf("BlackJack !");
            printf("\t\t\t\t\t\t");
        }
        if (joueurs[indexJoueur].etat == 'g')
        {
            printf("Gagn%ce !",130);
            printf("\t\t\t\t\t\t");
        }
        if (joueurs[indexJoueur].etat == 'n')
        {
            printf("Egalit%c !",130);
            printf("\t\t\t\t\t\t");
        }
        if (joueurs[indexJoueur].etat == 'p')
        {
            printf("Perdu !");
            printf("\t\t\t\t\t\t\t");
        }
        if (joueurs[indexJoueur].etat == 'e')
        {
            printf("\t\t\t\t\t\t\t");
        }
        if (joueurs[indexJoueur].etat == 'h')
        {
            printf("\t\t\t\t\t\t\t");
        }
    }
    printf("\n");


    for (int indexJoueur=0;indexJoueur<3;indexJoueur++)
    {
        for (int i=0;i<joueurs[indexJoueur].tailleMain;i++)
        {
            couleurAffichage(joueurs[indexJoueur].main[i]);
            printf(" ______ ");
        }
        for (int j=0;j<7-joueurs[indexJoueur].tailleMain;j++)
        {
            printf("\t");
        }
    }
    printf("\n");
    for (int indexJoueur=0;indexJoueur<3;indexJoueur++)
    {
        for (int i=0;i<joueurs[indexJoueur].tailleMain;i++)
        {
            couleurAffichage(joueurs[indexJoueur].main[i]);
            printf("|      |");
        }
        for (int j=0;j<7-joueurs[indexJoueur].tailleMain;j++)
        {
            printf("\t");
        }
    }
    printf("\n");
    for (int indexJoueur=0;indexJoueur<3;indexJoueur++)
    {
        for (int i=0;i<joueurs[indexJoueur].tailleMain;i++)
        {
            couleurAffichage(joueurs[indexJoueur].main[i]);
            printf("|      |");
        }
        for (int j=0;j<7-joueurs[indexJoueur].tailleMain;j++)
        {
            printf("\t");
        }
    }
    printf("\n");
    for (int indexJoueur=0;indexJoueur<3;indexJoueur++)
    {
        for (int i=0;i<joueurs[indexJoueur].tailleMain;i++)
        {
            couleurAffichage(joueurs[indexJoueur].main[i]);
            if (joueurs[indexJoueur].main[i].nom != '1')
            {

                printf("|  %c%c  |",joueurs[indexJoueur].main[i].nom,joueurs[indexJoueur].main[i].couleur);
            }
            else
            {
                printf("| 10%c  |",joueurs[indexJoueur].main[i].couleur);
            }
        }
        for (int j=0;j<7-joueurs[indexJoueur].tailleMain;j++)
        {
            printf("\t");
        }
    }
    printf("\n");
    for (int indexJoueur=0;indexJoueur<3;indexJoueur++)
    {
        for (int i=0;i<joueurs[indexJoueur].tailleMain;i++)
        {
            couleurAffichage(joueurs[indexJoueur].main[i]);
            printf("|      |");
        }
        for (int j=0;j<7-joueurs[indexJoueur].tailleMain;j++)
        {
            printf("\t");
        }
    }
    printf("\n");
    for (int indexJoueur=0;indexJoueur<3;indexJoueur++)
    {
        for (int i=0;i<joueurs[indexJoueur].tailleMain;i++)
        {
            couleurAffichage(joueurs[indexJoueur].main[i]);
            printf("|______|");
        }
        for (int j=0;j<7-joueurs[indexJoueur].tailleMain;j++)
        {
            printf("\t");
        }
    }
    printf("\n");
    for (int indexJoueur=0;indexJoueur<3;indexJoueur++)
    {
        setColor(0);
        if (indexJoueur==0)
        {
            printf("Joueur 1 : %d",joueurs[indexJoueur].score);
        }
        if (indexJoueur==1)
        {
            printf("Joueur 2 : %d",joueurs[indexJoueur].score);
        }
        if (indexJoueur==2)
        {
            printf("Joueur 3 : %d",joueurs[indexJoueur].score);
        }
        printf("\t\t\t\t\t\t");
    }
    printf("\n");
    for (int indexJoueur=0;indexJoueur<3;indexJoueur++)
    {
        setColor(0);
        printf("Solde : %d | Mise : %d",joueurs[indexJoueur].solde, joueurs[indexJoueur].mise);
        if ((joueurs[indexJoueur].solde >= 100) && (joueurs[indexJoueur].mise >= 100))
        {
            printf("\t\t\t\t");
        }
        else
        {
            printf("\t\t\t\t\t");
        }
    }
    printf("\n");
}
