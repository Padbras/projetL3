#include <iostream>

#include "gestionGrille.hpp"
#include "Player.hpp"
#include "Bateau.hpp"
#include "Pays.hpp"


using namespace std;


Player::Player(){}

void Player::initMyGrille(Grille grille){
	myGrille = grille;
}

void Player::setGrilleOpp(Grille grille){
	grilleOpp = grille ;
}

void Player::setMyPseudo(){
	myPseudo=lancerFenetreAccueil();
}

void Player::setPseudoOpp(string pseudo){
	pseudoOpp = pseudo    ;
}

void Player::setPaysId(){
  pays.setId(fenetrePays());
}


void Player::suppMyBoat(int supp){
	myBoat = myBoat-supp;
}

void Player::addMyBoat(int add){
	myBoat = myBoat+add;
}

void Player::suppboatOpp(int supp){
	boatOpp = boatOpp - supp;
}

Grille *Player::getMyModifGrille()
{
  return &myGrille;
}

Grille Player::getMyGrille(){
	return myGrille;
}

Grille Player::getGrilleOpp(){
	return grilleOpp;
}

string Player::getMyPseudo(){
	return myPseudo;
}

string Player::getPseudoOpp(){
	return pseudoOpp;
}

int Player::getPaysId(){
  return pays.getId();
}

int Player::getMyBoat(){
	return myBoat;
}

int Player::getBoatOpp(){
	return boatOpp;
}
