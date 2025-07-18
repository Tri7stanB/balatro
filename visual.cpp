#include <iostream>
#include "pioche.h"
#include "total.h"
#include "jeu.h"
#include "proposition.h"
#include <SFML/Graphics.hpp>
#include "visual.h"



void visual::setvisualProposition_() {
    sf::RectangleShape cartep1;
    cartep1.setSize(sf::Vector2f(142, 192)); // Taille du rectangle
    cartep1.setPosition(505, 400); // Position du rectangle
    cartep1.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartep2;
    cartep2.setSize(sf::Vector2f(142, 192)); // Taille du rectangle
    cartep2.setPosition(697, 400); // Position du rectangle
    cartep2.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartep3;
    cartep3.setSize(sf::Vector2f(142, 192)); // Taille du rectangle
    cartep3.setPosition(889, 400); // Position du rectangle
    cartep3.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartep4;
    cartep4.setSize(sf::Vector2f(142, 192)); // Taille du rectangle
    cartep4.setPosition(1081, 400); // Position du rectangle
    cartep4.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartep5;
    cartep5.setSize(sf::Vector2f(142, 192)); // Taille du rectangle
    cartep5.setPosition(1273, 400); // Position du rectangle
    cartep5.setFillColor(sf::Color::White); // Couleur du rectangle



    visualproposition_.push_back(cartep1);
    visualproposition_.push_back(cartep2);
    visualproposition_.push_back(cartep3);
    visualproposition_.push_back(cartep4);
    visualproposition_.push_back(cartep5);


}
void visual::setvisualJeu_() {
    // Création des cartes du jeu(forme recatangulaire)
    sf::RectangleShape cartej1;
    cartej1.setSize(sf::Vector2f(106.5, 144)); // Taille du rectangle
    cartej1.setPosition(430, 770); // Position du rectangle
    cartej1.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartej2;
    cartej2.setSize(sf::Vector2f(106.5, 144)); // Taille du rectangle
    cartej2.setPosition(567, 770); // Position du rectangle
    cartej2.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartej3;
    cartej3.setSize(sf::Vector2f(106.5, 144)); // Taille du rectangle
    cartej3.setPosition(704, 770); // Position du rectangle
    cartej3.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartej4;
    cartej4.setSize(sf::Vector2f(106.5, 144)); // Taille du rectangle
    cartej4.setPosition(841, 770); // Position du rectangle
    cartej4.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartej5;
    cartej5.setSize(sf::Vector2f(106.5, 144)); // Taille du rectangle
    cartej5.setPosition(978, 770); // Position du rectangle
    cartej5.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartej6;
    cartej6.setSize(sf::Vector2f(106.5, 144)); // Taille du rectangle
    cartej6.setPosition(1115, 770); // Position du rectangle
    cartej6.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartej7;
    cartej7.setSize(sf::Vector2f(106.5, 144)); // Taille du rectangle
    cartej7.setPosition(1252, 770); // Position du rectangle
    cartej7.setFillColor(sf::Color::White); // Couleur du rectangle

    sf::RectangleShape cartej8;
    cartej8.setSize(sf::Vector2f(106.5, 144)); // Taille du rectangle
    cartej8.setPosition(1389, 770); // Position du rectangle
    cartej8.setFillColor(sf::Color::White); // Couleur du rectangle

    visualjeu_.push_back(cartej1);
    visualjeu_.push_back(cartej2);
    visualjeu_.push_back(cartej3);
    visualjeu_.push_back(cartej4);
    visualjeu_.push_back(cartej5);
    visualjeu_.push_back(cartej6);
    visualjeu_.push_back(cartej7);
    visualjeu_.push_back(cartej8);
    
}
int visual::afficherProposition(Proposition prop, RenderWindow& window) {
    if (prop.getProposition().size() > 0) {
        //On affiche la première carte de le proposition
        Texture carte1;
        
        if (!carte1.loadFromFile("cartes/" + to_string(prop.getProposition()[0].getValeur()) + prop.getProposition()[0].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite1(carte1);
        Vector2f position1 = (visualproposition_[0]).getPosition();
        sprite1.setPosition(position1.x, position1.y);
        sprite1.setScale(visualproposition_[0].getSize().x / carte1.getSize().x, visualproposition_[0].getSize().y / carte1.getSize().y);
        window.draw(sprite1);
        

    }
    
    if (prop.getProposition().size() > 1) {
        //On affiche la deuxième carte de la proposition
        Texture carte2;
        if (!carte2.loadFromFile("cartes/" + to_string(prop.getProposition()[1].getValeur()) + prop.getProposition()[1].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite2(carte2);
        Vector2f position2 = (visualproposition_[1]).getPosition();
        sprite2.setPosition(position2.x, position2.y);
        sprite2.setScale(visualproposition_[1].getSize().x / carte2.getSize().x, visualproposition_[1].getSize().y / carte2.getSize().y);
        window.draw(sprite2);
    }
    
    if (prop.getProposition().size() > 2) {
        Texture carte3;
        if (!carte3.loadFromFile("cartes/" + to_string(prop.getProposition()[2].getValeur()) + prop.getProposition()[2].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite3(carte3);
        Vector2f position3 = (visualproposition_[2]).getPosition();
        sprite3.setPosition(position3.x, position3.y);
        sprite3.setScale(visualproposition_[2].getSize().x / carte3.getSize().x, visualproposition_[2].getSize().y / carte3.getSize().y);
        window.draw(sprite3);
    }

    if (prop.getProposition().size() > 3) {
        Texture carte4;
        if (!carte4.loadFromFile("cartes/" + to_string(prop.getProposition()[3].getValeur()) + prop.getProposition()[3].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite4(carte4);
        Vector2f position4 = (visualproposition_[3]).getPosition();
        sprite4.setPosition(position4.x, position4.y);
        sprite4.setScale(visualproposition_[3].getSize().x / carte4.getSize().x, visualproposition_[3].getSize().y / carte4.getSize().y);
        window.draw(sprite4);
    }

    if (prop.getProposition().size() > 4) {
        Texture carte5;
        if (!carte5.loadFromFile("cartes/" + to_string(prop.getProposition()[4].getValeur()) + prop.getProposition()[4].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite5(carte5);
        Vector2f position5 = (visualproposition_[4]).getPosition();
        sprite5.setPosition(position5.x, position5.y);
        sprite5.setScale(visualproposition_[4].getSize().x / carte5.getSize().x, visualproposition_[4].getSize().y / carte5.getSize().y);
        window.draw(sprite5);
    }

    return 0;

}

int visual::afficherJeu(Jeu jeu, RenderWindow& window) {
    if (jeu.getJeu().size() > 0) {//On affiche la première carte du jeu
        Texture carte1;
        if (!carte1.loadFromFile("cartes/" + to_string(jeu.getJeu()[0].getValeur()) + jeu.getJeu()[0].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite1(carte1);
        Vector2f position1 = (visualjeu_[0]).getPosition();
        sprite1.setPosition(position1.x, position1.y);
        window.draw(sprite1);
    }
    
    if (jeu.getJeu().size() > 1) {
        Texture carte2;
        if (!carte2.loadFromFile("cartes/" + to_string(jeu.getJeu()[1].getValeur()) + jeu.getJeu()[1].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite2(carte2);
        Vector2f position2 = (visualjeu_[1]).getPosition();
        sprite2.setPosition(position2.x, position2.y);
        window.draw(sprite2);
    }
    if (jeu.getJeu().size() > 2) {
        Texture carte3;
        if (!carte3.loadFromFile("cartes/" + to_string(jeu.getJeu()[2].getValeur()) + jeu.getJeu()[2].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite3(carte3);
        Vector2f position3 = (visualjeu_[2]).getPosition();
        sprite3.setPosition(position3.x, position3.y);
        window.draw(sprite3);
    }
    
    if (jeu.getJeu().size() > 3) {
        Texture carte4;
        if (!carte4.loadFromFile("cartes/" + to_string(jeu.getJeu()[3].getValeur()) + jeu.getJeu()[3].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite4(carte4);
        Vector2f position4 = (visualjeu_[3]).getPosition();
        sprite4.setPosition(position4.x, position4.y);
        window.draw(sprite4);
    }
    
    if (jeu.getJeu().size() > 4) {
        Texture carte5;
        if (!carte5.loadFromFile("cartes/" + to_string(jeu.getJeu()[4].getValeur()) + jeu.getJeu()[4].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite5(carte5);
        Vector2f position5 = (visualjeu_[4]).getPosition();
        sprite5.setPosition(position5.x, position5.y);
        window.draw(sprite5);
    }
    
    if (jeu.getJeu().size() > 5) {
        Texture carte6;
        if (!carte6.loadFromFile("cartes/" + to_string(jeu.getJeu()[5].getValeur()) + jeu.getJeu()[5].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite6(carte6);
        Vector2f position6 = (visualjeu_[5]).getPosition();
        sprite6.setPosition(position6.x, position6.y);
        window.draw(sprite6);
    }
    
    if (jeu.getJeu().size() > 6) {
        Texture carte7;
        if (!carte7.loadFromFile("cartes/" + to_string(jeu.getJeu()[6].getValeur()) + jeu.getJeu()[6].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite7(carte7);
        Vector2f position7 = (visualjeu_[6]).getPosition();
        sprite7.setPosition(position7.x, position7.y);
        window.draw(sprite7);
    }
    
    if (jeu.getJeu().size() > 7) {
        Texture carte8;
        if (!carte8.loadFromFile("cartes/" + to_string(jeu.getJeu()[7].getValeur()) + jeu.getJeu()[7].getCouleur() + ".gif")) {
            // Gérer l'échec du chargement de l'image
            return 1;
        }
        Sprite sprite8(carte8);
        Vector2f position8 = (visualjeu_[7]).getPosition();
        sprite8.setPosition(position8.x, position8.y);
        window.draw(sprite8);
    }
    

    return 0;
}


visual::visual(){/*constructeur de visual*/
    visualjeu_ = {};
    visualproposition_ = {};
};

//void visual::selectionCarte(Proposition prop, Event event,Jeu jeu) {
//    for (int i = 0; i < 8; i++) {
//        RectangleShape zone = visualjeu_[i];
//        if (zone.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
//            bool flag = false;
//            for (int k = 0; k < prop.getProposition().size(); k++) {
//                if (prop.getProposition()[k].getValeur() == jeu.getJeu()[i].getValeur() && prop.getProposition()[k].getCouleur() == jeu.getJeu()[i].getCouleur()) {
//                    prop.supprimerCarte(jeu.getJeu()[i]);
//                    flag = true;
//                    break;
//                }
//
//            }
//            if (!flag) {
//                prop.ajouterCarte(jeu.getJeu()[i]);
//            }
//
//        }
//    }
//}
//
//void visual::validerProposition(Proposition prop) {
//    for (int i = 0; i < prop.getProposition().size(); i++) {
//        cout << "cartes selectionées :";
//        cout << prop.getProposition()[i].getValeur() << "," << prop.getProposition()[i].getCouleur() << endl;
//    }
//}