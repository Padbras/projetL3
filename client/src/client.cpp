#include	"client.hpp"

Grille		g_Grille;
Grille		g_GrilleOpp;

bool		clientGameLoop(sf::TcpSocket *mySocket)
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
	  displayError("Failed to send infos");
	  return false;
	}
      displayInfo("First info sent");
      if (receiveInfo(mySocket) == false)
	{
	  displayError("Failed to receive infos");
	  return false;
	}
      displayInfo("First info received");
      g_GrilleOpp.afficherGrille();
      g_Grille.afficherGrille();
    }
  while (!running)
    {
      
    }
  return true;
}

bool		sendPseudo(sf::TcpSocket *socket, std::string pseudo)
{
  sf::Packet	toSend;

  toSend << pseudo;
  if (sendPacket(&toSend, socket) == false)
    {
      displayError("Failed to send pseudo");
      return false;
    }
  displayInfo("Pseudo sent");
  return true;
}

bool		startClient(char *ip, int port)
{
  std::string	pseudo;
  sf::TcpSocket	socketToServer;
  
  pseudo = lancerFenetreAccueil();
  if (connectToServer(&socketToServer, ip, port) == false)
    {
      displayError("Failed to connect to server");
      return false;      
    }
  if (sendPseudo(&socketToServer, pseudo) == false)
    {
      displayError("Failed to send packet");
      return false;
    }
  if (clientGameLoop(&socketToServer) == false)
    {
      displayError("Failed to load client loop");
      return false;
    }
  // a la fin de pos bateau envoi des positions.
      // fenetrePosBateau(//&socketToServer
      // 		       );
  return true;
}

int		main(int ac, char **av)
{
  if (ac != 3)
    {
      displayError("Need two arguments, specify the ip and the port");
      displayInfo("Usage : ./client.out [IP] [PORT]");                                      
      return -1;  
    }
  if (startClient(av[1], atoi(av[2])) == false)
    {
      displayInfo("Failed to start client");
      return -1;
    }
  return 0;
}
