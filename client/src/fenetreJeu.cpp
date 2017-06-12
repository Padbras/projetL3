#include "fenetreJeu.hpp"
#include "gestionGrille.hpp"
#include "fenetreWin.hpp"
#include "fenetreLoose.hpp"

using namespace sf;
using namespace std;

// return 1 si gagné, -1 si perdu

int fenetreJeu(Grille grilleMe, Grille grilleOpp, TcpSocket *mySocket){

  ////////////////// creation et init de la fenetre //////////////////

  RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : La Bataille ",Style::Titlebar);
  window.setPosition(Vector2i(10, 10));


  ////////////////// creation et init des variables //////////////////

  int cpt = 0;
  int victoire = 17;
  int defaite = 17;
  int x1 , x2 , x3, x4, x5, y1, y2, y3, y4, y5;
  x1 = x2 = x3 = x4 = x5 = y1 = y2 = y3 = y4 = y5 =0;
  Event event;


  ////////////////// chargement des fonts et textures /////////////////

  Texture fondEcran_tex;
  if (!fondEcran_tex.loadFromFile("../client/img/jeu.png")){
  }

  RectangleShape boutonValide(Vector2f(300, 60));
  boutonValide.setPosition(348,670);
  boutonValide.setFillColor(Color(0, 0, 0, 160));

  RectangleShape fenetreGrise(Vector2f(1000, 800));
  fenetreGrise.setPosition(0,0);


  //////////// creation des textes, sprites et textures //////////////
			
  Sprite fondEcran_spr(fondEcran_tex);
	
	
  //////////// affichage de la fenetre ///////////////////////////////

  Packet	whoTurn;
  Packet	tir;
  int		tir_x, tir_y;
  tir_x = tir_y = -1;
  bool		myTurn;
  
  whoTurn.clear();
  whoTurn = receivePacket(mySocket);
  whoTurn >> myTurn;
  
  while (window.isOpen())
    {      
      if (cpt > 0){
		boutonValide.setFillColor(Color(0, 0, 0, 0));
	
      window.clear(Color::White); 	
	      
      window.draw(fondEcran_spr);
      window.draw(boutonValide);
      for (int j = 0; j < 10; j++)
	for (int i = 0; i < 10; i++)
	  {
	    grilleMe._grille[i][j]._case_rect.setPosition(retGrGauchX(i), retGrGauchY(j));
	    window.draw(grilleMe._grille[i][j]._case_rect);	    
	  }
      for (int j = 0; j < 10; j++)
	for (int i = 0; i < 10; i++)
	  {
	    grilleOpp._grille[i][j]._case_rect.setPosition(retGrDroitX(i), retGrDroitY(j));
	    window.draw(grilleOpp._grille[i][j]._case_rect);  
	  }
      window.display();

      if (myTurn == false)
	{
	  fenetreGrise.setFillColor(Color(0, 0, 0, 160));
	  cpt = 0;
	  tir.clear();
	  tir = receivePacket(mySocket);
	  tir >> tir_x >> tir_y;
	  if (grilleMe._grille[tir_x][tir_y]._type == boat)
	    {
	      grilleMe._grille[tir_x][tir_y]._type = touch;
	      grilleMe._grille[tir_x][tir_y]._case_rect.setFillColor(sf::Color(255,0,0,128));
	      defaite--;
	      if (defaite == 0)
		return -1;
	    }
	  whoTurn.clear();
	  whoTurn = receivePacket(mySocket);
	  whoTurn >> myTurn;
	}
      //////////// gestion de la boule d'evenements///////////////////////
      
      if (myTurn == true)
	{
	  fenetreGrise.setFillColor(Color(0, 0, 0, 0));
	  while (window.pollEvent(event))
	    {
	      switch (event.type){				
	      case Event::MouseButtonPressed : // gestion de click dans la grille de tir
		if(	event.mouseButton.x < 933 && event.mouseButton.x >533 && 
			event.mouseButton.y < 600 && event.mouseButton.y > 200){		
		  x1 = ptRetourX(event.mouseButton.x);
		  y1 = ptRetourY(event.mouseButton.y);
		  grilleOpp._grille[x1][y1]._case_rect.setFillColor(sf::Color(128,128,128,128));
		  cpt++;				
		}
					
		//gestion du click sur le bouton
		if(	event.mouseButton.x < 648 && event.mouseButton.x >348 && 
			event.mouseButton.y < 730 && event.mouseButton.y > 670 && cpt == 1)
		  {
		    cpt = 0;
		    tir.clear();
		    tir << x1 << y1;
		    if (sendPacket(&tir, mySocket) == false)
		      {

		      }
		    if (grilleOpp._grille[x1][y1]._type == boat)
		      {
		        grilleOpp._grille[x1][y1]._type = touch;
		        grilleOpp._grille[x1][y1]._case_rect.setFillColor(sf::Color(0,255,0,128));
			victoire--;
			if (victoire == 0)
			  return 1;
		      }
		    else if (grilleOpp._grille[x1][y1]._type == mer)
		      {
		        grilleOpp._grille[x1][y1]._type = miss;
			grilleOpp._grille[x1][y1]._case_rect.setFillColor(sf::Color(255,0,0,128));
		      }  
		    grilleOpp.afficherGrille();
		    myTurn = false;
		    whoTurn.clear();
		    whoTurn << myTurn;
		    if (sendPacket(&whoTurn, mySocket) == false)
		      {

		      }
		  }
		break;
						
	      default:
		break;
	      }
	    }
/*	    
    //////////// gestion colorimetrie des boutons  ///////////////////////////
	
    if (cptBateauPos == 5 ){
      boutonGuerre.setFillColor(Color(0, 0, 0, 0));
    }
	
	  if (cpt < 1){
	    bouton.setFillColor(Color(128, 128, 128, 128));
	  }
	  else
	    bouton.setFillColor(Color(0,0,0,0));*/
	}
    }
  return 0;
}


