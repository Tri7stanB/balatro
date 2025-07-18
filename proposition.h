#pragma once
#include "carte.h"
#include <vector>
#include <fstream>

using namespace std;

class Proposition {
	vector<Carte> proposition_;
	/*int score_;*/
public:
	
	vector<Carte> getProposition() { return proposition_; };
	/*int getScore() { return score_; };*/
	int calculerScore();
	Proposition(vector<Carte>);
	//void setProposition();
	void ajouterCarte(Carte carte);
	void supprimerCarte(Carte carte);
	void sauver(ofstream& ofs) const;
	void charger(ifstream& ifs);
};