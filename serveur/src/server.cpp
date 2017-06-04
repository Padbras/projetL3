#include	"network.hpp"
#include	"Grille.hpp"
  
Grille grilleP1;

void		gameLoop(std::list<Joueur> joueurs, sf::TcpListener *listener,
			 sf::SocketSelector *selector)
{

  

  /sf::Packet	toTransmit;
  sf::Packet	grilleJ1;
  Joueur	joueurUn = joueurs.front();
  Joueur	joueurDeux = joueurs.back();
  bool		running = true;
  std::string	str;
  
  while (running)
    {
      // if (joueurUn.socket->receive == sf::Socket::Done)
      // 	{
      toTransmit.clear();
      toTransmit = receivePacket(joueurUn.socket);
      toTransmit >> str;
      std::cout << str << std::endl;
      if (sendPacket(&toTransmit, joueurDeux.socket) == false)
	displayError("failed to send packet");
      else
	displayInfo("packet sent");
      // 	}
      // if (joueurDeux.socket == sf::Socket::Done)
      // 	{
      toTransmit.clear();
      toTransmit = receivePacket(joueurDeux.socket);
      toTransmit >> str;
      std::cout << str << std::endl;
      if (sendPacket(&toTransmit, joueurUn.socket) == false)
	displayError("failed to send packet");
      else
	displayInfo("packet sent");

//bool		sendPacket(sf::Packet *, sf::TcpSocket *);

	
		/*grilleJ1 = receivePacket(joueurUn.socket);
		grilleJ1 >> grilleP1;
		grilleP1.afficherGrille();*/
		
	


      // }
    }
}

std::list<Joueur> serverLoop(sf::TcpListener *listener, sf::SocketSelector *selector,
			     std::list<sf::TcpSocket *> clients)
{
  bool		running = true;
  std::list<Joueur> joueurs;
  
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
      if (joueurs.size() == 2)
	running = false;
    }
  gameLoop(joueurs, listener, selector);
  return joueurs;
}

void		createServer(int port)
{
  sf::TcpListener listener;
  std::list<Joueur> joueurs;
  std::list<sf::TcpSocket *> clients;
  sf::SocketSelector selector;

  displayInfo("Server started");
  listener.listen(port);
  selector.add(listener);

  joueurs = serverLoop(&listener, &selector, clients);
  // displayListJoueur(joueurs);
}


int		main(int ac, char **av)
{
  if (ac != 2)
    {
      displayError("Only one argument, specify the port please.");
      displayInfo("usage : ./server.out [PORT]");
      exit(-1);
    }
  createServer(atoi(av[1]));
  return 0;
}
