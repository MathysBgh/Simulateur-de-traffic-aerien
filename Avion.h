#pragma once
#ifndef AVION_H
#define AVION_H

#include "Header.h"
//class Aeroport;
using namespace std;

class Avion
{

private:
    
    //vector <Avion> Les_Avions;

public:
    string m_nom;
    char m_type;
    int m_conso;
    int m_capacarburant;
    int m_pos_x;
    int m_pos_y;
    ~Avion();
    Avion(string nomFichier);

    void AfficherAvion();

};
#endif // AVION_H