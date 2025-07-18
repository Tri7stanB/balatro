#include "total.h"
using namespace std;

Total::Total() { //Pour initialiser le score au 1er niveau
	total_ = 0;
	vie_ = 4;
	niveau_ = 1;
	palier_ = 25;
	meilleurscore_ = 0;
};

void Total::augmenterNiveau(int total) { //Pour augmenter d'un niveau et garder le score actuel (on retrouve 4 vies)
	total_ = total;
	vie_ = 4;
	niveau_ = niveau_ + 1;
	palier_ = palier_ + 25;
}

void Total::calculerTotal(Proposition p) {
	total_ = total_ + p.calculerScore();//On ajoute le score de la proposition au score total
	if ((total_ < palier_) and (p.getProposition().size()>0)) {
		vie_=vie_-1;
	}
	while (total_ >= palier_) { // On augmente le niveau (et donc le palier) tant que le score est plus grand que le palier
		augmenterNiveau(total_);
	}
	if (total_ > meilleurscore_) {
		setMeilleurScore(total_);
	}
}
void Total::setMeilleurScore(int score) {
	meilleurscore_ = score;
};

void Total::sauver(ofstream& ofs) const {
	ofs << total_<< endl;
	ofs << vie_<<endl;
	ofs << niveau_<<endl;
	ofs << palier_<<endl;
};

void Total::charger(ifstream& ifs) {
	ifs >> total_;
	ifs >> vie_;
	ifs >> niveau_;
	ifs >> palier_;
};

void Total::sauverMeilleurScore(ofstream& ofs) const {
	ofs << meilleurscore_ << endl;
};


void Total::chargerMeilleurScore(ifstream& ifs) {
	ifs >> meilleurscore_;
};