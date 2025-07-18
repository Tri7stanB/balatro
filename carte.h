#pragma once
#include <string>
#include <fstream>
using namespace std;

class Carte {
	int valeur_;
	string couleur_;
public:
	Carte();
	Carte(int valeur, string couleur);
	int getValeur() { return valeur_; };
	string getCouleur() { return couleur_; };
	/*void setValeur(int valeur);
	void setCouleur(string couleur);*/
	void afficher();
	void sauver(ofstream& ofs) const;
	void charger(ifstream& ifs);
};