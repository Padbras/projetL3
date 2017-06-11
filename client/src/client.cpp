#include	"client.hpp"

bool		clientGameLoop(sf::TcpSocket *mySocket)
{
  bool		isOk = false;
  sf::Packet	toReceive;
  Grille	grilleMe;
  Grille	grilleOpp;	

  grilleMe = fenetrePosBateau();
  toReceive = receivePacket(mySocket);
  toReceive >> isOk;
  if (isOk)
    {
      if (sendInfo(mySocket, grilleMe) == false)
	{
	  displayError("Failed to send infos");
	  return false;
	}
      displayInfo("First info sent");
      grilleOpp = receiveInfo(mySocket);
      displayInfo("First info received");
      std::cout << "grille adversaire" << std::endl;
      grilleOpp.afficherGrille();
      std::cout << "ma grille" << std::endl;
      grilleMe.afficherGrille();
      if (fenetreJeu(grilleMe, grilleOpp, mySocket) == 1)
	{
	  mySocket->disconnect();
	  fenetreWin();
	}
      else
	{
	  mySocket->disconnect();
	  fenetreLoose();
	}
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
  sf::Packet portPartie;   
  int portGame;
  
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

   portPartie = receivePacket(&socketToServer);
  
  portPartie >> portGame;
  std::cout << portGame << std::endl;

  socketToServer.disconnect();
  
  std::cout << "Deco du serveur main" << std::endl;

  
   if (connectToServer(&socketToServer, ip, portGame) == false)
    {
      std::cout << port << std::endl; 
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
