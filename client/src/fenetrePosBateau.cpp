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

  Event event;
  Grille grille;
  int taille[5] = {2,3,3,4,5}; 
  int x, y, xOld, yOld ,i , j, rotateOld, cptBateauPos, rotate, cptBateauPosOld;
  bool bateauValide = false; 
  xOld = yOld = x = y = -1;
  cptBateauPos = cptBateauPosOld = rotate = 0;


  ////////////////// chargement des fonts et textures /////////////////

  Texture fondEcran_tex;
  if (!fondEcran_tex.loadFromFile("../client/img/bateau.png")){
  }
  // bouton entrer en guerre
  RectangleShape boutonGuerre(Vector2f(400, 78));
  boutonGuerre.setPosition(300,713);
  boutonGuerre.setFillColor(Color(0, 0, 0, 160));
  
  //bouton de validation de bateau
  RectangleShape boutonValide(Vector2f(300,59));
  boutonValide.setPosition(350,221);
  boutonValide.setFillColor(Color(0,0,0,160));


  //////////// creation des textes, sprites et textures //////////////
			
  Sprite fondEcran_spr(fondEcran_tex);
	

  //////////// affichage de la fenetre ///////////////////////////////

  while (window.isOpen()){

	
    //////////// gestion de la boule d'evenements///////////////////////

    while (window.pollEvent(event)){
			
      switch (event.type){
				
      case Event::MouseButtonPressed : 
      
      
	// gestion de click dans la grille
	if(	event.mouseButton.x < 700 && event.mouseButton.x >300 && 
		event.mouseButton.y < 700 && event.mouseButton.y > 300 && cptBateauPos < 6
		)
	  {		
	    if(x != -1)
	      {
		xOld = x;
		yOld = y;
		rotateOld=rotate;
	      } 	  
	    x = gdRetourX(event.mouseButton.x);
	    y = gdRetourY(event.mouseButton.y);
		
	    // effacement du bateau prec si bateau placé precedemment	
	    if (verifMer(&grille, x, y))
	      {
		
		if(verifPlace(&grille, xOld, yOld, taille[cptBateauPos], rotate) && cptBateauPosOld != cptBateauPos )
		  { 
		    eraseBateau(&grille, xOld, yOld, taille[cptBateauPos], rotate);
		  }
		setMer(&grille, xOld, yOld);
		bateauValide = posBateau(&grille, x, y, taille[cptBateauPos], rotate); // pos un bateau a x y 
		cptBateauPosOld++;
	      }
	    else
	      {
		x = y = -1;
	      }	
	  }	
			
	//gestion du click sur le bouton partir en guerre
	else if(	event.mouseButton.x < 700 && event.mouseButton.x >300 &&
			event.mouseButton.y < 791 && event.mouseButton.y > 713 && cptBateauPos == 5
			)
	  {
	    window.close();
	    return grille;
	  }
					
	// gestion bouton valider bateau
	else if(	event.mouseButton.x < 650 && event.mouseButton.x > 350 && 
			event.mouseButton.y < 280 && event.mouseButton.y > 221 &&
			x >= 0 && y >= 0 && bateauValide)
	  {	
	    x = y = xOld = yOld = bateauValide = -1;
	    rotate = 0;
	    cptBateauPos++;
	    cptBateauPosOld = cptBateauPos;
	    bateauValide = false;
	  }
	break;
	    
      case Event::KeyPressed : 
	 
	if (event.key.code == Keyboard::R )
	  {
	    if (x != -1){
	      rotateOld = rotate;
	      rotate++;
	      if (rotate == 4) // tour complet effectué
		rotate =0;

	      if(verifPlace(&grille, x, y, taille[cptBateauPos], rotateOld))
		{
		  eraseBateau(&grille, x, y, taille[cptBateauPos], rotateOld);
		}
	      else
		{
		  setMer(&grille, x, y);
		}	
	      bateauValide = posBateau(&grille, x, y, taille[cptBateauPos], rotate);
	    }
	  }
	break;
	    
      default:					
	break;
      }	
    }


    //////////// gestion colorimetrie des boutons  ///////////////////////////
	
    if (cptBateauPos == 5 ){
      boutonGuerre.setFillColor(Color(0, 0, 0, 0));
    }
	
    if (bateauValide){
      boutonValide.setFillColor(Color(0,0,0,0));
    }else{
      boutonValide.setFillColor(Color(0,0,0,160));
    }	
		
    ///////////// gestion de l'affichage //////////////////
    window.clear(Color::White); 	
		
    window.draw(fondEcran_spr);
    window.draw(boutonGuerre);
    window.draw(boutonValide);
    i = j =0;
    while ( j < 10){
      while( i < 10){
	window.draw(grille._grille[i][j]._case_rect);
	i++;
      }
      i = 0;
      j++;
    }
      
    window.display();
        
  }
}
  

