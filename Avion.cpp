#include "Avion.h"

#include "Avion.h"

Avion::Avion(string nomFichier)
{
    //LECTURE DU FICHIER .TXT
    ifstream ifs{ nomFichier };
    if (!ifs)
        throw runtime_error("Impossible d'ouvrir en lecture " + nomFichier);


    string nom;
    ifs >> nom;
    m_nom = nom;
    if (ifs.fail())
        throw runtime_error("Probleme lecture ");

    char type;
    ifs >> type;
    m_type = type;
    if (ifs.fail())
        throw runtime_error("Probleme lecture ");

    int conso;
    ifs >> conso;
    m_conso = conso;
    if (ifs.fail())
        throw runtime_error("Probleme lecture ");

    int capaCarburant;
    ifs >> capaCarburant;
    m_capacarburant = capaCarburant;
    if (ifs.fail())
        throw runtime_error("Probleme lecture ");
}


Avion::~Avion()
{

}

void Avion::AfficherAvion()
{
    if (m_type == 'c')
    {
        cout << "/////////////////////////////////////////" << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << "////////////// INFORMATION///////////////" << endl;
        cout << "/////////////    COURT    ///////////////" << endl;
        cout << "/////////////  COURRIER   ///////////////" << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << endl;
        cout << endl;
        cout << " CAPACITE: 500 personnes" << endl;
        cout << " CONSOMMATION L/100: 231 L" << endl;
        cout << " STOCKAGE MAXIMALE DE CARBURANT: 2 000 L" << endl;

    }
    if (m_type == 'm')
    {
        cout << "/////////////////////////////////////////" << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << "////////////// INFORMATION///////////////" << endl;
        cout << "/////////////    MOYEN    ///////////////" << endl;
        cout << "/////////////  COURRIER   ///////////////" << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << endl;
        cout << endl;
        cout << " CAPACITE: 5000 personnes" << endl;
        cout << " CONSOMMATION L/100: 740 L" << endl;
        cout << " STOCKAGE MAXIMALE DE CARBURANT: 15 000 L" << endl;

    }
    if (m_type == 'l')
    {
        cout << "/////////////////////////////////////////" << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << "////////////// INFORMATION///////////////" << endl;
        cout << "/////////////    LONG    ///////////////" << endl;
        cout << "/////////////  COURRIER   ///////////////" << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << endl;
        cout << endl;
        cout << " CAPACITE: 15 000 personnes" << endl;
        cout << " CONSOMMATION L/100: 1 100 L" << endl;
        cout << " STOCKAGE MAXIMALE DE CARBURANT: 26 000 L" << endl;

    }
}