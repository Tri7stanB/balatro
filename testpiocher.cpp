#include "pioche.h"
#include "jeu.h"
#include <vector>

using namespace std;

int main() {
	Pioche p; //On initialise la pioche qui est d�j� m�lang�e
	Jeu j;
	j.piocherMultiple(p);
	vector<Carte> jeu = j.getJeu();
	for (int i = 0; i < jeu.size(); i++) {
		jeu[i].afficher(); //On affiche une � une les cartes du jeu pour verifier que les cartes ont bien �t� pioch�es
	}
	vector<Carte> pioche = p.getPioche();
	for (int i = 0; i < pioche.size(); i++) {
		pioche[i].afficher(); //On affiche une � une les cartes du jeu pour verifier que les cartes ont bien �t� pioch�es
	}
	return 0;
}