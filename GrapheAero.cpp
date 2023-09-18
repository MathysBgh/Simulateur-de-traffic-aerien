#include "Header.h"




///////////////////////SOMMET/////////////////////////

inline int Sommet::getNum()
{
    return m_num;
}

Sommet* Sommet::getPredecesseur()
{ 
    return m_predecesseur; 
}

std::vector<std::pair<int, Sommet*>>& Sommet::getSuccesseurs()
{ 
    return m_successeurs; 
}

void Sommet::setNewPredecesseur(Sommet* s)
{ 
    m_predecesseur = s; 
}

void Sommet::ajouterSucc(int poids, Sommet* s)
{
    m_successeurs.push_back(std::make_pair(poids, s));
}


///////////////////////GRAPHE_AEROPORT/////////////////////////

void GrapheAero::ggraph(int V, int E)
{
    this->V = V;
    this->E = E;
}

void GrapheAero::addEdge(int u, int v, int w)
{
    graphe.push_back({ w, {u, v} });
}

GrapheAero::GrapheAero(std::string nomFichier)
{
    std::ifstream ifs{ nomFichier };
    if (!ifs)
        throw std::runtime_error("Impossible d'ouvrir en lecture " + nomFichier);

    int ordre;
    ifs >> ordre;
    m_ordre = ordre;
    V = ordre;
    if (ifs.fail())
        throw std::runtime_error("Probleme lecture ordre du graphe");

    int taille;
    ifs >> taille;
    m_taille = taille;
    E = taille;
    if (ifs.fail())
        throw std::runtime_error("Probleme lecture taille du graphe");

    for (int i = 0; i < ordre; ++i)
        m_sommets.push_back(new Sommet{ i });

    int num1, num2, poids;
    for (int i = 0; i < taille; ++i)
    {
        ifs >> num1 >> num2 >> poids;
        if (ifs.fail())
            throw std::runtime_error("Probleme lecture arc");
        graphe.push_back({ poids, {num1, num2} });
        m_sommets[num1]->ajouterSucc(poids, m_sommets[num2]);
    }
    ggraph(V, E);
}

std::vector<Sommet*> GrapheAero::getSommets() 
{ 
    return m_sommets;
}



