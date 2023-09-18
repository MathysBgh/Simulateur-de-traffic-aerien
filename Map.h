#pragma once
#include "Header.h"

class Map
{
public:
    vector<vector<Case>> m_map; //creation d'un vecteur de type case

    Map();
    void majmap(vector<Avion> avion_en_mvmt);
    void afficher();
    void initialisation();

};
