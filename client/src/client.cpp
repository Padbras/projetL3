#include	"client.hpp"

Grille		g_Grille;
Grille		g_GrilleOpp;

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
    {
      for (int j = 0; j < 10; j++)
	{
	  myPacket >> g_Grille._grille[i][j];
	}
    }
}

bool		sendInfo(sf::TcpSocket *mySocket)
{
  sf::Packet	myPacket;

  for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
	{
	  myPacket << &g_GrilleOpp._grille[i][j];
	  if (sendPacket(&myPacket, mySocket) == false)
	    return false;
	}
    }
}

void		clientGameLoop(sf::TcpSocket *mySocket)
{
  bool		running = true;
  bool		isOk = false;
  sf::Packet	toSend;
  sf::Packet	toReceive;

  toReceive = receivePacket(mySocket);
  toReceive >> isOk;
  if (isOk)
    {
      if (sendInfo(mySocket) == false)
	{
	  //dostuff
	}
      if (receiveInfo(mySocket) == false)
	{
	  //dostuff
	}
  
      g_GrilleOpp.afficherGrille();
      g_Grille.afficherGrille();
  
      displayInfo("First info sent");
    }
  while (!running)
    {
      
    }
}

bool		sendPseudo(sf::TcpSocket *socket, std::string pseudo)
{
  sf::Packet	toSend;

  toSend << pseudo;
  if (sendPacket(&toSend, socket) == false)
    return false;
  return true;
}

void		startClient(char *ip, int port)
{
  std::string	pseudo;
  sf::TcpSocket	socketToServer;
  
  pseudo = lancerFenetreAccueil();
  if (connectToServer(&socketToServer, ip, port) == false)
    {
      
    }
  if (sendPseudo(&socketToServer, pseudo) == false)
    {
      displayError("Failed to send packet");
      exit(-1);
    }
  clientGameLoop(&socketToServer);
  // a la fin de pos bateau envoi des positions.
      // fenetrePosBateau(//&socketToServer
      // 		       );
}

int		main(int ac, char **av)
{
  if (ac != 3)
    {
      displayError("Need two arguments, specify the ip and the port");
      displayInfo("Usage : ./client.out [IP] [PORT]");                                      
      return -1;  
    }
  startClient(av[1], atoi(av[2]));
  return 0;
}
