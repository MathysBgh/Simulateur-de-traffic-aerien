#pragma once
#ifndef AEROPORT_H
#define AEROPORT_H
#include "Header.h"

using namespace std;

class Avion;

class Aeroport
{
private:
    
public:
    pair<int, int>m_coordonees;
    string m_nom;
    vector <Avion> m_liste_avions;
    vector< Avion> m_piste_avions;
    int m_piste;
    int m_psol;
    int m_AttAuSol;
    int m_TmpAcceAuPiste;
    int m_AttDecolage;
    int m_antiCollision;
    int m_BcleAttente;

    //void recupAvion(std::vector<Avion>liste_avions);
    
    Aeroport(string nomFichier)
    {
        //LECTURE DU FICHIER .TXT
        ifstream ifs{ nomFichier };
        if (!ifs)
            throw runtime_error("Impossible d'ouvrir en lecture " + nomFichier);

        //lecture de l'ordre du graphe
        string nom;
        ifs >> nom;
        m_nom = nom;
        if (ifs.fail())
            throw runtime_error("Probleme lecture ");


        pair<int, int> coord;
        ifs >> coord.first;
        m_coordonees.first = coord.first;
        ifs >> coord.second;
        m_coordonees.second = coord.second;
        if (ifs.fail())
            throw runtime_error("Probleme lecture");


        //lecture de la taille du graphe
        int piste;
        ifs >> piste;
        m_piste = piste;
        if (ifs.fail())
            throw runtime_error("Probleme lecture");

        int psol;
        ifs >> psol;
        m_psol = psol;
        if (ifs.fail())
            throw runtime_error("Probleme lecture ");

        int AttAuSol;
        ifs >> AttAuSol;
        m_AttAuSol = AttAuSol;
        if (ifs.fail())
            throw runtime_error("Probleme lecture ");

        int tmpAcceAuPiste;
        ifs >> tmpAcceAuPiste;
        m_TmpAcceAuPiste = tmpAcceAuPiste;
        if (ifs.fail())
            throw runtime_error("Probleme lecture  ");

        int AttDeccolage;
        ifs >> AttDeccolage;
        m_AttDecolage = AttDeccolage;
        if (ifs.fail())
            throw runtime_error("Probleme lecture ");

        int antiCollision;
        ifs >> antiCollision;
        m_antiCollision = antiCollision;
        if (ifs.fail())
            throw runtime_error("Probleme lecture");

        int bcleAttente;
        ifs >> bcleAttente;
        m_BcleAttente = bcleAttente;
        if (ifs.fail())
            throw runtime_error("Probleme lecture");

    }


    void afficher()
    {
        cout << "Nom : " << m_nom << endl;
        cout << "Coordonnees: " << m_coordonees.first << ":" << m_coordonees.second << endl;
        cout << "Nombre de pistes : " << m_piste << endl;
        cout << "Nombre de places au sol :  " << m_psol << endl;
        cout << "Delai d'attente au sol : " << m_AttAuSol << " UT" << endl;
        cout << "Temps d'acces aux pistes : " << m_TmpAcceAuPiste << " UT" << endl;
        cout << "Delai d'anticollision : " << m_antiCollision << "UT" << endl;
        cout << "Temps de decollage ou d'atterissage : " << m_AttDecolage << " UT" << endl;
        cout << "Duree de la boucle d'attente en vol : " << m_BcleAttente << " UT" << endl << endl;
    }
    ~Aeroport()
    {

    }
    
};

#endif // HEADER_H_INCLUDED
/*
void Aeroport::recupAvion(std::vector<Avion> liste_avions)
{
    for(int i = Les_Avions.size(); )
}*/