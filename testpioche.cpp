#include "pioche.h"
#include <iostream>
using namespace std;

int main() {
	Pioche p; //On initialise la pioche qui est déjà mélangée
	vector<Carte> pioche = p.getPioche();
	for (int i = 0; i < pioche.size(); i++) {
		pioche[i].afficher(); //On affiche une à une les cartes de la pioche pour verifier que le melange a bien ete fait
	}
	return 0;
}