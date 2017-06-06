#include "fenetreJeu.hpp"
#include "gestionGrille.hpp"
#include "fenetreWin.hpp"
#include "fenetreLoose.hpp"

using namespace sf;
using namespace std;

int retTrueX(int x)
{
  return (66 + 40 * x);
}

int retTrueY(int y)
{
  return (200 + 40 * y);
}

int fenetreJeu(Grille grilleMe, Grille grilleOpp, TcpSocket *mySocket){

  ////////////////// creation et init de la fenetre //////////////////

  RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : La Bataille ",Style::Titlebar);
  window.setPosition(Vector2i(10, 10));


  ////////////////// creation et init des variables //////////////////

  int cpt = 0;
  int x1 , x2 , x3, x4, x5, y1, y2, y3, y4, y5;
  x1 = x2 = x3 = x4 = x5 = y1 = y2 = y3 = y4 = y5 =0;
  Event event;


  ////////////////// chargement des fonts et textures /////////////////

  Texture fondEcran_tex;
  if (!fondEcran_tex.loadFromFile("../client/img/jeu.png")){
  }

  RectangleShape bouton(Vector2f(300, 60));
  bouton.setPosition(348,670);
  bouton.setFillColor(Color(255, 0, 0, 50));


  //////////// creation des textes, sprites et textures //////////////
			
  Sprite fondEcran_spr(fondEcran_tex);
	
	
  //////////// affichage de la fenetre ///////////////////////////////

  Packet	whoTurn;
  bool		myTurn;

  whoTurn.clear();
  whoTurn = receivePacket(mySocket);
  whoTurn >> myTurn;

  int cpt2 = 0;
  while (window.isOpen())
    {
      if (myTurn == false)
	{
	  if (cpt2 < 1)
	    {
	      window.clear(Color::White); 	
	      
	      window.draw(fondEcran_spr);
	      window.draw(bouton);
	            for (int j = 0; j < 10; j++)
	for (int i = 0; i < 10; i++)
	  {
	    grilleMe._grille[i][j]._case_rect.setPosition(retTrueX(i), retTrueY(j));
	    window.draw(grilleMe._grille[i][j]._case_rect);
	    
	  }

	      window.display();
	      cpt2++;
	    }
	  whoTurn.clear();
	  whoTurn = receivePacket(mySocket);
	  whoTurn >> myTurn;
	}
      //////////// gestion de la boule d'evenements///////////////////////

      while (window.pollEvent(event))
	{
	  cout << "rentre dans le while event " << endl;
	  cout << "1" << myTurn << endl;
	  if ( myTurn == true)
	    {
	      cout << "2" << myTurn << endl;
	      switch (event.type){
				
	      case Event::MouseButtonPressed : // gestion de click dans la grille de tir
		if(	event.mouseButton.x < 933 && event.mouseButton.x >533 && 
			event.mouseButton.y < 600 && event.mouseButton.y > 200){		
		  x1 = ptRetourX(event.mouseButton.x);
		  y1 = ptRetourY(event.mouseButton.y);
		  cout << x1 << "  " << y1 << endl;
		  cpt++;				
		}
					
		//gestion du click sur le bouton
		if(	event.mouseButton.x < 648 && event.mouseButton.x >348 && 
			event.mouseButton.y < 730 && event.mouseButton.y > 670)
		  {
		    if (grilleOpp._grille[x1][y1]._type == boat)
		      {
		        grilleOpp._grille[x1][y1]._type = touch;
		        // affichage vert
		      }
		    else if (grilleOpp._grille[x1][y1]._type == mer)
		      {
		        grilleOpp._grille[x1][y1]._type = miss;
		        // affichage rouge
		      }
		    myTurn = false;
		    whoTurn.clear();
		    whoTurn << myTurn;
		    if (sendPacket(&whoTurn, mySocket) ==false)
		      {

		      }
		  }
		break;
						
	      default:
		break;
	      }
	    }
	  else
	    {
	      cout << "tour de l'adversaire" << endl;
	      cout << "3" << myTurn << endl;
	    }
	}

      //////////// gestion colorimetrie du bouton  ///////////////////////////

      if (cpt > 0 ){
	bouton.setFillColor(Color(0, 255, 0, 50));
      }


      ///////////// gestion de l'affichage //////////////////

      window.clear(Color::White); 	
		
      window.draw(fondEcran_spr);
      window.draw(bouton);
      for (int j = 0; j < 10; j++)
	for (int i = 0; i < 10; i++)
	  {
	    grilleMe._grille[i][j]._case_rect.setPosition(retTrueX(i), retTrueY(j));
	    window.draw(grilleMe._grille[i][j]._case_rect);
	    
	  }
      window.display();
    
    }

  return 0;
}


