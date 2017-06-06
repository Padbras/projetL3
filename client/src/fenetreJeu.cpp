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
  int victoire = 1;
  int defaite = 1;
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
  Packet	tir;
  int		tir_x, tir_y;
  tir_x = tir_y = -1;
  bool		myTurn;
  int		cpt2 = 0;
  
  whoTurn.clear();
  whoTurn = receivePacket(mySocket);
  whoTurn >> myTurn;
  
  while (window.isOpen())
    {      
      if (cpt < 1){
	bouton.setFillColor(Color(128, 128, 128, 128));
      }
      else
	bouton.setFillColor(Color(0,0,0,0));
      window.clear(Color::White); 	
	      
      window.draw(fondEcran_spr);
      window.draw(bouton);
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
	  std::cout << "tir x " << tir_x << " tir y " << tir_y << std::endl;
	  whoTurn.clear();
	  whoTurn = receivePacket(mySocket);
	  whoTurn >> myTurn;
	}
      //////////// gestion de la boule d'evenements///////////////////////
      
      if (myTurn == true)
	{
	  while (window.pollEvent(event))
	    {
	      switch (event.type){				
	      case Event::MouseButtonPressed : // gestion de click dans la grille de tir
		if(	event.mouseButton.x < 933 && event.mouseButton.x >533 && 
			event.mouseButton.y < 600 && event.mouseButton.y > 200){		
		  x1 = ptRetourX(event.mouseButton.x);
		  y1 = ptRetourY(event.mouseButton.y);
		  cout << x1 << "  " << y1 << endl;
		  grilleOpp._grille[x1][y1]._case_rect.setFillColor(sf::Color(128,128,128,128));
		  cpt++;				
		}
					
		//gestion du click sur le bouton
		if(	event.mouseButton.x < 648 && event.mouseButton.x >348 && 
			event.mouseButton.y < 730 && event.mouseButton.y > 670 && cpt == 1)
		  {
		    cpt = 0;
		    tir.clear();
		    std::cout << "x1 " << x1 << " y1 " << y1 << std::endl;
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
			//std::cout << "nombre de case restantes : " << victoire << std::endl;
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
	  if (cpt < 1){
	    bouton.setFillColor(Color(128, 128, 128, 128));
	  }
	  else
	    bouton.setFillColor(Color(0,0,0,0));
	  // window.clear(Color::White); 	
	 
	  // window.clear(Color::White); 	
	      
	  // window.draw(fondEcran_spr);
	  // window.draw(bouton);
	  // for (int j = 0; j < 10; j++)
	  //   for (int i = 0; i < 10; i++)
	  //     {
	  // 	grilleMe._grille[i][j]._case_rect.setPosition(retGrGauchX(i), retGrGauchY(j));
	  // 	window.draw(grilleMe._grille[i][j]._case_rect);	    
	  //     }
	  // for (int j = 0; j < 10; j++)
	  //   for (int i = 0; i < 10; i++)
	  //     {
	  // 	grilleOpp._grille[i][j]._case_rect.setPosition(retGrDroitX(i), retGrDroitY(j));
	  // 	window.draw(grilleOpp._grille[i][j]._case_rect);  
	  //     }
	  // window.display();
	}
    }
  return 0;
}


