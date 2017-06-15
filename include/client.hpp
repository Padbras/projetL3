#ifndef		CLIENT_HPP_
# define	CLIENT_HPP_

#include	"Case.hpp"
#include	"Grille.hpp"
#include	"fenetreAccueil.hpp"
#include	"fenetrePosBateau.hpp"
#include	"fenetreJeu.hpp"
#include	"fenetreLoose.hpp"
#include	"fenetreWin.hpp"
#include	"network.hpp"
#include 	"gestionGrille.hpp"
#include "fenetreAttente.hpp"
#include "Player.hpp"

#include 	"fenetrePays.hpp"

// infos.cpp

// Surcharge des opérateurs >> et << de sf::Packet pour la
// transmission de la grille

sf::Packet	&operator <<(sf::Packet &, const Case &);
sf::Packet	&operator >>(sf::Packet &, Case &);

// fonctions d'envoi et de reception d'infos

Grille		receiveInfo(sf::TcpSocket *);
bool		sendInfo(sf::TcpSocket *, Grille);

bool		startClient(char *, int, bool, Player *);

#endif
