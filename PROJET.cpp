#include "Header.h"

using namespace std;

int main()
{
    clock_t time_req;
    srand(time(NULL));
    int choix = 0;

    time_req = clock(); // clock(); renvoie le temps en je sais pas je pense milliseconde, j'ai mis un exemple pour que vous comprenez compilez
  /* //EXEMPLE
    do
    {
        cout << clock() << endl;
    } while (1);
    //en bas en commentaire ya les differente fonction et comment on les appel (en commentaire) :) */


    //Chargement des fichiers
    Aeroport NewYork("NewYork.txt");
    Aeroport Paris("Paris.txt");
    Aeroport CapeTown("CapeTown.txt");
    Aeroport Haiti("Haiti.txt");
    Aeroport LePaz("LePaz.txt");
    Aeroport Perth("Perth.txt");
    Aeroport Bangkok("Bangkok.txt");
    Avion M("Moyen.txt");
    Avion C("Court.txt");
    Avion L("Long.txt");
    GrapheAero l{ "GrapheAero.txt" }; //Récupération du graphe
    GrapheAero c{ "GrapheC.txt" };
    GrapheAero m{ "GrapheM.txt" };

    //Déclaration variables
    vector <Aeroport> aeroports = RemplissageAeroports();
    vector<Avion> avion_en_mvmt;
    Map mapp;
    mapp.initialisation();

    //MENU Début    
    //Creation du menu avec les différents choix
    choix = Menu();

    if (choix == 1)
    {


        cout << "/////////////////////////////////////////////" << endl;
        cout << "//////////////     AEROPORT     /////////////" << endl;
        cout << "/////////////////////////////////////////////" << endl;
        cout << "/////////////////////////////////////////////" << endl;
        Paris.afficher();
        cout << endl; cout << endl;
        Bangkok.afficher();
        cout << endl; cout << endl;
        CapeTown.afficher();
        cout << endl; cout << endl;
        Haiti.afficher();
        cout << endl; cout << endl;
        LePaz.afficher();
        cout << endl; cout << endl;
        NewYork.afficher();
        cout << endl; cout << endl;
        Perth.afficher();
        cout << endl; cout << endl;
        cout << "/////////////////////////////////////////////" << endl;
        cout << "/////////////////////////////////////////////" << endl;

    }
    if (choix == 2)
    {
        ///Chargement des avions en fonction de leurs type

        M.AfficherAvion();
        cout << endl;
        cout << endl;
        C.AfficherAvion();
        cout << endl;
        cout << endl;
        L.AfficherAvion();
        cout << endl;
        cout << endl;
    }
    if (choix == 3)
    {

        ///DIJKSTRA Menu
        cout << "/////////////////////////////////////////////" << endl;
        cout << "/////////////////////////////////////////////" << endl;
        cout << "//////////   0. NewYork   ///////////////////" << endl;
        cout << "//////////   1. Paris     ///////////////////" << endl;
        cout << "//////////   2. Haiti     ///////////////////" << endl;
        cout << "//////////   3. Perth     ///////////////////" << endl;
        cout << "//////////   4. CapeTown  ///////////////////" << endl;
        cout << "//////////   5. LePaz     ///////////////////" << endl;
        cout << "//////////   6.Bangkok    ///////////////////" << endl;
        cout << "/////////////////////////////////////////////" << endl;
        cout << "/////////////////////////////////////////////" << endl;
        int som_init, som_fin;

        ///saisie du premier sommet
        std::cout << " Quel Aeroport de depart voulez vous choisir ? :" << std::endl;
        std::cin >> som_init;
        std::cout << std::endl << "Quel Aeroport d'arrive voulez vous choisir :" << std::endl;
        std::cin >> som_fin;
        std::cout << std::endl << std::endl;
        int M;
        int C;
        int L;

        /*On vérifie quelles avions sont disponibles dans l'aéroport*/
        C = verifAvionC(som_init, aeroports);
        M = verifAvionM(som_init, aeroports);
        L = verifAvionL(som_init, aeroports);
        /*Affichage du nombre de chaque avion */
        cout << "//////////////////////////////////////////" << endl;
        cout << "/////////////  COURT COURRIER: " << C << " //////////" << endl;
        cout << "/////////////  MOYEN COURRIER: " << M << " //////////" << endl;
        cout << "/////////////  LONG COURRIER:  " << L << " //////////" << endl;
        cout << "//////////////////////////////////////////" << endl;

        if ((C != 0) && (som_init != 6) && (som_fin != 6) && (som_init != 3) && (som_fin != 3))
        {
            cout << "[TRAJET COURT COURRIER] " << endl;
            c.dijkstra(c.getSommets()[som_init], c.getSommets()[som_fin]); //Affichage du trajet en cour courrier 

        }
        else
            cout << " !!!!!!!!!!! AUCUN TRAJET DISPONIBLE EN COURT COURRIER !!!!!!!!!!!" << endl; // Affichage si il n'y a pas le type d'avion Court courrier

        if ((M != 0) && (som_init != 6) && (som_fin != 6))
        {
            cout << "[TRAJET MOYEN COURRIER] " << endl;
            m.dijkstra(m.getSommets()[som_init], m.getSommets()[som_fin]); //Affichage du trajet en moyen courrier


        }
        else
            cout << " !!!!!!!!!!! AUCUN TRAJET DISPONIBLE EN MOYEN COURRIER !!!!!!!!!!!" << endl;// Affichage si il n'y a pas le type d'avion MOYEN courrier

        if (L != 0)
        {
            cout << "[TRAJET LONG COURRIER] " << endl;
            l.dijkstra(l.getSommets()[som_init], l.getSommets()[som_fin]); //Affichage du trajet en long courrier

        }
        else
            cout << " !!!!!!!!!!! AUCUN TRAJET DISPONIBLE EN LONG COURRIER !!!!!!!!!!!" << endl;// Affichage si il n'y a pas le type d'avion LONG courrier








    }


    if (choix == 4)
    {
        int i;
        int Arrive = rand() % (6 - 0 + 1) + 0;
        int Depart;
        int Numero;
        do
        {
            Depart = Arrive;
            Arrive = rand() % (6 - 0 + 1) + 0;
            //int Depart=0;
            Numero = simulationDEPART(Depart,Arrive,aeroports);
            simulationARRIVE(Arrive,Depart, aeroports);
    
            cout << endl;

           // cin >>i;

            cout << endl;
            
            
        } while (true);
        
        /*
        system("cls");
        avion_en_mvmt.push_back(C); // Map déja faite sans avion, plus qu'à faire déplacer les avions dessus grâce aux coordonnées (modifier l'algo Dijkstra)
        mapp.afficher();*/
    }
    //MENU FIN
    
}




        //Avion Boeing("Court.txt");
       


        //aeroports.at(0).m_liste_avions.push_back(Boeing);

        //Mélange et cout pour voir si il est bon (10:14 06/04)
       /* aeroports = melanger(aeroports);

        //J'affiche pour vérifier le bon fonctionnement du mélange
        for (int i = 0; i < 7; i++)
        {
            cout << aeroports.at(i).m_nom << endl;
        }
        */
        //Ici on va attribuer à chaque aéroport ses avions selon sa capacité... (à finaliser)


        


       

       



    
    
    
    







/*
/// kruskalALgo
GrapheAero g{ "GrapheAero.txt" };

g.afficherGraphAero(); //Affiche le graphe aerport

cout << "\n\nL arbre couvrant tous les Aeroports avec le moins de distance est : \n\n";
int poid_total = g.kruskalALgo(); //Affiche le graphe kruskal aeroport et renvoie le poids total

cout << "\nLa distance total est de : " << poid_total;
cout << endl;
cout << endl;
cout << endl;
*/






