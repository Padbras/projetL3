#include	"network.hpp"


void serverLoop(sf::TcpListener *listener, sf::SocketSelector *selector,
			     std::list<sf::TcpSocket *> clients, bool role)
{
  bool		running = true;
  std::list<Joueur> joueurs;

  if(role == false)
    std::cout << "Sub serveur" << std::endl;

 
  
  while (running)
    {
      if (selector->wait())
	{
	  if (selector->isReady(*listener))
	    {
	      
	      // We found a connection
	      sf::TcpSocket *client = new sf::TcpSocket;
	      if (listener->accept(*client) == sf::Socket::Done)
		{
		  clients.push_back(client);
		  selector->add(*client);
		  displayInfo("Client connected");
		  displayInfo("Client add to the selector");
		}
	      else
		delete client;
	    }	  
	  else
	    {
	      for (std::list<sf::TcpSocket *>::iterator it = clients.begin();
		   it != clients.end(); ++it)
		{
		  sf::TcpSocket &client = **it;
		  if (selector->isReady(client))
		    {
		      sf::Packet packet;
		      if (client.receive(packet) == sf::Socket::Done)
			{
			  std::string pseudo;
			  packet >> pseudo;
			  Joueur *newJoueur = createJoueur(pseudo, &client);
			  joueurs.push_back(*newJoueur);
			  displayInfo("Client add to list");
			  displayInfo("Pseudo received from client");
			  std::cout << pseudo << std::endl;
			}
		    }   
		}
	    } 
	}
      if (joueurs.size() == 2 && role == true)
      	{
      	  std::cout << nextPort << std::endl;
      	  nextPort++;
      	  sf::Packet myPacket;
      	  sf::Thread threadSub(&createServer, false);
      	  myThreads.push_back(&threadSub);
	 
	  myThreads.back()->launch();
      	  myPacket << nextPort;
	  
      	  if( sendPacket(&myPacket, joueurs.front().socket) == false)
		 displayError("Pb envoi port au j1");
	  else displayInfo("Nouveau port envoyé");
       	   if( sendPacket(&myPacket, joueurs.back().socket) == false)
		  displayError("Pb envoi port au j2");
	   else displayInfo("Nouveau port envoyé");
      	  joueurs.clear();
	  clients.clear();
	  std::cout << joueurs.size() << std::endl;	 
      	}

      else  if (joueurs.size() == 2 && role == false)
      	{
      	  std::cout << "begin game" << std::endl;  
	  beginGame(joueurs);
 
      	}
      
	   
    }
}
