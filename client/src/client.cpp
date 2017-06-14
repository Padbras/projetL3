#include	"client.hpp"
#include "fenetreAttente.hpp"
bool		clientGameLoop(sf::TcpSocket *mySocket, Player *player)
{
  bool		isOk = false;
  
  sf::Thread myThread(&fenetreAttente, 2);
  sf::Packet	toReceive;
  toReceive = receivePacket(mySocket);
  toReceive >> isOk;
  if (isOk)
    {
      if (sendGrille(mySocket, player->getMyGrille()) == false)
	{
	  displayError("Failed to send infos");
	  return false;
	}
      displayInfo("First info sent");
      //myThread.launch();
      
      player->setGrilleOpp(receiveGrille(mySocket));
      
      //myThread.terminate();
      displayInfo("First info received");
      std::cout << "grille adversaire" << std::endl;
      player->getGrilleOpp().afficherGrille();
      std::cout << "ma grille" << std::endl;
      player->getMyGrille().afficherGrille();
      
      if (fenetreJeu(player, mySocket) == 1)
	{
	  fenetreWin();
	  mySocket->disconnect();

	}
      else
	{
	  fenetreLoose();
	  mySocket->disconnect();

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
  Player player;
  Grille tmp; 
  
  player.setMyPseudo();
  

  
  if (connectToServer(&socketToServer, ip, port) == false)
    {
      displayError("Failed to connect to server");
      return false;      
    }
  else
    {
       displayInfo("Connected to server ");
       std::cout << port << std::endl;
    }
 
  if (sendPseudo(&socketToServer, player.getMyPseudo()) == false)
    {
      displayError("Failed to send packet");
      return false;
    }
sf::Thread myThread(&fenetreAttente, 1);
	//myThread.launch();
	
      sf::Packet strReceive;
      std::string myStr;
      strReceive = receivePacket(&socketToServer);
      strReceive >> myStr;
      std::cout<< "mystr " << myStr << std::endl;
      player.setPseudoOpp(myStr);
      std::cout<< "getpseudopp   "<<player.getPseudoOpp()<<std::endl;

	
  portPartie = receivePacket(&socketToServer);
  //myThread.terminate();
  portPartie >> portGame;
  std::cout << "port recu par le server : " << portGame << std::endl;

  socketToServer.disconnect();
  
  std::cout << "Deco du serveur main" << std::endl;  
   if (connectToServer(&socketToServer, ip, portGame) == false)
    {
      displayError("Failed to connect to server");
      return false;      
    }

     if (sendPseudo(&socketToServer, player.getMyPseudo()) == false)
    {
      displayError("Failed to send packet");
      return false;
    }
     
     player.setPaysId();
     tmp = fenetrePosBateau();
     player.initMyGrille(tmp);
     


     if (clientGameLoop(&socketToServer, &player) == false)
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
