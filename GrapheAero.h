    #pragma once
#include "Header.h"

using namespace std;

typedef  pair<int, int> iPair;

//Utile a Dijskra
class Sommet
{
private:
    //numéro du sommet
    int m_num;
    //chaque sommet possède la liste de ses successeurs
    //Vector de pairs, un poids int et un sommet de type sommet
    std::vector<std::pair<int, Sommet*>> m_successeurs;
    //Chaque sommet a un predecesseur
    Sommet* m_predecesseur;
public:
    //CONSTRUCTEUR
    Sommet(int num) :m_num{ num }, m_predecesseur(0){};
    ~Sommet() {}

    //ACCESSEURS
    inline int getNum();
    Sommet* getPredecesseur();
    std::vector<std::pair<int, Sommet*>>& getSuccesseurs();

    //Setter
    void setNewPredecesseur(Sommet* s);

    //METHODES

    //methode pour ajouter successeurs au sommet
    void ajouterSucc(int poids, Sommet* s);
};


//Manipulation du graphe
struct GrapheAero
{
private:
    int m_ordre, m_taille;
public:

    int V, E;
    
    vector< pair<int, iPair> > graphe;
    std::vector<Sommet*> m_sommets;

    void ggraph(int V, int E); 
    void addEdge(int u, int v, int w);
    
    //Récuperation fichier graphe
    GrapheAero(std::string nomFichier);
    
    std::vector<Sommet*> getSommets();

    //Afficher le graphe des aeroports
    void afficherGraphAero();

    //Affiche le graphe kruskal
    inline int kruskalALgo();
    
    //Affiche le chemin le plus court entre deux aeroport
    void dijkstra(Sommet* depart, Sommet* arrivee);
    
};

//utile a Kruskal
struct verifParent
{
private:

public:
    int* parent, * prank;
    int n;

    verifParent(int n);
    int verif(int u);
    void verif2(int x, int y);
    
};



inline int GrapheAero::kruskalALgo()
{
    int poid_total = 0;
    vector< pair<int, iPair> >::iterator it;
    string A1;
    string A2;

    sort(graphe.begin(), graphe.end());

    verifParent uv(V);

    for (it = graphe.begin(); it != graphe.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        int set_u = uv.verif(u);
        int set_v = uv.verif(v);

        if (set_u != set_v)
        {
            if (u == 0) A1 = "NewYork";
            if (u == 1) A1 = "Paris";
            if (u == 2) A1 = "Haiti";
            if (u == 3) A1 = "Perth";
            if (u == 4) A1 = "CapeTown";
            if (u == 5) A1 = "LaPaz";
            if (u == 6) A1 = "Bankok";

            if (u == 0) A2 = "NewYork";
            if (v == 1) A2 = "Paris";
            if (v == 2) A2 = "Haiti";
            if (v == 3) A2 = "Perth";
            if (v == 4) A2 = "CapeTown";
            if (v == 5) A2 = "LaPaz";
            if (v == 6) A2 = "Bankok";
            cout << A1 << " - " << A2 << " -> distance : " << it->first << endl;
            poid_total += it->first;
            uv.verif2(set_u, set_v);
        }
    }
    return poid_total;
}


inline void GrapheAero::afficherGraphAero()
{
    string A1, A2;
    std::cout << endl;
    std::cout << m_ordre << " Aeroports actifs. " << std::endl;
    std::cout << "Connexions et distance entre Aeroports : " << std::endl;
    std::cout << endl;
    vector< pair<int, iPair> >::iterator it;
    for (it = graphe.begin(); it != graphe.end(); it++)
    {
        
        if (it->second.first == 0) A1 = "NewYork";
        if (it->second.first == 1) A1 = "Paris";
        if (it->second.first == 2) A1 = "Haiti";
        if (it->second.first == 3) A1 = "Perth";
        if (it->second.first == 4) A1 = "CapeTown";
        if (it->second.first == 5) A1 = "LaPaz";
        if (it->second.first == 6) A1 = "Bankok";

        if (it->second.second == 0) A2 = "NewYork";
        if (it->second.second == 1) A2 = "Paris";
        if (it->second.second == 2) A2 = "Haiti";
        if (it->second.second == 3) A2 = "Perth";
        if (it->second.second == 4) A2 = "CapeTown";
        if (it->second.second == 5) A2 = "LaPaz";
        if (it->second.second == 6) A2 = "Bankok";
        cout << A1 << " - " << A2 << "  -> distance : " << it->first << endl;
        it++;
    }
}




/*
NewYork 0
Paris 1
Haiti 2
Perth 3
CapeTown 4
LaPaz 5
Bankok 6
*/