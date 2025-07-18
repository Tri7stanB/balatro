#include "pioche.h"
#include "carte.h"
#include <vector>
#include <ctime>
using namespace std;

Pioche::Pioche() {
	pioche_ = {};
	taille_ = 52;
	for (int i = 2; i < 15; i++) { //on ajoute les carreaux du 2 à l'As (représenté par l'entier 14)
		Carte carte(i, "ca");
		pioche_.push_back(carte);
	}
	for (int i = 2; i < 15; i++) {//on ajoute les coeurs du 2 à l'As
		Carte carte(i, "co");
		pioche_.push_back(carte);
	}
	for (int i = 2; i < 15; i++) {//on ajoute les trefles du 2 à l'As
		Carte carte(i, "tr");
		pioche_.push_back(carte);
	}
	for (int i = 2; i < 15; i++) {//on ajoute les piques du 2 à l'As
		Carte carte(i, "pi");
		pioche_.push_back(carte);
	}
	// On mélange la pioche à l'aide de l'algorithme de Fisher-Yates
	srand(static_cast<unsigned int>(time(nullptr)));//Pour initialiser le générateur de nombres pseudo-aléatoires 
	int n = pioche_.size(); //
	for (int i = n - 1; i > 0; --i) { //On parcourt la liste de manière décroissante
		int j = rand() % (i + 1); //On prend un nombre aleatoire entre 0 et i
		swap(pioche_[i], pioche_[j]); //On échange les deux éléements pour mélanger
	}
}

void Pioche::setTaille(int taille) {
	taille_ = taille;
};

void Pioche::sauver(ofstream& ofs) const {
	ofs << taille_ << endl;
	for (int i = 0; i < pioche_.size() ; i++) {
		pioche_[i].sauver(ofs);
	}
};

void Pioche::charger(ifstream& ifs) {

	ifs >> taille_;

	pioche_.clear();

	for (int i = 0; i < taille_; ++i) {
		Carte carte;
		carte.charger(ifs);
		pioche_.push_back(carte);
	}

}