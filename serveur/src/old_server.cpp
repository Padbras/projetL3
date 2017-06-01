#include	<iostream>
#include	<list>
#include	<memory>
#include	<sstream>
#include	<thread>
#include	<SFML/Network.hpp>

#define		INFO "[\033[32mINFO\033[0m] : "
#define		ERRO "[\033[31mERROR\033[0m] : "

int		new_server(int port)
{
  std::cout << INFO << "Second server started" << std::endl;

  // initialisation des sockets et selectors
  using uptrSocket_t = std::unique_ptr<sf::TcpSocket>;
  std::list<uptrSocket_t> sockets;
  sf::SocketSelector selector;
  
  // initialisation listener
  sf::TcpListener listener;
  if (listener.listen(port) != sf::Socket::Done)
    {
      std::cout << ERRO << "Listening impossible" << std::endl;
      exit(-1);
    }
  selector.add(listener);
  std::string	wlcmMsg = "You're connected";
  sf::Packet	packetToClient;
  packetToClient << wlcmMsg;
  
  while (true)
    {
      // wait for data
      if (selector.wait())
	{
	  // data from the listener (new client)
	  if (selector.isReady(listener))
	    {
	      // accept a new client
	      uptrSocket_t uptrSocket = std::make_unique<sf::TcpSocket>();
	      if (listener.accept(*uptrSocket) != sf::Socket::Done)
		continue;
	      std::cout << INFO << "Client connected" << std::endl;

	      // register the new client
	      selector.add(*uptrSocket);
	      sockets.push_front(std::move(uptrSocket));
	    }
	  else
	    {
	      for (uptrSocket_t & clientSocket: sockets)
		{
		  // we found the client
		  if (selector.isReady(*clientSocket))
		    {
		      // receive data from client
		      sf::Packet packetFromClient;
		      if (clientSocket->receive(packetFromClient)
			  != sf::Socket::Done)
			continue;
		      std::cout << INFO <<"Pseudo of client" << std::endl;
		      std::string pseudo;
		      while (packetFromClient >> pseudo)
			{
			  std::cout << pseudo;
			}
		      std::cout << std::endl;
		    }
		}
	    }
	}
    }
  return 0;  
}

int		main(int ac, char **av)
{
  std::cout << INFO << "Server started" << std::endl;

  // initialisation des sockets et selectors
  using uptrSocket_t = std::unique_ptr<sf::TcpSocket>;
  std::list<uptrSocket_t> sockets;
  sf::SocketSelector selector;
  
  // initialisation listener
  sf::TcpListener listener;
  if (listener.listen(8988) != sf::Socket::Done)
    {
      std::cout << ERRO << "Listening impossible" << std::endl;
      exit(-1);
    }
  selector.add(listener);
  std::string	wlcmMsg = "You're connected";
  sf::Packet	packetToClient;
  packetToClient << wlcmMsg;
  
  while (true)
    {
      // wait for data
      if (selector.wait())
	{
	  // data from the listener (new client)
	  if (selector.isReady(listener))
	    {
	      // accept a new client
	      uptrSocket_t uptrSocket = std::make_unique<sf::TcpSocket>();
	      if (listener.accept(*uptrSocket) != sf::Socket::Done)
		continue;
	      std::cout << INFO << "Client connected" << std::endl;

	      // register the new client
	      selector.add(*uptrSocket);
	      sockets.push_front(std::move(uptrSocket));
	    }
	  else
	    {
	      for (uptrSocket_t & clientSocket: sockets)
		{
		  // we found the client
		  if (selector.isReady(*clientSocket))
		    {
		      // receive data from client
		      sf::Packet packetFromClient;
		      if (clientSocket->receive(packetFromClient)
			  != sf::Socket::Done)
			continue;
		      std::cout << INFO <<"Pseudo of client" << std::endl;
		      std::string pseudo;
		      while (packetFromClient >> pseudo)
			{
			  std::cout << pseudo;
			}
		      std::cout << std::endl;
		      uptrSocket_t uptrSocket = std::make_unique<sf::TcpSocket>();
		      packetToClient << "7894";
		      if (uptrSocket->send(packetToClient) != sf::Socket::Done)
			continue;
		      new_server(7894);
		    }
		}
	    }
	}
    }
  return 0;
}