void GrapheAero::dijkstra(Sommet* depart, Sommet* arrivee)
{
    //creation d'un tableau de booléen pour différencier les sommets non marques de ceux qui le sont
    bool* decouvert = new bool[m_sommets.size() + 1];
    string P, P1;
    //Vector qui stock les ditances de tous les points au sommet initial
    //choisi par l'utilisateur
    std::vector<int>distance;
    for (int j = 0; j < m_ordre; j++)
    {
        distance.push_back(INF);//on initialise pour tous les points, leur distance=Infini
    }

    //on initialise le vector à nul

    for (unsigned int i = 0; i < m_sommets.size(); i++)
    {
        decouvert[i] = false;//false si pas marqué, on met donc tous les sommets à non marqué

    }

    //priority queue cree afin de stocker les successeurs du sommet actuel
    //permettra de mettre à la premiere position de la queue, le sommet avec la pondération plus
    //petite partant du sommet initial
    std::priority_queue< std::pair<int, Sommet*>, std::vector<std::pair<int, Sommet*>>, std::greater<std::pair<int, Sommet*>> >liste;

    //On ajoute le sommet initial a la priority queue
    liste.push(make_pair(0, depart));
    //on met à 0 la distance du point initial à lui meme
    distance[depart->getNum()] = 0;

    //tant qu’il reste des sommets non marqués
    while (!liste.empty())
    {
        //On cree un sommet actuel pour y travailler dessus
        int actuel;
        actuel = liste.top().second->getNum();
        liste.pop();
        decouvert[actuel] = true;//On sort le sommet de la ppriority queue et on le marque


        //on parcours tous les successeurs du sommet actuel
        for (int i = 0; i < getSommets()[actuel]->getSuccesseurs().size(); i++)
        {


            //Pour chaque successeur non marqué x de s (Non découvert):
            if (decouvert[getSommets()[actuel]->getSuccesseurs()[i].second->getNum()] != true)
            {

                int w = getSommets()[actuel]->getSuccesseurs()[i].first;
                int v = getSommets()[actuel]->getSuccesseurs()[i].second->getNum();//soit v le numero d'un des succeseurs du sommet actuel

                //si la distance du successeur au sommet initial > la distance du sommet actuel au sommet initial + poids du sommet actuel au predecesseur actuel
                if (distance[v] > (distance[actuel] + w))
                {
                    //pour chaque succeseur du sommet actuel, on lui met à jour son nouveau predecesseur
                    //ainsi que sa nouvelle distance au sommet initial
                    getSommets()[actuel]->getSuccesseurs()[i].second->setNewPredecesseur(getSommets()[actuel]);
                    distance[v] = distance[actuel] + w;

                    //On ajoute les nouveaux candidats sommets pour le marquage
                    liste.push(make_pair(distance[v], getSommets()[actuel]->getSuccesseurs()[i].second));

                }

            }

        }

    }

    //on affiche le parcours le plus court selon la ponération
    if (arrivee->getNum() == 0) P = "NewYork";
    if (arrivee->getNum() == 1) P = "Paris";
    if (arrivee->getNum() == 2) P = "Haiti";
    if (arrivee->getNum() == 3) P = "Perth";
    if (arrivee->getNum() == 4) P = "CapeTown";
    if (arrivee->getNum() == 5) P = "LaPaz";
    if (arrivee->getNum() == 6) P = "Bankok";

    if (depart->getNum() == 0) P1 = "NewYork";
    if (depart->getNum() == 1) P1 = "Paris";
    if (depart->getNum() == 2) P1 = "Haiti";
    if (depart->getNum() == 3) P1 = "Perth";
    if (depart->getNum() == 4) P1 = "CapeTown";
    if (depart->getNum() == 5) P1 = "LaPaz";
    if (depart->getNum() == 6) P1 = "Bankok";
    //std::cout << "Le chemin le plus court en partant de " << P1 << " pour aller " << P << " est : ";
    int D;
    D = distance[arrivee->getNum()];
    
    Sommet* tmp = NULL;
    tmp = arrivee;
    if (arrivee->getNum() == 0) P = "NewYork";
    if (arrivee->getNum() == 1) P = "Paris";
    if (arrivee->getNum() == 2) P = "Haiti";
    if (arrivee->getNum() == 3) P = "Perth";
    if (arrivee->getNum() == 4) P = "CapeTown";
    if (arrivee->getNum() == 5) P = "LaPaz";
    if (arrivee->getNum() == 6) P = "Bankok";
    cout << endl;

    int NUM = NumAvion();
    cout << "UN TRAJET EST DISPONIBLE : " << endl;
    cout << "HEURE DE DEPART: " << HeureDep() << ":" << MinuteDep() << " NUMERO: " << NUM << endl;
    cout << endl;
    std::cout <<" -> "<< P<<endl;

    int i = 0;
    while (arrivee != NULL)
    {
        
        tmp = tmp->getPredecesseur();
        if (tmp->getNum() == 0) P = "NewYork";
        if (tmp->getNum() == 1) P = "Paris";
        if (tmp->getNum() == 2) P = "Haiti";
        if (tmp->getNum() == 3) P = "Perth";
        if (tmp->getNum() == 4) P = "CapeTown";
        if (tmp->getNum() == 5) P = "LaPaz";
        if (tmp->getNum() == 6) P = "Bankok";
       
        
       
        std::cout  <<" -> " << P << endl;
        i++;
        if (tmp == depart)
        {
            arrivee = NULL;
        }
    }
    cout << endl;
    if (i != 1)
    {
        cout << "Il y auras donc " << i << " escales" << endl;
    }
    cout << endl;
    cout << "La distance parcourue par ce chemin est de : " << D << "km" << std::endl << std::endl;
    cout << endl;
}





///////////////////////VERIFPARENT KRUSKAL ISSUE/////////////////////////


verifParent::verifParent(int n)
{
    this->n = n;
    parent = new int[8];
    prank = new int[8];

    for (int i = 0; i <= n; i++)
    {
        prank[i] = 0;
        parent[i] = i;
    }
}

int verifParent::verif(int u)
{
    if (u != parent[u])
        parent[u] = verif(parent[u]);
    return parent[u];
}

void verifParent::verif2(int x, int y)
{
    x = verif(x), y = verif(y);

    if (prank[x] > prank[y])
        parent[y] = x;
    else
        parent[x] = y;

    if (prank[x] == prank[y])
        prank[y]++;
}

