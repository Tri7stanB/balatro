
#include "jeu.h"
#include "carte.h"
#include "pioche.h"
#include "proposition.h"
#include "visual.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
Jeu::Jeu() {
	jeu_ = {};  /*initiaise le jeu du joueur vide*/
	taille_ = 0;  /*initialise la taille à 0*/
}


void Jeu::piocher(Pioche &pioche) { //On place la pioche en référence pour pouvoir la modifier
    if (!(pioche.getPioche()).empty()) {  /*test si la pioche n'est pas vide*/
        Carte carte_Piocher = (pioche.getPioche()).back();  /*carte_Piocher est la carte qui est prélevé de la pioche*/
        jeu_.push_back(carte_Piocher);/*on ajoute la carte pioché au jeu_*/
        (pioche.getPioche()).pop_back();/*on retire la carte piocher de la pioche*/
        taille_ = taille_ + 1;/*on augmente la taille du jeu de 1*/
        pioche.setTaille(pioche.getTaille() - 1);
    }
    
}

void Jeu::piocherMultiple(Pioche& pioche) {
    int taille = taille_;
    for (int i = 0; i <(8-taille);i++) {
        piocher(pioche);
        
    }
}

void Jeu::supprimerCarte(Carte carte) {
    for (int i = 0; i < jeu_.size(); i++) {
        if (jeu_[i].getValeur() == carte.getValeur() and jeu_[i].getCouleur() == carte.getCouleur()) {
            jeu_.erase(jeu_.begin() + i);
            taille_ = taille_ - 1;
        }
    };
}

void Jeu::sauver(ofstream& ofs) const {
    ofs << taille_ << endl;
    for (int i = 0; i < taille_; i++) {
        jeu_[i].sauver(ofs);
    }
};

void Jeu::charger(ifstream& ifs) {

    ifs >> taille_;

    jeu_.clear();

    for (int i = 0; i < taille_; ++i) {
        Carte carte;
        carte.charger(ifs);
        jeu_.push_back(carte);
    }

}