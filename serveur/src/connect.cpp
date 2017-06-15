#include	"network.hpp"

// connect to a server 

bool		connectToServer(sf::TcpSocket *mySocket, char *ip, int port)
{
	/// \brief Permet de connecter un client au serveur
  if ((*mySocket).connect(ip, port) != sf::Socket::Done)
    {
      displayError("Problem connecting to the server");
      return false;
    }
  return true;
}

void		disconnectFromServer(sf::TcpSocket mySocket)
{
	/// \brief Deconnecte un client du serveur
  mySocket.disconnect();
}
