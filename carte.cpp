#include "carte.h"
#include <iostream>
using namespace std;

Carte::Carte(int valeur, string couleur) : valeur_(valeur), couleur_(couleur) {};//Constructeur de Carte

Carte::Carte() : valeur_(0), couleur_("") {};//Constructeur de Carte

void Carte::afficher() { //Affichage d'une carte sous le format (valeur,couleur)
	cout << "(" << valeur_ << ", " << couleur_ << ")";
}

void Carte::sauver(ofstream& ofs) const {
	ofs << valeur_ << endl;
	ofs << couleur_ << endl;
};

void Carte::charger(ifstream& ifs) {
	ifs >> valeur_;
	ifs >> couleur_;
};