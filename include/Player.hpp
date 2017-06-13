#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <string>

#include "Grille.hpp"
#include "Pays.hpp"
#include "France.hpp"


class Player{
	private :
		Grille myGrille;
		Grille grilleOpp;
		string myPseudo;
		String pseudoOpp;
		int pays;
		int myBoat = 17;
		int boatOpp = 17;
		
	public :	
		Player();
		void initMyGrille();
		//setMyGrille(&grille);
		void setGrilleOpp();
		void setMyPseudo();
		void setPseudoOpp();
		void setPays();
		void suppMyBoat(int);
		void addMyBoat(int);
		void setboatOpp();
		Grille getMyGrille();
		Grille getGrilleOpp();
		string getMyPseudo();
		string getPseudoOpp();
		int getPays();
		int getMyBoat();
		int getBoatOpp();
};

#endif
