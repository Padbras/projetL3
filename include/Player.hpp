#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <string>
#include "Grille.hpp"
#include "Pays.hpp"
#include "fenetrePays.hpp"
#include "fenetrePosBateau.hpp"
#include "fenetreAccueil.hpp"

class Player{
	private :
		Grille myGrille;
		Grille grilleOpp;
		std::string myPseudo;
		std::string pseudoOpp;
		Pays pays;
		int myBoat = 17;
		int boatOpp = 17;
		
	public :	
		Player();
		void initMyGrille(Grille);
		void setGrilleOpp(Grille);
		void setMyPseudo();
		void setPseudoOpp(std::string);
		void setPaysId();
		void suppMyBoat(int);
		void addMyBoat(int);
		void suppboatOpp(int);
		Grille getMyGrille();
		Grille *getMyModifGrille();
		Grille *getModifGrilleOpp();
		Grille getGrilleOpp();
		std::string getMyPseudo();
		std::string getPseudoOpp();
		int getPaysId();
		int getMyBoat();
		int getBoatOpp();
};

#endif
