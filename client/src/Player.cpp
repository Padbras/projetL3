#include <iostream>

#include "gestionGrille.hpp"
#include "Player.hpp"
#include "Bateau.hpp"


using namespace std;


void Player::Player(){}

void Player::initMyGrille(){
	myGrille=fenetrePosBateau();
}
/*
Player::setMyGrille(&grille grille){
	
}
*/

void Player::setGrilleOpp(){
	//grilleOpp= ;// receive pays;
}

void Player::setMyPseudo(){
	myPseudo=lancerFenetreAccueil();
}

void Player::setPseudoOpp(){
	//include la recption / socket
	//pseudoOpp =    ;
}

void Player::setPays(){
	pays = fenetrePays();
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

int Player::getPays(){
	return pays;
}

int Player::getMyBoat(){
	return myBoat;
}

int Player::getBoatOpp(){
	return boatOpp;
}

/*



int Player::jouerCoup(Player &j,int cpt){
	int x,y;
	cout<<"Coordonnées a viser : ";
	cin>>x>>y;
	if(j.gJoueur.getTypeCase(x,y)==boat){
		gAdversaire.setTypeCase(x,y,touch);
		j.gJoueur.setTypeCase(x,y,touch);
		cpt++;
	}else if(j.gJoueur.getTypeCase(x,y)==mer){
		gAdversaire.setTypeCase(x,y,miss);
		j.gJoueur.setTypeCase(x,y,miss);
	}
	return cpt;
}


void Player::initGrille(Grille &g){
	Bateau b1;
	Bateau b2;
	Bateau b3;
	Bateau b4;
	Bateau b5;
	
	g.afficherGrille();
	b1.posBateau(g,2);
	
	g.afficherGrille();
	b2.posBateau(g,3);
	
	g.afficherGrille();
	b3.posBateau(g,3);
	
	g.afficherGrille();
	b4.posBateau(g,4);
	
	g.afficherGrille();
	b5.posBateau(g,5);
	
	g.afficherGrille();
}
*/
