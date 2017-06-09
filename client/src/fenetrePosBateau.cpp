#include "fenetrePosBateau.hpp"
#include "gestionGrille.hpp"
#include "gestionBateau.hpp"
#include "fenetreJeu.hpp"
#include "Grille.hpp"

using namespace sf;
using namespace std;

Grille fenetrePosBateau(){

////////////////// creation et init de la fenetre //////////////////

  RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : Positionnes tes bateaux Matelot !!",Style::Titlebar);
  window.setPosition(Vector2i(10, 10));


  ////////////////// creation et init des variables //////////////////

  int cpt = 1;
  int x = -1;
  int y = -1;
  int x2,y2;
  int rotate = 0;
  Event event;
  Grille grille;


  ////////////////// chargement des fonts et textures /////////////////

  Texture fondEcran_tex;
  if (!fondEcran_tex.loadFromFile("../client/img/bateau.png")){
  }
	
  RectangleShape bouton(Vector2f(400, 78));
  bouton.setPosition(300,713);
  bouton.setFillColor(Color(0, 0, 0, 128));


  //////////// creation des textes, sprites et textures //////////////
			
  Sprite fondEcran_spr(fondEcran_tex);
	

  //////////// affichage de la fenetre ///////////////////////////////

  while (window.isOpen()){

	
    //////////// gestion de la boule d'evenements///////////////////////

    while (window.pollEvent(event)){
			
      switch (event.type){
				
      case Event::MouseButtonPressed : // gestion de click dans la grille
	if(	event.mouseButton.x < 700 && event.mouseButton.x >300 && 
		event.mouseButton.y < 700 && event.mouseButton.y > 300 && cpt < 6
		){		
	  x = gdRetourX(event.mouseButton.x);
	  y = gdRetourY(event.mouseButton.y);
	  switch (cpt){
	      case 1 :	      
			posBateau(&grille, x, y, 2, rotate);			
		break;
	     
	      case 2 :
			posBateau(&grille, x, y, 3, rotate);
		break;
								
	      case 3 :
			posBateau(&grille, x, y, 3, rotate);
		break;
								
	      case 4 :
			posBateau(&grille, x, y, 4, rotate);
		break;
								
	      case 5 :
			posBateau(&grille, x, y, 5, rotate);
		break;
	      }
	}
					
	//gestion du click sur le bouton demarrer
	else if(	event.mouseButton.x < 700 && event.mouseButton.x >300 && 
			event.mouseButton.y < 791 && event.mouseButton.y > 713 && cpt == 6
			){
	  window.close();
	  return grille;
	}
					
	// gestion bouton valide bateau
	else if(	event.mouseButton.x < 650 && event.mouseButton.x > 350 && 
			event.mouseButton.y < 280 && event.mouseButton.y > 221 &&
			x >= 0 && y >= 0){	
          x = y = -1;
	  cpt++;
	}
	break;

	 case Event::KeyPressed : 
	 
	  if (event.key.code == Keyboard::R ){
	     rotate++;
		 if (rotate == 4){
	      rotate =0;
	     }
	  }
	    break;
	    
      default:					
	break;
      }	
    }


    //////////// gestion colorimetrie du bouton  ///////////////////////////
	
    if (cpt == 6 ){
      bouton.setFillColor(Color(0, 0, 0, 0));
    }
	
    ///////////// gestion de l'affichage //////////////////
    window.clear(Color::White); 	
		
    window.draw(fondEcran_spr);
    window.draw(bouton);
    x2 = y2 =0;
    while ( y2 < 10){
      while( x2 < 10){
	window.draw(grille._grille[x2][y2]._case_rect);
	x2++;
      }
      x2 = 0;
      y2++;
    }
      
    window.display();
        
  }
}


