#include "Header.h"

vector <Aeroport> RemplissageAeroports()
{

    vector <Aeroport> aeroports;
    Aeroport Paris("Paris.txt");
    Aeroport Bangkok("Bangkok.txt");
    Aeroport CapeTown("CapeTown.txt");
    Aeroport Haiti("Haiti.txt");
    Aeroport LePaz("LePaz.txt");
    Aeroport NewYork("NewYork.txt");
    Aeroport Perth("Perth.txt");

    aeroports.push_back(NewYork);
    aeroports.push_back(Paris);
    aeroports.push_back(Haiti);
    aeroports.push_back(Perth);
    aeroports.push_back(CapeTown);
    aeroports.push_back(LePaz);
    aeroports.push_back(Bangkok);


    int alea;
    Avion c("Court.txt");
    Avion m("Moyen.txt");
    Avion l("Long.txt");

    for (int i = 0; i < aeroports.size(); i++)
    {
        for (int j = 0; j < aeroports.at(i).m_psol; j++)
        {
            alea = rand() % (3 - 1 + 1) + 1;
            if (alea == 1)
            {
                aeroports.at(i).m_liste_avions.push_back(c);
            }
            if (alea == 2)
            {
               
                aeroports.at(i).m_liste_avions.push_back(m);
            }
            if (alea == 3)
            {
                
                aeroports.at(i).m_liste_avions.push_back(l);
            }



        }
    }
    /*
    for (int i = 0; i < aeroports.size(); i++)
    {
        cout << "===========================" << endl;
        cout << aeroports.at(i).m_nom << endl;
        cout << "===========================" << endl;
        for (int j = 0; j < aeroports.at(i).m_psol; j++)
        {
            aeroports.at(i).m_liste_avions.at(j).AfficherAvion();

        }
    }*/
    return aeroports;
}

int  verifAvionC(int AeroDep, vector<Aeroport> aeroport)
{
    int C = 0;
    if (AeroDep == 0)
    {

        for (int i = 0; i < aeroport.at(0).m_psol; i++)
        {
            if (aeroport.at(0).m_liste_avions.at(i).m_type == 'c')
                C++;
            
        }
    }
    if (AeroDep == 1)
    {

        for (int i = 0; i < aeroport.at(1).m_psol; i++)
        {
            if (aeroport.at(1).m_liste_avions.at(i).m_type == 'c')
                C++;
            
        }
    }
    if (AeroDep == 2)
    {

        for (int i = 0; i < aeroport.at(2).m_psol; i++)
        {
            if (aeroport.at(2).m_liste_avions.at(i).m_type == 'c')
                C++;
           
        }
    }
    if (AeroDep == 3)
    {

        for (int i = 0; i < aeroport.at(3).m_psol; i++)
        {
            if (aeroport.at(3).m_liste_avions.at(i).m_type == 'c')
                C++;
        }
    }
    if (AeroDep == 4)
    {

        for (int i = 0; i < aeroport.at(4).m_psol; i++)
        {
            if (aeroport.at(4).m_liste_avions.at(i).m_type == 'c')
                C++;
        }
    }
    if (AeroDep == 5)
    {

        for (int i = 0; i < aeroport.at(5).m_psol; i++)
        {
            if (aeroport.at(5).m_liste_avions.at(i).m_type == 'c')
                C++;
            
        }
    }
    if (AeroDep == 6)
    {

        for (int i = 0; i < aeroport.at(6).m_psol; i++)
        {
            if (aeroport.at(6).m_liste_avions.at(i).m_type == 'c')
                C++;
            
        }
    }
    return C;

}
int  verifAvionM(int AeroDep, vector<Aeroport> aeroport)
{
    int M = 0;
    if (AeroDep == 0)
    {

        for (int i = 0; i < aeroport.at(0).m_psol; i++)
        {
            if (aeroport.at(0).m_liste_avions.at(i).m_type == 'm')
                M++;
        }
    }
    if (AeroDep == 1)
    {

        for (int i = 0; i < aeroport.at(1).m_psol; i++)
        {
          
            if (aeroport.at(1).m_liste_avions.at(i).m_type == 'm')
                M++;
           
        }
    }
    if (AeroDep == 2)
    {

        for (int i = 0; i < aeroport.at(2).m_psol; i++)
        {
            
            if (aeroport.at(2).m_liste_avions.at(i).m_type == 'm')
                M++;
           
        }
    }
    if (AeroDep == 3)
    {

        for (int i = 0; i < aeroport.at(3).m_psol; i++)
        {
            
            if (aeroport.at(3).m_liste_avions.at(i).m_type == 'm')
                M++;
            
        }
    }
    if (AeroDep == 4)
    {

        for (int i = 0; i < aeroport.at(4).m_psol; i++)
        {
            
            if (aeroport.at(4).m_liste_avions.at(i).m_type == 'm')
                M++;
            
        }
    }
    if (AeroDep == 5)
    {

        for (int i = 0; i < aeroport.at(5).m_psol; i++)
        {
            
            if (aeroport.at(5).m_liste_avions.at(i).m_type == 'm')
                M++;
            
        }
    }
    if (AeroDep == 6)
    {

        for (int i = 0; i < aeroport.at(6).m_psol; i++)
        {
            
            if (aeroport.at(6).m_liste_avions.at(i).m_type == 'm')
                M++;
            
        }
    }
    return M;

}
int  verifAvionL(int AeroDep, vector<Aeroport> aeroport)
{
    int L = 0;
    if (AeroDep == 0)
    {

        for (int i = 0; i < aeroport.at(0).m_psol; i++)
        {
            
            if (aeroport.at(0).m_liste_avions.at(i).m_type == 'l')
                L++;
        }
    }
    if (AeroDep == 1)
    {

        for (int i = 0; i < aeroport.at(1).m_psol; i++)
        {
            
            if (aeroport.at(1).m_liste_avions.at(i).m_type == 'l')
                L++;
        }
    }
    if (AeroDep == 2)
    {

        for (int i = 0; i < aeroport.at(2).m_psol; i++)
        {
           
            if (aeroport.at(2).m_liste_avions.at(i).m_type == 'l')
                L++;
        }
    }
    if (AeroDep == 3)
    {

        for (int i = 0; i < aeroport.at(3).m_psol; i++)
        {
            
            if (aeroport.at(3).m_liste_avions.at(i).m_type == 'l')
                L++;
        }
    }
    if (AeroDep == 4)
    {

        for (int i = 0; i < aeroport.at(4).m_psol; i++)
        {
            
            if (aeroport.at(4).m_liste_avions.at(i).m_type == 'l')
                L++;
        }
    }
    if (AeroDep == 5)
    {

        for (int i = 0; i < aeroport.at(5).m_psol; i++)
        {
            
            if (aeroport.at(5).m_liste_avions.at(i).m_type == 'l')
                L++;
        }
    }
    if (AeroDep == 6)
    {

        for (int i = 0; i < aeroport.at(6).m_psol; i++)
        {
            
            if (aeroport.at(6).m_liste_avions.at(i).m_type == 'l')
                L++;
        }
    }
    return L;

}
