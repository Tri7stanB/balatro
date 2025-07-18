#include<iostream>
#include "carte.h"
#include "proposition.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int Proposition::calculerScore() {
    
    vector<Carte> copie_proposition(proposition_);/*crer une copie de proposition appel� copie_proposition pour changer l'ordre pour travailler plus facilement dessu*/
    string test ="true";/*initialise un test pour le test du quinte flush royal*/
    
    if (proposition_.size() == 0) {
        return 0;
    }

    for (int i = 0; i < copie_proposition.size(); ++i) {/*on fais un tri de copie_preposition*/
        for (int j = 0; j < copie_proposition.size() - i - 1; ++j) {
            if (copie_proposition[j].getValeur() > copie_proposition[j + 1].getValeur()) {/*on fais le test pour trier les cartes de la proposition en fonction de leurs valeurs*/
                
                Carte echange = copie_proposition[j];/*les 3 lignes suivantes echangent l'ordre des carte pour le tri */
                copie_proposition[j] = copie_proposition[j + 1];
                copie_proposition[j + 1] = echange;
            }
        }
    }
    
    if (copie_proposition.size() == 5) { /*on va tester les coup dans l'ordre du plus fort au moins fort*/ /*les coups les plus fort sont avec 5 cartes quinte flushroyal...*/
        
        for (int k = 0; k <4 ; k++) {/*test du quint flush royal*/
            if (copie_proposition[k].getValeur()+1 != (copie_proposition[k + 1].getValeur()) || copie_proposition[k].getCouleur() != copie_proposition[k + 1].getCouleur() || copie_proposition[0].getValeur() != 10) {/*si les cartes se suivent et sont de m�me couleur */
                test = "false";
                
            }
        
        }
        if (test == "true") {
            
            return 200;
        }
        test = "true";
        for (int k = 0; k < 4; k++) {/*test du quint flush */
            if (copie_proposition[k].getValeur() + 1 != (copie_proposition[k + 1].getValeur()) || copie_proposition[k].getCouleur() != copie_proposition[k + 1].getCouleur() ) {/*si les cartes se suivent et sont de m�me couleur */
                test = "false";
                
            }
        }
        
        if (test == "true") {
            return 150;
        }
        test = "true";
        
        if (copie_proposition[0].getValeur() == copie_proposition[1].getValeur()) {/*test du carr� s'il y a 5 cartes et on rentre dans la boucle si les 4 premiere carte de copie_proposition sont les m�mes*/
            for (int k = 0; k < 3; k++) {
                
                if (copie_proposition[k].getValeur() != copie_proposition[k+ 1].getValeur()) {/*test */
                    test = "false";
                    
                }
            }
            if (test == "true") {
                return 125;
            }
        }
        else {/*test du carr� s'il y a 5 cartes et on rentre dans la bpucle pour tester si les 4 der,i�re boucle ont m�me hauteur*/
            for (int k = 1; k < 4; k++) {
                
                if (copie_proposition[k].getValeur() != copie_proposition[k+1].getValeur()) {
                    test = "false";
                }
            }
        
            if (test == "true") {
                return 125;
            }
        }

    }/*on sort de la boucles avec les tests de 5 cartes car on va ensuite tester le carre avec 4 cartes*/
    
    if (copie_proposition.size() == 4) {/*s'il y a 4 cartes test si c'est un carr�*/
        
        if (copie_proposition[0].getValeur() == copie_proposition[1].getValeur() && copie_proposition[1].getValeur()==copie_proposition[2].getValeur()&& copie_proposition[2].getValeur() == copie_proposition[3].getValeur()) {/*test si les 5 cartes sont �gales*/
            
            return 125;
        }
    }
    /*test full*/
    if (copie_proposition.size() == 5) {
        if (((copie_proposition[0].getValeur() == copie_proposition[1].getValeur()) && (copie_proposition[2].getValeur() == copie_proposition[3].getValeur()) && (copie_proposition[3].getValeur() == copie_proposition[4].getValeur())) || ((copie_proposition[4].getValeur() == copie_proposition[3].getValeur()) && (copie_proposition[0].getValeur() == copie_proposition[1].getValeur()) && (copie_proposition[1].getValeur() == copie_proposition[2].getValeur()))) {/*test si on a un full c'est � dire si les 2 premi�re cartes de copie_proposition sont les memes et les 3 suivent aussi ou si les 3premi�res cartes sont les m^mes et les 2 suiventes aussi*/
            return 100;
        }
    }

    if (copie_proposition.size() == 5) {/*test couleur*/
        if (copie_proposition[0].getCouleur() == copie_proposition[1].getCouleur() && copie_proposition[1].getCouleur() == copie_proposition[2].getCouleur() && copie_proposition[2].getCouleur() == copie_proposition[3].getCouleur() && copie_proposition[3].getCouleur() == copie_proposition[4].getCouleur()) {/*test s'il y a une couleur en ragrdant si toutes les couleurs sont les m�mes*/
            return 80;
        }
        test = "true";/*si in a pas une quinte la varibale test sera "false , on la r�initialise donc � true*/
    }
    

    if (copie_proposition.size()==5) {/*test si la longeur de la proposition est 5 pour ne pas rentr� dans la boucle for inutilement*/
        
        for (int k = 0; k < 4; k++) {/*test de la quint*/
            if (copie_proposition[k].getValeur() + 1 != (copie_proposition[k + 1].getValeur())) {/*test si les cartes se suivent en augmentant de 1 � chque fois*/
                test = "false";

            }
        }
        if (test == "true") {
            return 65;
        }
    }

    /*test Brelan*/
    if (copie_proposition.size() > 2) {/*pour le brelan il faut au moins 3 cartes*/
        if (copie_proposition[0].getValeur()== copie_proposition[1].getValeur()&& copie_proposition[1].getValeur()== copie_proposition[2].getValeur()) {/*test si c'est les 3�re valeurs qui sont les m�mes*/
            return 40;
        }
        if (copie_proposition[copie_proposition.size()-1].getValeur() == copie_proposition[copie_proposition.size() - 2].getValeur() && copie_proposition[copie_proposition.size() - 2].getValeur() == copie_proposition[copie_proposition.size() - 3].getValeur()) {/*test sii les3 derni�re cartes sont les m�mes*/
            return 40;
        }
        if (copie_proposition.size() == 5) {/*test le cas ou il y a 5 cartes que que dans la liste tri� , les 3 cartes sont la 2,3,4*/
            if (copie_proposition[copie_proposition.size() - 2].getValeur() == copie_proposition[copie_proposition.size() - 3].getValeur() && copie_proposition[copie_proposition.size() - 3].getValeur() == copie_proposition[copie_proposition.size() - 4].getValeur()) {/*test sii les3 derni�re cartes sont les m�mes*/
                return 40;
            }
        }
    }
    /*test double-pair*/
    if (copie_proposition.size() > 3) {/*test si on a copie_proposition de taille superieur � 3*/
        if (copie_proposition.size() == 4) {/*si copie_proposition est de longueur 4 on test */
            if (copie_proposition[0].getValeur() == copie_proposition[1].getValeur() && copie_proposition[2].getValeur() == copie_proposition[3].getValeur()) {
                return 25;
            }
        }
        else {/*si copie_proposition est de longueur 5*/
            if (copie_proposition[0].getValeur() == copie_proposition[1].getValeur() && copie_proposition[3].getValeur() == copie_proposition[4].getValeur()) {/*test les 2 premi�re et 2 derni�re*/
                return 25;
            }
            if (copie_proposition[0].getValeur() == copie_proposition[1].getValeur() && copie_proposition[2].getValeur() == copie_proposition[3].getValeur()) {/*test les 2 premi�re et les 2 suiventes*/
                return 25;
            }
            
            if (copie_proposition[1].getValeur() == copie_proposition[2].getValeur() && copie_proposition[3].getValeur() == copie_proposition[4].getValeur()) {/*test les 2 derni�re et les 2 pr�c�dentes*/
                return 25;
            }
            
        }
    }
    
    /*test pair*/
    if (copie_proposition.size() > 1) {
        for (int k = 0; k < copie_proposition.size() - 2; k++) {
            if (copie_proposition[k].getValeur() == copie_proposition[k + 1].getValeur()) {/*regarde si 2 cartes qui se suivent sont �gales*/
                test = "true";/*test est � false et si on a une pair test passe � true*/
            }
        }
        if (test == "true") {
            return 10;
        }
    }
    


    /*
    for (int k = 0; k < copie_proposition.size(); k++) {
        cout << copie_proposition[k].getValeur();
    }*/
    return 5;
}
    
