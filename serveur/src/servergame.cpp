//#include	<time.h>
#include	"network.hpp"

void		gameLoop(Joueur joueurUn, Joueur joueurDeux)
{
  //srand(time(NULL));
  int tour = 0;
  bool running = true;
  sf::Packet myPacket; 
  
  whoPlays(joueurUn, joueurDeux, tour);

  while(running)
    {
      myPacket.clear();
      if(tour % 2 != 0) // Joueur Un joue
	{
	  std::cout << "dans le if" << std::endl; 
	  std::cout << "tour = " << tour << std::endl; 
	  myPacket = receivePacket(joueurUn.socket);
	  myPacket >> tour;
	  std::cout << "Nouveau tour : " << tour << std::endl; 
	  
	}
      else // Joueur Deux joue
	{
	  std::cout << "dans le else" << std::endl; 
	  std::cout << "tour = " << tour << std::endl; 
	  myPacket = receivePacket(joueurDeux.socket);
	  myPacket >> tour;
	  std::cout << "Nouveau tour : " << tour << std ::endl;
	}
      whoPlays(joueurUn, joueurDeux, tour);
    }
}
