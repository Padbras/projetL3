#include <time.h>
#include "network.hpp"


void		whoBegin(Joueur joueurUn, Joueur joueurDeux)
{
  sf::Packet	begin;
  srand(time(NULL));

  if (rand()%2 == 0)
    {
      begin << true;
      if (sendPacket(&begin, joueurUn.socket) == false)
	displayError("Failed to send begin packet");

      begin.clear();
      begin << false;
      if (sendPacket(&begin, joueurDeux.socket) == false)
	displayError("Failed to send begin packet");
    }
  
  else
    {
      begin << false;
      if (sendPacket(&begin, joueurUn.socket) == false)
	displayError("Failed to send begin packet");
      begin.clear();
      begin << true;
      if (sendPacket(&begin, joueurDeux.socket) == false)
	displayError("Failed to send begin packet");
    } 
}

void		beginGame(std::list<Joueur> joueurs)
{
  std::cout << "Entre dans begin game" << std::endl; 
  bool		running = true;
  sf::Packet	myPacket;
  Joueur	joueurUn = joueurs.front();
  Joueur	joueurDeux = joueurs.back();

  myPacket << true;
  if (sendPacket(&myPacket, joueurUn.socket) == false)
    {
      displayError("Failed to send packet (bool to j1)");
    }
  if (sendPacket(&myPacket, joueurDeux.socket) == false)
    {
      displayError("Failed to send packet (bool to j2)");
    }
  
  if (transmitFirstInfo(joueurUn, joueurDeux) == false)
    {
      displayError("Failed to transmit");
    }
  displayInfo("First Info transmit");
  displayInfo("Game start");
  gameLoop(joueurUn, joueurDeux);
}
