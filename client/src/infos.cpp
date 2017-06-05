#include	"client.hpp"

sf::Packet	&operator <<(sf::Packet &packet, const Case &myCase)
{
  return packet << (int)myCase._x << (int)myCase._y << (int)myCase._type;
}

sf::Packet	&operator >>(sf::Packet &packet, Case &myCase)
{
  return packet >> myCase._x >> myCase._y << myCase._type;
}


bool		receiveInfo(sf::TcpSocket *mySocket)
{
  sf::Packet	myPacket;

  myPacket = receivePacket(mySocket);
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      myPacket >> g_Grille._grille[i][j];
  return true;
}

bool		sendInfo(sf::TcpSocket *mySocket)
{
  sf::Packet	myPacket;

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      {
	myPacket << &g_GrilleOpp._grille[i][j];
	if (sendPacket(&myPacket, mySocket) == false)
	  return false;
      }
  return true;
}
