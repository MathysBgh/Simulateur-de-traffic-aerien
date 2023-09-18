#include "header.h"
#include"Header.h"


vector<Avion> melanger(vector<Avion> paquet)
{
    srand(time(NULL));
    std::random_shuffle(paquet.begin(), paquet.end());
    return paquet;
}

vector<Aeroport> melanger(vector<Aeroport> paquet)
{
    srand(time(NULL));
    random_shuffle(paquet.begin(), paquet.end());
    return paquet;
}
int Menu()
{
    int choix;
    cout << "/////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "///////////////////    BIENVENUE SUR NOTRE SIMULATION     ///////////////////" << endl;
    cout << "///////////////////           DE TRAFIC AERIEN            ///////////////////" << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "///////////////////  1. INFORMATION DES AEROPORT          ///////////////////" << endl;
    cout << "///////////////////  2. INFORMATION SUR LES AVIONS        ///////////////////" << endl;
    cout << "///////////////////  3. COMMANDER UN VOL                  ///////////////////" << endl;
    cout << "///////////////////  4. VOIR LE TRAFFIC AERIEN            ///////////////////" << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////" << endl;
    do {
        cout << "->Faites votre choix :";
        cin >> choix;
    } while (choix < 0 || choix>4);

    return choix;
}

int NumAvion()
{
    int NUM =rand()%(9999-1000+1)+1000;
    return NUM;

 }

int HeureDep()
{
    int NUM = rand() % (23 - 0 + 1) + 0;
    return NUM;

}
int MinuteDep()
{
    int NUM = rand() % (59 - 0 + 1) + 0;
    return NUM;

}

void Color(int couleurDuTexte, int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte); //Définit les attributs des caractères écrits dans le tampon d'écran de la console par la fonction
}

void gotoligcol(int lig, int col)
{
    ///ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord); // handle vers le tampon d'écran
}