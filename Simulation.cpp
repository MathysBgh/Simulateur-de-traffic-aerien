#include "Header.h"
#include <vector>


int simulationDEPART(int AER,int AERARR,vector<Aeroport> aeroport)
{
	/*EN GROS ICI ON SIMULE LES TRAJETS AUTOMATIQUE
	On a un aeroport de depart générer, puis un aeroport
	d'arrive generer. Ensuite on choisi aleatoirement le type
	d'avion puis on l'ajoute sur la piste puis on l'enlève du parking
	ensuite je vaus faire un sous programme pour remplir l'aeroport
	d'arrivée. (Pour savoir c'est lequel je retourne un entier )*/
	
	
	//int AER = dep; //j'ai pris juste New YORK pour commencer 
	
	
	int NUMA = NumAvion();

	cout << "-> AEROPORT DE DEPART: " << aeroport.at(AER).m_nom << endl;
	cout << "-> AEROPORT D'ARRIVE: " << aeroport.at(AERARR).m_nom << endl;
	cout << endl;
	

	
		int AVI = rand() % (3 - 1 + 1) + 1; //on tire un avion au hasard pour la simulation 
		//Si on tombe sur un avion LONG COURRIER
		if (AVI == 3)
		{
			int VL = verifAvionL(AER, aeroport); //récupère les avions existant
			if (VL != 0)
			{
				for (int i = 0; i < aeroport.at(0).m_psol; i++) //parcour de l'aeroport 
				{
					if (aeroport.at(AER).m_liste_avions.at(i).m_type == 'l') // on prend le premeir long courrier
					{
						aeroport.at(AER).m_piste_avions.push_back(aeroport.at(AER).m_liste_avions.at(i)); // on l'ajoute sur les pistes
						aeroport.at(AER).m_liste_avions.pop_back(); //on le supprime du parking
						cout << "AVION LONG COURRIER DE NUMERO " << NUMA << " EN DIRECTION DE" << aeroport.at(AERARR).m_nom << endl;
						i = aeroport.at(AER).m_psol; // on force l'arret de la boucle
					}
				}
			}
		}
		//Si on tombe sur un Avion MOYEN COURRIER
		if (AVI == 2)
		{
			int VM = verifAvionM(AER, aeroport); //recupère le nombre d'avion existant
			cout << VM << endl;;
			if (VM != 0)
			{
				for (int i = 0; i < aeroport.at(AER).m_psol; i++) //Parcour du vector
				{
					if (aeroport.at(AER).m_liste_avions.at(i).m_type == 'm') //le premier qu'on trouve on prend 
					{
						aeroport.at(AER).m_piste_avions.push_back(aeroport.at(AER).m_liste_avions.at(i)); // on l'ajoute à la piste 
						aeroport.at(AER).m_liste_avions.pop_back(); // on l'nlève du parking
						cout << "AVION MOYEN COURRIER DE NUMERO " << NUMA << " EN DIRECTION DE" << aeroport.at(AERARR).m_nom << endl;
						i = aeroport.at(AER).m_psol; //on force l'arret de la boucle
					}
				}
			}
		}
		//Si on tombe sur un Avion COURT COURRIER
		if (AVI == 0)
		{
			int VC = verifAvionC(AER, aeroport); //recupère le nombre d'avion existant
			//cout << VC << endl;;
			if (VC != 0)
			{
				for (int i = 0; i < aeroport.at(AER).m_psol; i++) //Parcour du vector
				{
					if (aeroport.at(AER).m_liste_avions.at(i).m_type == 'c') //le premier qu'on trouve on prend 
					{
						aeroport.at(AER).m_piste_avions.push_back(aeroport.at(AER).m_liste_avions.at(i)); // on l'ajoute à la piste 
						aeroport.at(AER).m_liste_avions.pop_back(); // on l'nlève du parking
						cout << "AVION COUR COURRIER DE NUMERO "<< NUMA << " EN DIRECTION DE" << aeroport.at(AERARR).m_nom<<endl;
						i = aeroport.at(AER).m_psol; //on force l'arret de la boucle
					}
				}
			}
		}
		

		cout << aeroport.at(AER).m_piste_avions.size()<<endl;
		//aeroport.at(AER).m_piste_avions.at(0).AfficherAvion();

		int tmp=aeroport.at(AER).m_AttAuSol+ aeroport.at(AER).m_AttDecolage+aeroport.at(AER).m_TmpAcceAuPiste*1000;

		cout << tmp << endl;
		int tempo=clock();
		do
		{
			
		} while (clock() < tempo + tmp);
;		if (clock() == tempo + tmp)
		{
			cout << "->L'avion est Partit de: "<< aeroport.at(AER).m_nom << endl;
		}

		//aeroport.at(AER).m_piste_avions.pop_back(); 
		//cout << aeroport.at(AER).m_piste_avions.size() << endl;
		
		return NUMA;
	
}

void simulationARRIVE(int arr,int dep, vector<Aeroport> aeroport)
{
	if (aeroport.at(arr).m_piste_avions.size() != aeroport.at(arr).m_piste)
	{
		int tmp = aeroport.at(arr).m_AttAuSol + aeroport.at(arr).m_AttDecolage + aeroport.at(arr).m_TmpAcceAuPiste * 1000;
		int tempo = clock();
		do
		{
		} while (clock() < tempo + tmp);
		;		if (clock() == tempo + tmp)
		{
			cout << "-> L'avion est ARRIVE a: " << aeroport.at(arr).m_nom << endl;
		}
		aeroport.at(arr).m_piste_avions = aeroport.at(dep).m_piste_avions;
		
	}
}