Proposition::Proposition(vector<Carte> proposition) {
    proposition_ = proposition;
    
   
}

//void Proposition::setProposition() {
//    vector<Carte> prop = {};
//    Event event;
//    while (!(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)) {
//        // G�rer l'�v�nement d'appui sur la touche Entr�e ici
//        // Par exemple : 
//        std::cout << "La touche Entr�e a �t� enfonc�e !" << std::endl;
//    }
//
//}

void Proposition::ajouterCarte(Carte carte){
    if (proposition_.size() < 5) {
        proposition_.push_back(carte);
    }
}

void Proposition::supprimerCarte(Carte carte) {
    for (int i = 0; i < proposition_.size(); i++) {
        if (proposition_[i].getValeur() == carte.getValeur() and proposition_[i].getCouleur() == carte.getCouleur()) {
            proposition_.erase(proposition_.begin() + i);
        }
    };
}

void Proposition::sauver(ofstream& ofs) const {
    for (int i = 0; i < proposition_.size(); i++) {
        proposition_[i].sauver(ofs);
    }
};

void Proposition::charger(ifstream& ifs) {
        
    proposition_.clear();

    for (int i = 0; i < proposition_.size(); ++i) {
        Carte carte;
        carte.charger(ifs);
        proposition_.push_back(carte);
    }

}