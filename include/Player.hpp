#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Grille.hpp"
#include "Pays.hpp"
#include "France.hpp"


class Player{
	public :
		Grille gJoueur;
		Grille gAdversaire;
		Pays *_p;
		int cptBoatPart=17;
		
	public :	
		Player();
		int jouerCoup(Player &j,int cpt);
		void initGrille(Grille &g);

};






#endif
