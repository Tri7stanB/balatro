#include "pioche.h"
#include "carte.h"
#include <vector>
#include <ctime>
using namespace std;

Pioche::Pioche() {
	pioche_ = {};
	taille_ = 52;
	for (int i = 2; i < 15; i++) { //on ajoute les carreaux du 2 � l'As (repr�sent� par l'entier 14)
		Carte carte(i, "ca");
		pioche_.push_back(carte);
	}
	for (int i = 2; i < 15; i++) {//on ajoute les coeurs du 2 � l'As
		Carte carte(i, "co");
		pioche_.push_back(carte);
	}
	for (int i = 2; i < 15; i++) {//on ajoute les trefles du 2 � l'As
		Carte carte(i, "tr");
		pioche_.push_back(carte);
	}
	for (int i = 2; i < 15; i++) {//on ajoute les piques du 2 � l'As
		Carte carte(i, "pi");
		pioche_.push_back(carte);
	}
	// On m�lange la pioche � l'aide de l'algorithme de Fisher-Yates
	srand(static_cast<unsigned int>(time(nullptr)));//Pour initialiser le g�n�rateur de nombres pseudo-al�atoires 
	int n = pioche_.size(); //
	for (int i = n - 1; i > 0; --i) { //On parcourt la liste de mani�re d�croissante
		int j = rand() % (i + 1); //On prend un nombre aleatoire entre 0 et i
		swap(pioche_[i], pioche_[j]); //On �change les deux �l�ements pour m�langer
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