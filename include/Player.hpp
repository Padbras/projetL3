#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <string>
#include "Grille.hpp"
#include "fenetrePays.hpp"
#include "fenetrePosBateau.hpp"
#include "fenetreAccueil.hpp"

class Player{
	private :
		Grille myGrille;
		Grille grilleOpp;
		std::string myPseudo;
		std::string pseudoOpp;
		int idPays;
		int cooldown;
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
		int getCooldown();
		void setCooldown(int);
		void setMyBoat(int );
		void callPvr(int, int, int, Grille *);
};


int pouvoirAllemagne(int, int, Grille *);
void pouvoirFrance(int, int, Grille *);
int pouvoirRussie(int, int, Grille *);
int pouvoirJapon(int, int, Grille *);
void pouvoirPirate(Grille *);

#endif
