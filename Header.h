#pragma once
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
#include <time.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#define INF 0x3f3f3f3f
#include <time.h>
#include <fstream>
#include <string>
#include <chrono>
#include <windows.h>
#include "Avion.h"
#include "Aeroport.h"
#include "GrapheAero.h"
#include "Case.h"
#include "Map.h"


using namespace std;

vector<Avion> melanger(vector<Avion> paquet);

vector<Aeroport> melanger(vector<Aeroport> paquet);
int Menu();
vector <Aeroport> RemplissageAeroports();
int  verifAvionL(int AeroDep, vector<Aeroport> aeroport);
int  verifAvionM(int AeroDep, vector<Aeroport> aeroport);
int  verifAvionC(int AeroDep, vector<Aeroport> aeroport);
int NumAvion();
int HeureDep();
int MinuteDep();

void Color(int couleurDuTexte, int couleurDeFond); // fonction d'affichage de couleurs
void gotoligcol(int lig, int col);

int simulationDEPART(int dep, int AERARR,vector<Aeroport> aeroport);
void simulationARRIVE(int arr, int dep, vector<Aeroport> aeroport);








#endif // HEADER_H_INCLUDED
