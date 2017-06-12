#include "network.hpp"


bool		sendGrille(sf::TcpSocket *mySocket, Grille myGrille)
{
  sf::Packet	myPacket;
  int		x, y, type;

  for (int j = 0; j < 10; j++)
    for (int i = 0; i < 10; i++)
      {
	myPacket.clear();
	x = myGrille._grille[i][j]._x;
	y = myGrille._grille[i][j]._y;
	if (myGrille._grille[i][j]._type == mer)
	  type = 0;
	else
	  type = 1;
	myPacket << x << y << type;
	if (sendPacket(&myPacket, mySocket) == false)
	  return false;
      }
  return true;
}

Grille		receiveGrille(sf::TcpSocket *mySocket)
{
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
	else
	  myGrille._grille[i][j]._type = boat;
      }
  myGrille.afficherGrille();
  return myGrille;
}

bool		transmitFirstInfo(Joueur joueurUn, Joueur joueurDeux)
{
  sf::Packet	myPacket1;
  sf::Packet	myPacket2;
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

