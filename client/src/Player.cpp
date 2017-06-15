#include <iostream>

#include "gestionGrille.hpp"
#include "Player.hpp"


using namespace std;


void pouvoirFrance(int x, int y, Grille *g)
{
  /// \brief Définition du pouvoir de la France
	std::cout << "pvr france" << std::endl;
	if (g->getTypeCase(x, y) == mer)
		g->setColorCase(x, y, 255,0,0,160);
	else if (g->getTypeCase(x, y) == boat)
		g->setColorCase(x, y, 0, 255, 0, 160);
}

int pouvoirRussie(int x, int y, Grille *g)
{
   /// \brief Définition du pouvoir de la Russie
	std::cout << "pvr russe" << std::endl;
	int nbTouch = 0;
	//case gauche
	if(g->getTypeCase(x - 1, y) == boat && x - 1 >= 0)
	{
		g->setTypeCase(x-1,y,touch);
		nbTouch++;
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
		nbTouch++;
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
		nbTouch++;
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
		nbTouch++;
		g->setColorCase(x, y + 1, 0, 255, 0, 128);
	}
	else if(g->getTypeCase(x, y + 1) == mer && y + 1 <= 10)
	{
		g->setTypeCase(x, y + 1, miss);
		g->setColorCase(x, y + 1, 255, 0, 0, 128);
	}
	return nbTouch;
}

int pouvoirAllemagne(int x, int y, Grille *g)
{
   /// \brief Définition du pouvoir de l'Allemagne
	int nbTouch = 0;
	if(g->getTypeCase(x, y) == boat)
	{
		g->setTypeCase(x,y,touch);
		nbTouch++;
		g->setColorCase(x,y,0,255,0,128);
	}
	else if(g->getTypeCase(x, y)==mer)
	{
		g->setTypeCase(x,y,miss);
		g->setColorCase(x,y,255,0,0,128);
	}		
	return nbTouch;
}

int pouvoirJapon(int x, int y, Grille *g)
{
   /// \brief Définition du pouvoir du Japon
	int nbTouch;
		if(g->getTypeCase(x, y) == boat)
	{
		g->setTypeCase(x,y,touch);
		nbTouch++;
		g->setColorCase(x,y,0,255,0,128);
	}
	else if(g->getTypeCase(x, y)==mer)
	{
		g->setTypeCase(x,y,miss);
		g->setColorCase(x,y,255,0,0,128);
	}		
	return nbTouch;
}
void pouvoirPirate(Grille *g)
{
   /// \brief Définition du pouvoir des Pirates
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

Player::Player(){
  /// \brief Constructeur par défaut
}

void Player::initMyGrille(Grille grille){
  /// \brief Initialise la grille du joueur
	myGrille = grille;
}

void Player::setGrilleOpp(Grille grille){
  /// \brief Définit la grille de l'opposant 
	grilleOpp = grille ;
}


void Player::setMyPseudo(){
  /// \brief Définit le pseudo via la fenêtre d'accueil
	myPseudo=lancerFenetreAccueil();
}

void Player::setPseudoOpp(string pseudo){
  /// \brief définit le pseudo du joueur adverse 
	pseudoOpp = pseudo    ;
}

void Player::setPaysId(){
  /// \brief Affecte un id au pays du joueur en fonction de la valeur
  /// renvoyée par fenetrePays()
  idPays = fenetrePays();

}

void Player::suppMyBoat(int supp){
  /// \brief Décrémente le nombre de parties de bateaux touchées
	myBoat = myBoat-supp;
}

void Player::addMyBoat(int add){
   /// \brief Incrémente le nombre de parties de bateaux touchées
	myBoat = myBoat+add;
}

void Player::setMyBoat(int nbBoat)
{
  /// \brief Définit le nombre de partie de bateaux à toucher
	myBoat = nbBoat;
}

void Player::suppboatOpp(int supp){
  /// \brief Décrémente le nombre de parties de bateaux touchées du joueurOpp
	boatOpp = boatOpp - supp;
}

Grille *Player::getMyModifGrille()
{
  /// \brief Renvoie un pointeur sur la grille du joueur afin de pouvoir
  /// la modifier
  return &myGrille;
}

Grille Player::getMyGrille(){
   /// \brief Renvoie la grille du joueur
	return myGrille;
}

Grille Player::getGrilleOpp(){
  /// \brief Renvoie la grille du joueur adverse
	return grilleOpp;
}

Grille *Player::getModifGrilleOpp(){
  /// \brief Renvoie un pointeur sur la grille du joueur adverse
  ///afin de pouvoir la modifier
	return &grilleOpp;
}

string Player::getMyPseudo(){
  /// \brief Retourne le pseudo du joueur
	return myPseudo;
}

string Player::getPseudoOpp(){
  /// \brief Retourne le pseudo du joueur adverse
	return pseudoOpp;
}

int Player::getPaysId(){
  /// \brief Retourne l'id du pays du joueur 
  return idPays;
}

int Player::getCooldown()
{
  /// \brief Renvoie le cooldown du joueur 
	return cooldown;
}
void Player::callPvr(int idPays, int x, int y, Grille *grille)
{
  /// \brief Appelle le pouvoir d'un pays en fonction de l'id passé en
  /// paramêtre
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
  /// \brief Définit le cooldown du joueur en fonction de l'id du pays choisi
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
  /// \brief Renvoie le nombre de parties de bateaux du joueur
  /// permet de gérer la défaite
  return myBoat;
}

int Player::getBoatOpp(){
  /// \brief Renvoie le nombre de parties de bateaux du joueur adverse
   /// permet de gérer la victoire
	return boatOpp;
}
