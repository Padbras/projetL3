#include <iostream>

#include "gestionGrille.hpp"
#include "Player.hpp"


using namespace std;


void pouvoirFrance(int x, int y, Grille *g)
{
	/// \brief Fonction qui gère le pouvoir de la France
	std::cout << "pvr france" << std::endl;
	if (g->getTypeCase(x, y) == mer)
		g->setColorCase(x, y, 255,0,0,160);
	else if (g->getTypeCase(x, y) == boat)
		g->setColorCase(x, y, 0, 255, 0, 160);
}

void pouvoirRussie(int x, int y, Grille *g)
{
	/// \brief Fonction qui gère le pouvoir de la Russie
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
	/// \brief Fonction qui gère le pouvoir de l'Allemagne
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
	/// \brief Fonction qui gère le pouvoir du Japon
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
	/// \brief Fonction qui gère le pouvoir des Pirates
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

Player::Player(){} /// \brief Constructeur par defaut

void Player::initMyGrille(Grille grille){
	/// \brief Initialise la grille du joueur avec la grille retournée par fenetrePosBateau (cf #fenetrePosBateau)
	myGrille = grille;
}

void Player::setGrilleOpp(Grille grille){
	/// \brief Initialise la grille sur laquelle le joueur tire avec la grille retournée par fenetrePosBateau (cf #fenetrePosBateau)
	grilleOpp = grille ;
}

void Player::setMyPseudo(){
	 /// \brief Initialise le pseudo du joueur via la fenetre d'accueil (cf #lancerFenetreAccueil)
	myPseudo=lancerFenetreAccueil();
}

void Player::setPseudoOpp(string pseudo){ 
	/// \brief Initialise le pseudo du joueur adverse passé en paramètre
	pseudoOpp = pseudo    ;
}

void Player::setPaysId(){ 
	/// \brief affecte un identifiant a chaque pays via #fenetrePays
  pays.setId(fenetrePays());
}


void Player::suppMyBoat(int supp){
	/// \brief Décremente le compteur de cases de bateaux restantes du joueur, utilisé pour gérer la defaite
	myBoat = myBoat-supp;
}

void Player::addMyBoat(int add){
	/// \brief Incrémente le compteur de cases de bateaux restantes du joueur, utilisé pour gérer la defaite
	myBoat = myBoat+add;
}

void Player::suppboatOpp(int supp){
	/// \brief Décremente le compteur de cases de bateaux restantes du joueur adverse, utilisé pour gérer la victoire
	boatOpp = boatOpp - supp;
}

Grille *Player::getMyModifGrille(){
	/// \brief Renvoie la grille du joueur afin de pouvoir la modifier
  return &myGrille;
}

Grille Player::getMyGrille(){
	/// \brief Renvoie une copie de la grille du joueur
	return myGrille;
}

Grille Player::getGrilleOpp(){
	/// \brief Renvoie une copie de la grille du joueur adverse
	return grilleOpp;
}

Grille *Player::getModifGrilleOpp(){
	/// \brief Renvoie la grille du joueur adverse afin de pouvoir la modifier
	return &grilleOpp;
}

string Player::getMyPseudo(){
	/// \brief Renvoie le pseudo du joueur courant
	return myPseudo;
}

string Player::getPseudoOpp(){
	/// \brief Renvoie le pseudo du joueur adverse
	return pseudoOpp;
}


int Player::getPaysId(){
	/// \brief Renvoie l'identifiant du pays du joueur courant
  return idPays;
}

int Player::getCooldown()
{
	/// \brief Retourne le cooldown du pays 
	return cooldown;
}
void Player::callPvr(int idPays, int x, int y, Grille *grille)
{
	/// \brief Appelle la fonction de pouvoir du pays en fonction de l'identifiant
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
	/// \brief Définit le cooldown du pays en fonction de son identifiant
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
	/// \brief Renvoie le compteur de cases de bateaux restantes, gère la defaite
	return myBoat;
}

int Player::getBoatOpp(){
	/// \brief Renvoie le compteur de cases de bateaux restantes du joueur adverse, gère la victoire
	return boatOpp;
}
