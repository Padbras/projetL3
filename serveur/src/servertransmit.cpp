#include "network.hpp"


bool		sendGrille(sf::TcpSocket *mySocket, Grille myGrille)
{
	/// \brief Permet d'envoyer une grille
  sf::Packet	myPacket; // Rajouter touch et miss
  int		x, y, type;

  for (int j = 0; j < 10; j++)
    for (int i = 0; i < 10; i++)
      {
	myPacket.clear();
	x = myGrille._grille[i][j]._x;
	y = myGrille._grille[i][j]._y;
	if (myGrille._grille[i][j]._type == mer)
	  type = 0;
	else if (myGrille._grille[i][j]._type == boat)
	  type = 1;
	else if (myGrille._grille[i][j]._type == touch)
	  type = 2;
	else if (myGrille._grille[i][j]._type == miss)
	  type = 3;
	myPacket << x << y << type;
	if (sendPacket(&myPacket, mySocket) == false)
	  return false;
      }
  return true;
}

Grille		receiveGrille(sf::TcpSocket *mySocket)
{
	/// \brief Permet de recevoir une grille
  sf::Packet	myPacket;
  Grille	myGrille;
  int		type;
  
  for (int j = 0; j < 10; j++)
    for (int i = 0; i < 10; i++)
      {
	myPacket.clear();
	myPacket = receivePacket(mySocket);
	myPacket >> myGrille._grille[i][j]._x
		 >> myGrille._grille[i][j]._y
		 >> type;
	if (type == 0)
	  myGrille._grille[i][j]._type = mer;
	else if (type == 1)
	  myGrille._grille[i][j]._type = boat;
	else if (type == 2)
	  myGrille._grille[i][j]._type = touch;
	else if (type == 3)
	  myGrille._grille[i][j]._type = miss;
	  
      }
  myGrille.afficherGrille();
  return myGrille;
}

bool		transmitFirstInfo(Joueur joueurUn, Joueur joueurDeux)
{
	/// \brief Permet d'envoyer les grilles des adversaires afin de commencer la partie
  Grille       	GrilleP2;
  Grille       	GrilleP1;
  
  displayJoueur(joueurUn);
  displayJoueur(joueurDeux);
  GrilleP1 = receiveGrille(joueurUn.socket);
  GrilleP2 = receiveGrille(joueurDeux.socket);
  
  if (sendGrille(joueurDeux.socket, GrilleP1) == false)
    return false;
  if (sendGrille(joueurUn.socket, GrilleP2) == false)
    return false;
  return true;  
}

