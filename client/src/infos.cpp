#include	"client.hpp"

Grille		receiveInfo(sf::TcpSocket *mySocket)
{
  sf::Packet	myPacket;
  int		type;
  Grille	myGrille;
  
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

bool		sendInfo(sf::TcpSocket *mySocket, Grille myGrille)
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
