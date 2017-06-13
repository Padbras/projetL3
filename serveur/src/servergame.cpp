//#include	<time.h>
#include	"network.hpp"

void		gameLoop(Joueur joueurUn, Joueur joueurDeux)
{
  //srand(time(NULL));
  int tour = 1;
  bool running = true;
  sf::Packet myPacket; 
  
  whoPlays(joueurUn, joueurDeux, tour);
  while(running)
    {
      myPacket.clear();
      if(tour % 2 != 0) // Joueur Un joue
	{
	  myPacket = receivePacket(&joueurUn.socket);
	  myPacket >> tour;
	}
      else // Joueur Deux joue
	{
	  myPacket = receivePacket(&joueurDeux.socket);
	  myPacket >> tour;
	}
      whoPlays(joueurUn, joueurDeux, tour);
    }
}
