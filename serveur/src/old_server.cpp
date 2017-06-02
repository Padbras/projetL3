#include	"server.hpp"

int		main()
{
  // Création d'une socket pour écouter les nouvelles connexions
  sf::TcpListener listener;
  // Create a list to store the future clients
  std::list<Joueur> joueurs;
  std::list<sf::TcpSocket*> clients;;
  // Creation d'un selector
  sf::SocketSelector selector;
  displayInfo("Server start");
  // On commence à écouter le port
  listener.listen(PORT);
  //display_info("Listening on port n°");
  std::cout << PORT << std::endl;
  // Ajout du listener dans le selector
  selector.add(listener);
  // Boucle principale
  while (true)
    {
      // Make the selector wait for data on any socket
      if (selector.wait())
	{
	  // Test the listener
	  if (selector.isReady(listener))
	    {
	      // The listener is ready: there is a pending connection
	      sf::TcpSocket* client = new sf::TcpSocket;
	      if (listener.accept(*client) == sf::Socket::Done)
		{
		  // Add the new client to the clients list
		  clients.push_back(client);
		  // Add the new client to the selector so that we will
		  // be notified when he sends something
		  selector.add(*client);
		  //display_info("Client connected");
	        }
	      else
		{
		  // Error, we won't get a new connection, delete the socket
		  delete client;
		}
	    }
	  else
	    {
	      // The listener socket is not ready, test all other sockets (the clients)
	      for (std::list<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it)
		{
		  sf::TcpSocket& client = **it;
		  if (selector.isReady(client))
		    {
                    // The client has sent some data, we can receive it
		      sf::Packet packet;
		      // On recoit le pseudo du client
		      if (client.receive(packet) == sf::Socket::Done)
			{
			  //display_info("Pseudo client :");
			  std::string pseudo;
			  packet >> pseudo;
			  // on ajoute un nouveau joueur a notre liste de joueurs
			  Joueur *newJoueur = new Joueur;
			  newJoueur->socket = &client;
			  newJoueur->pseudo = pseudo;
			  joueurs.push_back(*newJoueur);
			  //display_info(pseudo.c_str());
			  //std::cout << "Nombre de joueurs : " << joueurs.size() << std::endl;
	        	}
		    }
		}
	    }
	  // si deux joueurs sont connectés on procede à l'échange des pseudos 
	  if (joueurs.size() == 2 )
	    {
	      // a modifier
	      sf::Packet pseudo1;
	      pseudo1 << joueurs.front().pseudo;
	      if (joueurs.back().socket->send(pseudo1) == sf::Socket::Done)
		{
		  std::cout << "Pseudo de " << joueurs.front().pseudo <<
		    " envoyé à " << joueurs.back().pseudo << std::endl;
		}
	      sf::Packet pseudo2;
	      pseudo2 << joueurs.back().pseudo;
	      if (joueurs.front().socket->send(pseudo2) == sf::Socket::Done)
		{
		  std::cout << "Pseudo de " << joueurs.back().pseudo <<
		    " envoyé à " << joueurs.front().pseudo << std::endl;
		}
	    }
	 
	}
    }
  return 0;
}
