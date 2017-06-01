#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <thread>
#include <SFML/Network.hpp>

#define PORT 8888

struct Joueur {
  std::string pseudo;
  sf::TcpSocket *socket;
};

int main()
{
  std::cout << "Server start" << std::endl;
  // Create a socket to listen to new connections
  sf::TcpListener listener;
  listener.listen(PORT);
  std::cout << "Listening on "<< PORT << std::endl;
  // Create a list to store the future clients
  std::list<Joueur> joueurs;
  std::list<sf::TcpSocket*> clients;
  // Create a selector
  sf::SocketSelector selector;
  // Add the listener to the selector
  selector.add(listener);
  // Endless loop that waits for new connections
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
		  std::cout << "Client connected" << std::endl;
		  std::cout << "Nombre de clients : " << clients.size() << std::endl;
		  // sf::Packet packetPort;
		  // packetPort << 7894;
		  // if (client->send(packetPort) == sf::Socket::Done)
		  //   {
		  //     std::cout << "Port send" << std::endl;
		     
		  // new_server(7894); 
		  //   }
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
		      if (client.receive(packet) == sf::Socket::Done)
			{
			  std::cout << "Pseudo client" << std::endl;
			  std::string pseudo;
			  packet >> pseudo;
			  Joueur *newJoueur = new Joueur;
			  newJoueur->socket = &client;
			  newJoueur->pseudo = pseudo;
			  joueurs.push_back(*newJoueur);
			  std::cout << pseudo << std::endl;
			  std::cout << "Nombre de joueurs : " << joueurs.size() << std::endl;
			  // for (Joueur x : joueurs)
			  //   {
			  //     std::cout << x.pseudo << std::endl;
			  //   }
			}
		    }
		}
	    }
	  // 
	  if (joueurs.size() == 2 )
	    {
	      // std::cout << "Two players detected" << std::endl;
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
}
