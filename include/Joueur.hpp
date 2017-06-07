#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Grille.hpp"
#include "Pays.hpp"

class Joueur{
	public :
		Grille gJoueur;
		Grille gAdversaire;
		Pays pJoueur;
		int cptBoatPart=17;
		Joueur();
		int jouerCoup(Joueur &jAdv,int &cpt);
		void initGrille(Grille &g);

};






#endif
