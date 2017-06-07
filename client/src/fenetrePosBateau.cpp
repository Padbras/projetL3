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
  int x1 = -1;
  int y1 = -1;
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
	  x1 = gdRetourX(event.mouseButton.x);
	  y1 = gdRetourY(event.mouseButton.y);
	  switch (cpt){
	      case 1 :
	    verifPlaceNord(&grille, x1, y1, 5);
	    //  posBateauNord(&grille, x1, y1, 2);
		//placeBateau(&grille, x1, y1,2,rotate);  
		//Place les bateaux dans la grille, vers le nord par défaut				
		break;
		// Rajouter: si pas possible vers le nord, rotate pour trouver une position valable
		// Et place le bateau par défaut dans une position valable
	      case 2 :
		placeBateau(&grille, x1, y1,3, rotate);
		break;
								
	      case 3 :
		placeBateau(&grille, x1, y1,3, rotate);
		break;
								
	      case 4 :
		placeBateau(&grille, x1, y1,4, rotate);
		break;
								
	      case 5 :
		placeBateau(&grille, x1, y1,5, rotate);
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
			x1 >= 0 && y1 >= 0){	
          x1 = y1 = -1;
	  cpt++;
	}
	break;

	// case Event::KeyPressed : 
	 
	//   if (event.key.code == Keyboard::R )
	//     rotate++;
	//   if (rotate == 4)
	//     rotate =0;
	// switch (cpt){
	//       case 1 :
	// 	placeBateau(&grille, x1, y1,2,rotate);
	// 	//Place les bateaux dans la grille, vers le nord par défaut				
	// 	break;
	// 	// Rajouter: si pas possible vers le nord, rotate pour trouver une position valable
	// 	// Et place le bateau par défaut dans une position valable
	//       case 2 :
	// 	placeBateau(&grille, x1, y1,3, rotate);
	// 	break;
								
	//       case 3 :
	// 	placeBateau(&grille, x1, y1,3, rotate);
	// 	break;
								
	//       case 4 :
	// 	placeBateau(&grille, x1, y1,4, rotate);
	// 	break;
								
	//       case 5 :
	// 	placeBateau(&grille, x1, y1,5, rotate);
	// 	break;
	//       }
	  
	//   std::cout << "rotate " <<rotate << std::endl;
	//   break;
	
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


