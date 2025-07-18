#pragma once
#include "proposition.h"
using namespace std;

class Total {
	int total_;
	int vie_; //pour compter le nombre de vies a chaque niveau
	int niveau_; //donne le niveau actuel
	int palier_; //donne le palier de points à atteindre pour passer au niveau suivant
	int meilleurscore_;
public:
	Total(); //Constructeur (on initialise toutes les valeurs)
	int getTotal() { return total_; };
	int getNiveau() { return niveau_; };
	int getVie() { return vie_; };
	int getPalier() { return palier_; };
	int getMeilleurScore() { return meilleurscore_; };
	void setMeilleurScore(int score);
	void calculerTotal(Proposition p);
	void augmenterNiveau(int total); //On augmente d'un niveau et on ajoute 20 au palier à atteindre (on garde le score)
	void sauver(ofstream& ofs) const;
	void charger(ifstream& ifs);
	void sauverMeilleurScore(ofstream& ofs) const;
	void chargerMeilleurScore(ifstream& ifs);
};