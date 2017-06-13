#include	"network.hpp"

void		gameLoop(Joueur joueurUn, Joueur joueurDeux)
{
  bool		running = true;
  bool		turnUn = true;
  bool		turnDeux = false;
  int		x, y;
  sf::Packet	tir;
  sf::Packet	turn;
  
  whoBegin(joueurUn, joueurDeux);
  while (running)
    {
      displayInfo("tour joueur 1");
      tir.clear();
      tir = receivePacket(joueurUn.socket);
      tir >> x >> y;
      std::cout << "x " << x << " y " << y << std::endl;
      turn.clear();
      turn = receivePacket(joueurUn.socket);
      turn >> turnUn;
      
      if (turnUn == false)
	{
	  tir.clear();
	  tir << x << y;
	  if (sendPacket(&tir, joueurDeux.socket) == false)
	    {
	      displayError("Probleme pour envoyer eul tir");
	    }
	     
	  displayInfo("debut tour joueur 2");
	  turn.clear();
	  turn << true;
	  if (sendPacket(&turn, joueurDeux.socket) == false)
	    {

	    }
	}
      displayInfo("tour joueur 2");
      tir.clear();
      tir = receivePacket(joueurDeux.socket);
      tir >> x >> y;
      std::cout << "x " << x << " y " << y << std::endl;
      turn.clear();
      turn = receivePacket(joueurDeux.socket);
      turn >> turnDeux;
      if (turnDeux == false)
	{
	  tir.clear();
	  tir << x << y;
	  if (sendPacket(&tir, joueurUn.socket) == false)
	    {
	      displayError("Probleme pour envoyer eul tir");
	    }
	  displayInfo("debut tour joueur 2");
	  turn.clear();
	  turn << true;
	  if (sendPacket(&turn, joueurUn.socket) == false)
	    {
	      
	    }
	}
    }
}
