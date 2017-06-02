#ifndef		SERVER_HPP_
# define	SERVER_HPP_

#include	<iostream>
#include	<list>
#include	<memory>
#include	<sstream>
#include	<thread>
#include	<SFML/Network.hpp>

#define		PORT 8888

struct		Joueur
{
  std::string	pseudo;
  sf::TcpSocket	*socket;
};

// display.cpp

void		display_info(char *);
void		display_error(char *);

#endif		/* !SERVER_HPP_ */
