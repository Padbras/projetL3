#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Grille.hpp"
#include "Pays.hpp"
#include "France.hpp"


class Joueur{
	public :
		Grille gJoueur;
		Grille gAdversaire;
		Pays *_p;
		int cptBoatPart=17;
		
	public :	
		Joueur();
		void jouerCoup(Grille &g,int x,int y);
		void initGrille(Grille &g);

};






#endif
