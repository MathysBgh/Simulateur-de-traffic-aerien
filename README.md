# Simulateur de Trafic Aérien

Le Simulateur de Trafic Aérien est un projet de simulation de gestion du trafic aérien en C++. Il vous permet de gérer un réseau d'aéroports, de suivre les déplacements d'avions, de planifier des vols et de simuler des scénarios de trafic aérien.

![Aéroport](lien_vers_une_image_de_aeroport.png)

## Table des matières

- [Introduction](#introduction)
- [Fonctionnalités](#fonctionnalités)
- [Exemple de Code](#exemple-de-code)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Contributions](#contributions)
- [Licence](#licence)

## Introduction

Le Simulateur de Trafic Aérien est un projet complet pour la gestion du trafic aérien. Il peut être utilisé à des fins éducatives, pour des simulations réalistes ou pour des jeux de stratégie basés sur l'aviation. Le projet est écrit en C++ et utilise des fichiers de données pour définir les aéroports, les avions et les connexions entre eux.

## Fonctionnalités

- **Affichage des Informations sur les Aéroports** : Vous pouvez afficher les détails de chaque aéroport, y compris son nom, emplacement, pistes de décollage, etc.

- **Affichage des Informations sur les Avions** : Le simulateur répertorie les avions disponibles, classés par type (court-courrier, moyen-courrier, long-courrier) et affiche leurs caractéristiques.

- **Calcul des Itinéraires de Vol** : L'algorithme de Dijkstra est utilisé pour calculer le chemin le plus court entre deux aéroports, en fonction de la disponibilité des avions.

- **Simulation de Trafic Aérien** : Vous pouvez lancer des simulations de trafic aérien avec des départs et des arrivées aléatoires entre les aéroports.

## Exemple de Code

```cpp
#include "Header.h"
using namespace std;

int main()
{
    // Code source du simulateur
}
