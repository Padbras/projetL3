#ifndef		NETWORK_HPP_
# define	NETWORK_HPP_

#include	<iostream>
#include	<list>
#include	<memory>
#include	<sstream>
#include	<thread>
#include	<SFML/Network.hpp>
#include        <SFML/System.hpp>

#include	"client.hpp"
#include	"Grille.hpp"


#define		NB_MAX_THREAD 10;
extern		int nextPort;
struct		Joueur
{
  std::string	pseudo;
  sf::TcpSocket	*socket;
};

struct defServer
{
  bool		role;
  int		port ;
  
};

struct myThreads
{
  int		id;
  bool		isReady;
  defServer	def;
  sf::Thread	*myThread;
};

extern		std::vector<myThreads *> mySubServers;

// display.cpp

void		displayInfo(const char *);
void		displayError(const char *);

// packet.cpp

bool		sendPacket(sf::Packet *, sf::TcpSocket *);
sf::Packet	receivePacket(sf::TcpSocket *);

// connect.cpp

bool		connectToServer(sf::TcpSocket *, char *, int);
void		disonnectFromServer(sf::TcpSocket);

// joueur.cpp

Joueur		*createJoueur(std::string, sf::TcpSocket *);
void		displayJoueur(Joueur myJoueur);
void		displayListJoueur(std::list<Joueur>);

// server.cpp
void		createServer(defServer def);

// serverloop.cpp

void		serverLoop(sf::TcpListener*, sf::SocketSelector *,
		std::list<sf::TcpSocket *> , defServer);

// servergame.cpp
void		gameLoop(Joueur, Joueur);  

// serverbegin.cpp
void		beginGame(std::list<Joueur>);
void		whoBegin(Joueur, Joueur);

// servertransmit.cpp
bool		transmitFirstInfo(Joueur, Joueur);

// subserver.cpp

void		initSubServers(std::vector<myThreads *> *, int);
void		launchSubServer(std::vector<myThreads *> *, int);
int		returnFirstSubReady(std::vector<myThreads *>);
int		returnPortSubServer(std::vector<myThreads *>, int);

#endif		/* !NETWORK_HPP_ */


