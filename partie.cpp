#include <iostream>
#include "pioche.h"
#include "total.h"
#include "jeu.h"
#include "visual.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;


int main() {

    RenderWindow window;
    ContextSettings option;
    option.antialiasingLevel = 8;

    window.create(VideoMode::getFullscreenModes()[0], "Partie de Balatro", Style::Default, option); //On ouvre la fenetre en plein ecran

    Event event;
    sf::Music music;
    

    Texture texture; //Pour mettre une image du tapis de jeu en fond d'ecran (texture)
    if (!texture.loadFromFile("cartes/tapis.jpg")) {
        // Gestion d'erreur si le chargement échoue
        return EXIT_FAILURE;
    }

    // Création du sprite pour afficher l'image
    Sprite background(texture);

    Texture texture1;
    if (!texture1.loadFromFile("cartes/regles.png")) {
        // Gestion de l'erreur si le chargement de l'image échoue
        return -1;
    }
    Texture texture2;
    if (!texture2.loadFromFile("cartes/points.png")) {
        // Gestion de l'erreur si le chargement de l'image échoue
        return -1;
    }
    Texture texture3;
    if (!texture3.loadFromFile("cartes/Perdu.png")) {
        // Gestion de l'erreur si le chargement de l'image échoue
        return -1;
    }

    Texture texture4;
    if (!texture4.loadFromFile("cartes/Menu.png")) {
        // Gestion de l'erreur si le chargement de l'image échoue
        return -1;
    }

   


    Sprite sprite1(texture1);
    sprite1.setPosition(450, 150);
    bool afficherRegles = false;

    Sprite sprite2(texture2);
    sprite2.setPosition(760, 150);
    bool afficherPoints = false;

    Sprite sprite3(texture3);
    sprite3.setPosition(410, 200);
    bool afficherPerdu = false;

    Sprite sprite4(texture4);
    sprite4.setPosition(150, 170);
    bool afficherMenu = true;
    float scaleFactor = 1.5f;

    bool musique = true;
    music.play();
    music.setLoop(true);
    // Redimensionner le tapis de jeu pour qu'il remplisse toute la fenêtre
    background.setScale(window.getSize().x / background.getLocalBounds().width,
        window.getSize().y / background.getLocalBounds().height);
    
    // Configuration du texte avec la police choisie
    Font font;
    if (!font.loadFromFile("styles/segoepr.ttf")) {
        // Gestion d'erreur si le chargement de la police échoue
        return EXIT_FAILURE;
    }
    

    Text scoreText; //Paramètres textuels du score
    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(Color::White);


    Text niveauText; //Paramètres textuels du niveau
    niveauText.setFont(font);
    niveauText.setCharacterSize(50);
    niveauText.setFillColor(Color::White);

    Text vieText; //Paramètres textuels des vies
    vieText.setFont(font);
    vieText.setCharacterSize(50);
    vieText.setFillColor(Color::White);

    Text Regles; //Paramètres textuels du score
    Regles.setFont(font);
    Regles.setCharacterSize(35);
    Regles.setFillColor(Color::White);

    Text Menu; //Paramètres textuels du score
    Menu.setFont(font);
    Menu.setCharacterSize(35);
    Menu.setFillColor(Color::White);

    Text Points; //Paramètres textuels du score
    Points.setFont(font);
    Points.setCharacterSize(35);
    Points.setFillColor(Color::White);

    Text meilleurscoreText; //Paramètres textuels des vies
    meilleurscoreText.setFont(font);
    meilleurscoreText.setCharacterSize(50);
    meilleurscoreText.setFillColor(Color::White);

    Text palierText; //Paramètres textuels des vies
    palierText.setFont(font);
    palierText.setCharacterSize(50);
    palierText.setFillColor(Color::White);

    visual Visual;/*créer Visual un element de type visual*/
    Visual.setvisualJeu_();
    Visual.setvisualProposition_();

    Total total; //on initialise le total qui gere le score, le niveau et les vies

    Pioche pioche; // on initialise la pioche

    Jeu jeu; //on initialise le jeu

    jeu.piocherMultiple(pioche);
    Proposition prop({});

    
    
    while (window.isOpen())
    {
        ifstream fichier_in("meilleurscore.txt");
        total.chargerMeilleurScore(fichier_in);
        
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();



            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                
                for (int i = 0; i < prop.getProposition().size(); i++) {
                    jeu.supprimerCarte(prop.getProposition()[i]);
                }
                jeu.piocherMultiple(pioche);

                total.calculerTotal(prop);
                int tailleprop = prop.getProposition().size();
                for (int i = tailleprop - 1; i > -1; i--) {
                    prop.supprimerCarte(prop.getProposition()[i]);
                }


            }
            sprite4.setScale(scaleFactor, scaleFactor);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                afficherRegles = !afficherRegles;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                afficherPoints = !afficherPoints;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M) {
                afficherMenu= !afficherMenu;
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                ofstream fichier_out("partie.txt");
                if (fichier_out.is_open()) {
                    total.sauverMeilleurScore(fichier_out);
                    total.sauver(fichier_out);
                    pioche.sauver(fichier_out);
                    jeu.sauver(fichier_out);
                    fichier_out.close();
                }
                else {
                    cerr << "Erreur : Impossible d'ouvrir le fichier pour sauvegarde" << endl;
                    return 1;
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) {
                ifstream fichier_in("partie.txt");
                if (fichier_in.is_open()) {
                    total.chargerMeilleurScore(fichier_in);
                    total.charger(fichier_in);
                    pioche.charger(fichier_in);
                    jeu.charger(fichier_in);
                    fichier_in.close();
                }
                else {
                    cerr << "Erreur : Impossible d'ouvrir le fichier pour chargement" << endl;
                    return 1;
                }
            }


            if (event.type == sf::Event::MouseButtonPressed) {
                for (int i = 0; i < 8; i++) {
                    RectangleShape zone = Visual.getVisualJeu()[i];
                    if (zone.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        bool flag = false;


                        for (int k = 0; k < prop.getProposition().size(); k++) {
                            if (prop.getProposition()[k].getValeur() == jeu.getJeu()[i].getValeur() && prop.getProposition()[k].getCouleur() == jeu.getJeu()[i].getCouleur()) {
                                prop.supprimerCarte(jeu.getJeu()[i]);
                                flag = true;
                                
                                break;
                            }

                        }
                        if (!flag) {
                            prop.ajouterCarte(jeu.getJeu()[i]);
                            
                        }

                    }
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    musique = !musique; // Inverser l'état de la musique
                    if (musique) {
                        music.play();
                    }
                    else {
                        music.pause();
                    }
                }
            }
        }

        if(to_string(total.getVie())=='0'||(to_string(pioche.getTaille())=='0')&&(to_string(jeu.getTaille()) == '0')) {
            afficherPerdu = !afficherPerdu;
        }


        // Convertir le score, le niveau et les vies en chaîne de caractères pour l'affichage
        scoreText.setString("Score: " + to_string(total.getTotal()));
        niveauText.setString("Niveau: " + to_string(total.getNiveau()));
        vieText.setString("Vies: " + to_string(total.getVie()));
        palierText.setString("Palier: " + to_string(total.getPalier()));
        meilleurscoreText.setString("Meilleur score: " + to_string(total.getMeilleurScore()));
        Regles.setString("Règles:R");
        Points.setString("Points:P");
        Menu.setString("Menu:M");
        // Affichage de l'image de fond
        window.draw(background);


        if (total.getTotal() > total.getMeilleurScore()) {
            total.setMeilleurScore(total.getTotal());
        }
        ofstream fichier_out("meilleurscore.txt");
        total.sauverMeilleurScore(fichier_out);


        if (afficherRegles) {
            window.draw(sprite1);
        }
        if (afficherPoints) {
            window.draw(sprite2);
        }
        if (afficherPerdu) {
            window.draw(sprite3);
        }
        if (afficherMenu) {
            window.draw(sprite4);
        }
        // Positionner le texte du score, du niveau et des vies
        scoreText.setPosition(30, 20);
        niveauText.setPosition(30, 80);
        vieText.setPosition(30, 140);
        palierText.setPosition(30, 200);
        meilleurscoreText.setPosition(30, 260);
        Regles.setPosition(1300, 20);
        Points.setPosition(1600, 20);
        Menu.setPosition(1000, 20);
        // Afficher le score, le niveau et les vies à l'écran
        window.draw(scoreText);
        window.draw(niveauText);
        window.draw(vieText);
        window.draw(palierText);
        window.draw(meilleurscoreText);
        window.draw(Regles);
        window.draw(Points);
        window.draw(Menu);


        Visual.afficherJeu(jeu, window); //On affiche le jeu à l'écran
        Visual.afficherProposition(prop, window); //On affiche la proposition à l'écran


        // Affichage de la fenêtre à l'écran
        window.display();

    }

    return 0;
}