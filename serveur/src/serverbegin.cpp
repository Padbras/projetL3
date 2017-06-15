#include	"network.hpp"

void		whoPlays(Joueur joueurUn, Joueur joueurDeux, int tour)
{
  /// \brief Ordonnanceur des tours de jeu 
  sf::Packet	begin;

  if (tour % 2 != 0)
    {
      begin << true; // Tour pair
      if (sendPacket(&begin, joueurUn.socket) == false)
	displayError("Failed to send begin packet");
      
      begin.clear();
      begin << false;
      
      if (sendPacket(&begin, joueurDeux.socket) == false)
	displayError("Failed to send begin packet");	
    }
  else
    {
      begin << false; //Tour impair
      if (sendPacket(&begin, joueurUn.socket) == false)
	displayError("Failed to send begin packet");
      
      begin.clear();
      begin << true;
      
      if (sendPacket(&begin, joueurDeux.socket) == false)
	displayError("Failed to send begin packet"); 
    } 
}

int		beginGame(std::list<Joueur> joueurs)
{
  /// \brief Permet de commencer une partie de bataille navale, et de déclancher la boucle de jeu
  std::cout << "Entre dans begin game" << std::endl; 
  sf::Packet	myPacket;
  Joueur	joueurUn = joueurs.front();
  Joueur	joueurDeux = joueurs.back();

  
  myPacket << true; // La partie est trouvée, et prête à lancer
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
  else
    {
      displayInfo("First Info transmit");
      displayInfo("Game start");
      gameLoop(joueurUn, joueurDeux);
    }
  return joueurUn.socket->getLocalPort();  
}
