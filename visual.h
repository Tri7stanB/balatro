#include <iostream>
#include "pioche.h"
#include "total.h"
#include "jeu.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

using namespace std;
using namespace sf;

class visual {/*classe qui crée des instance qui permettent de visualisé le jeu et les propositions*/
	vector<sf::RectangleShape> visualjeu_;
	vector<sf::RectangleShape> visualproposition_;
	
public:
	visual();
	void setvisualJeu_();
	void setvisualProposition_();
	vector<sf::RectangleShape> getVisualProposition() { return visualproposition_; };
	vector<sf::RectangleShape>& getVisualJeu() { return visualjeu_; };
	int afficherProposition(Proposition prop, RenderWindow& window);
	int afficherJeu(Jeu jeu, RenderWindow& window);
	
};