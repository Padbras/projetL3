#include	"network.hpp"

// send a packet to a valid tcpsocket
// return true if works, false if not

bool		sendPacket(sf::Packet *myPacket, sf::TcpSocket *mySocket)
{
  if ((*mySocket).send(*myPacket) != sf::Socket::Done)
    return false;
  return true;
}

// receive a packet from a valid tcpsocket
// return this packet

sf::Packet	receivePacket(sf::TcpSocket *mySocket)
{
  sf::Packet	myPacket;

  if (mySocket->receive(myPacket) != sf::Socket::Done)
    {
      displayError("Problem receiving packet");
    }
  return myPacket;
}
