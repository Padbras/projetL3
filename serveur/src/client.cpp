#include	"network.hpp"

bool		sendPseudo(sf::TcpSocket *mySocket)
{
  std::string	pseudo;
  sf::Packet	toSend;
  displayInfo("What's ur pseudo ? ");
  std::cin >> pseudo;
  toSend << pseudo;
  if (sendPacket(&toSend, mySocket) == false)
    return false;
  displayInfo("Pseudo sent");
  return true;
}

int		main()
{
  sf::TcpSocket	socketToServer;
  int		port;

  displayInfo("Specify port please ? ");
  std::cin >> port;
  if (connectToServer(&socketToServer, "127.0.0.1", port) != true)
    exit(-1);
  if (sendPseudo(&socketToServer) == false)
    exit(-1);
}
