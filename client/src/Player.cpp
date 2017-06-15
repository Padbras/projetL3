#include <iostream>

#include "gestionGrille.hpp"
#include "Player.hpp"


using namespace std;


void pouvoirFrance(int x, int y, Grille *g)
{
	std::cout << "pvr france" << std::endl;
	if (g->getTypeCase(x, y) == mer)
		g->setColorCase(x, y, 255,0,0,160);
	else if (g->getTypeCase(x, y) == boat)
		g->setColorCase(x, y, 0, 255, 0, 160);
}

void pouvoirRussie(int x, int y, Grille *g)
{
	std::cout << "pvr russe" << std::endl;

	//case gauche
	if(g->getTypeCase(x - 1, y) == boat && x - 1 >= 0)
	{
		g->setTypeCase(x-1,y,touch);
		g->setColorCase(x-1,y,0,255,0,128);
	}
	else if(g->getTypeCase(x - 1, y) == mer && x - 1 >= 0)
	{
		g->setTypeCase(x - 1, y, miss);
		g->setColorCase(x-1,y,255,0,0,128);
	}
	
	
	//case droite
	if(g->getTypeCase(x + 1, y) == boat && x + 1 <= 10)
	{
		g->setTypeCase(x + 1, y, touch);
		g->setColorCase(x+1,y,0,255,0,128);
	}
	else if(g->getTypeCase(x + 1, y) == mer && x + 1 <= 10)
	{
		g->setTypeCase(x + 1, y, miss);
		g->setColorCase(x+1,y,255,0,0,128);
	}
	
	
	//case haut
	if(g->getTypeCase(x, y - 1) == boat && y - 1 >= 0)
	{
		g->setTypeCase(x, y - 1, touch);
		g->setColorCase(x,y-1,0,255,0,128);
	}
	else if(g->getTypeCase(x, y - 1) == mer && y - 1 >= 0)
	{
		g->setTypeCase(x, y - 1, miss);
		g->setColorCase(x,y-1,255,0,0,128);
	}
	
	
	//case bas
	if(g->getTypeCase(x, y + 1) == boat && y + 1 <= 10)
	{
		g->setTypeCase(x, y + 1, touch);
		g->setColorCase(x, y + 1, 0, 255, 0, 128);
	}
	else if(g->getTypeCase(x, y + 1) == mer && y + 1 <= 10)
	{
		g->setTypeCase(x, y + 1, miss);
		g->setColorCase(x, y + 1, 255, 0, 0, 128);
	}
	
}

void pouvoirAllemagne(int x, int y, Grille *g)
{
	if(g->getTypeCase(x, y) == boat)
	{
		g->setTypeCase(x,y,touch);
		g->setColorCase(x,y,0,255,0,128);
	}
	else if(g->getTypeCase(x, y)==mer)
	{
		g->setTypeCase(x,y,miss);
		g->setColorCase(x,y,255,0,0,128);
	}		
}

void pouvoirJapon(int x, int y, Grille *g)
{
		if(g->getTypeCase(x, y) == boat)
	{
		g->setTypeCase(x,y,touch);
		g->setColorCase(x,y,0,255,0,128);
	}
	else if(g->getTypeCase(x, y)==mer)
	{
		g->setTypeCase(x,y,miss);
		g->setColorCase(x,y,255,0,0,128);
	}		
}
void pouvoirPirate(Grille *g)
{
	for (int j = 0; j < 10; j++)
		for (int i = 0; i < 10; i++)
			{
				if (g->getTypeCase(i, j) == touch)
				{
					g->setTypeCase(i,j,boat);
					g->setColorCase(i,j,0,255,0,128);
					return ;
				}
			}
}

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
  idPays = fenetrePays();

}

void Player::suppMyBoat(int supp){
	myBoat = myBoat-supp;
}

void Player::addMyBoat(int add){
	myBoat = myBoat+add;
}

void Player::setMyBoat(int nbBoat)
{
	myBoat = nbBoat;
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

Grille *Player::getModifGrilleOpp(){
	return &grilleOpp;
}

string Player::getMyPseudo(){
	return myPseudo;
}

string Player::getPseudoOpp(){
	return pseudoOpp;
}

int Player::getPaysId(){
  return idPays;
}

int Player::getCooldown()
{
	return cooldown;
}
void Player::callPvr(int idPays, int x, int y, Grille *grille)
{
	switch(idPays)
	{
		case 1:
			pouvoirFrance(x, y, grille);
		break;
		case 2:
			pouvoirAllemagne(x, y, grille);
		break;
		case 3:
			pouvoirRussie(x, y, grille);
		break;
		case 4:
			pouvoirJapon(x, y, grille);
		break;
	}
}

void Player::setCooldown(int idPays)
{	
	switch(idPays)
	{
		case 1:
			cooldown = 4;
		break;
		case 2:
			cooldown = 7;
		break;
		case 3:
			cooldown = 8;
		break;
		case 4:
			cooldown = 3;
		break;
		case 5:
			cooldown = 5;
		break;
	}
}

int Player::getMyBoat(){
	return myBoat;
}

int Player::getBoatOpp(){
	return boatOpp;
}
