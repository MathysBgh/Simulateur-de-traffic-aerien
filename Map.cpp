#include "Map.h"

Map::Map()
{
    //ctor
}




void Map::initialisation()
{
    m_map.resize(52);
    for (int i = 0; i < 52; i++)
        m_map[i].resize(102);

    for (int i = 0;i < 51;i++)
    {
        for (int j = 0;j < 101;j++)
        {
            m_map[i][j].m_affichage = 0; ///Vide
        }
    }

    m_map[0][0].m_affichage = 1;///New York
    m_map[25][0].m_affichage = 1; ///Haïti
    m_map[50][0].m_affichage = 1; ///Le Paz
    m_map[0][40].m_affichage = 1;///Paris
    m_map[50][50].m_affichage = 1;///Cape Town
    m_map[50][100].m_affichage = 1; ///Perth
    m_map[25][100].m_affichage = 1; ///Bangkok

}



void Map::majmap(vector<Avion> avion_en_mvmt)
{
    system("cls");
    initialisation();
    for (int i = 0;i < avion_en_mvmt.size();i++)
    {
        m_map[avion_en_mvmt.at(i).m_pos_x][avion_en_mvmt.at(i).m_pos_y].m_affichage = 2;
    }
}




void Map::afficher()
{
    cout << endl << endl;
    for (int i = 0;i < 51;i++)
    {
        for (int j = 0;j < 101;j++)
        {
            switch (m_map[i][j].m_affichage)
            {
            case 0:
                cout << "."; /// Si c'est vide (99%) du plateau
                break;
            case 1:
                Color(3, 0);
                cout << "O"; /// Si c'est un aéroport
                Color(15, 0);
                    break;
            case 2:
                cout << "A"; /// Si c'est un avion
                    break;
            default:
                cout << " ";
                break;
            }

        }
        cout << endl;
    }
}

