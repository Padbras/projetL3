#include	"network.hpp"

void		gameLoop(sf::TcpSocket *mySocket)
{
  sf::Packet	toSend;
  sf::Packet	toReceive;
  std::string	str;
  bool		running = true;

  while (running)
    {
      toSend.clear();
      std::cout << "message ? ";
      std::cin >> str;
      toSend << str;
      if (sendPacket(&toSend, mySocket) == false)
	{
	  displayError("Problem sending packet");
	}
      else
	displayInfo("Packet sent");
      toReceive.clear();
      toReceive = receivePacket(mySocket);
      toReceive >> str;
      std::cout << str << std::endl;
    }
}

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
  gameLoop(&socketToServer);
}
