#ifndef		NETWORK_HPP_
# define	NETWORK_HPP_

#include	<iostream>
#include	<list>
#include	<memory>
#include	<sstream>
#include	<thread>
#include	<SFML/Network.hpp>

struct		Joueur
{
  std::string	pseudo;
  sf::TcpSocket	*socket;
};

// display.cpp

void		displayInfo(const char *);
void		displayError(const char *);

// packet.cpp

bool		sendPacket(sf::Packet *, sf::TcpSocket *);
sf::Packet	receivePacket(sf::TcpSocket);

// connect.cpp

bool		connectToServer(sf::TcpSocket *, char *, int);
void		disonnectFromServer(sf::TcpSocket);

#endif		/* !NETWORK_HPP_ */
