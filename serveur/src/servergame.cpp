#include	"network.hpp"

void		gameLoop(Joueur joueurUn, Joueur joueurDeux)
{
		/// \brief Permet de définir la boucle de jeu au niveau du serveur, avec les envois de paquets associés
  int tour = 0;
  int tmpBoat;
  bool running = true;
  sf::Packet myPacket; 
  Grille grille;
  sf::Packet myBoat;

  while(running)
    {
	  whoPlays(joueurUn, joueurDeux, tour);
     // myPacket.clear();
      if(tour % 2 != 0) // Joueur Un joue
	{
	  std::cout << "dans le if" << std::endl; 
	  std::cout << "tour = " << tour << std::endl;
	  myBoat.clear();
	  myBoat = receivePacket(joueurUn.socket);
	  myBoat >> tmpBoat;
	  if (tmpBoat == 0)
		running = false;
	  std::cout << "tmpboat envoyé par j1 : " << tmpBoat << std::endl;
	  myBoat.clear();
	  myBoat << tmpBoat;
	  if (sendPacket(&myBoat, joueurDeux.socket) == false)
	  {
		  displayInfo("Failed to send nb boat");
		  return ;
	  }
	  grille = receiveGrille(joueurUn.socket);
	  if (sendGrille(joueurDeux.socket, grille) == false)
	  {
		  displayInfo("Failed to send grille");
		  return;
	  }
	  grille = receiveGrille(joueurUn.socket);
	  if (sendGrille(joueurDeux.socket, grille) == false)
	  {
		  displayInfo("Failed to send grille");
		  return;
	  }
	  myPacket.clear();
	  myPacket = receivePacket(joueurUn.socket);
	  myPacket >> tour;
	  myPacket << false;
	  
	  std::cout << "Nouveau tour : " << tour << std::endl; 
	  
	}
      else // Joueur Deux joue
	{
	  std::cout << "dans le else" << std::endl; 
	  std::cout << "tour = " << tour << std::endl;
	  myBoat.clear();
	  myBoat = receivePacket(joueurDeux.socket);
	  myBoat >> tmpBoat;
	  if (tmpBoat == 0)
		running = false;
	  std::cout << "tmpboat envoyé par j2 : " << tmpBoat << std::endl;
	  myBoat.clear();
	  myBoat << tmpBoat;
	  if (sendPacket(&myBoat, joueurUn.socket) == false)
	  {
		  displayInfo("Failed to send nb boat");
		  return ;
	  }
	   grille = receiveGrille(joueurDeux.socket);
	  if (sendGrille(joueurUn.socket, grille) == false)
	  {
	  }
	  grille = receiveGrille(joueurDeux.socket);
	  if (sendGrille(joueurUn.socket, grille) == false)
	  {
	  } 
	  myPacket.clear();
	  myPacket = receivePacket(joueurDeux.socket);
	  myPacket >> tour;
	  std::cout << "Nouveau tour : " << tour << std ::endl;
	}
    }
}
