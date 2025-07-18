#pragma once
#include "carte.h"
#include<vector>
using namespace std;

class Pioche {
	vector<Carte> pioche_;
	int taille_;
public:
	Pioche(); //Constructeur et melangeur de la pioche
	vector<Carte>& getPioche() { return pioche_; };
	int getTaille() { return taille_; };
	void setTaille(int taille);
	void sauver(ofstream& ofs) const;
	void charger(ifstream& ifs);
};