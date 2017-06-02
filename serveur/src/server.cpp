#include	"network.hpp"

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
	{
	  running = false;
	}
    }
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
  displayListJoueur(joueurs);
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
