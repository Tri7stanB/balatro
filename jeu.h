#pragma once
#include <vector>
#include "carte.h"
#include "pioche.h"
using namespace std;

class Jeu {
	vector<Carte> jeu_;
	int taille_;
public:
	Jeu();
	vector<Carte> getJeu() { return jeu_; };
	int getTaille() { return taille_; };
	void piocher(Pioche &pioche);
	void piocherMultiple(Pioche& pioche);//Pour piocher plusieurs fois a la suite et refaire le jeu
	void supprimerCarte(Carte carte);
	void sauver(ofstream& ofs) const;
	void charger(ifstream& ifs);
};