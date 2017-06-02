#include	"network.hpp"



bool		connectToServer(sf::TcpSocket *mySocket, char *ip, int port)
{
  if ((*mySocket).connect(ip, port) != sf::Socket::Done)
    {
      displayError("Problem connecting to the server");
      return false;
    }
  return true;
}

void		disconnectFromServer(sf::TcpSocket mySocket)
{
  mySocket.disconnect();
}
