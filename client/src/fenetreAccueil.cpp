#include	"fenetreAccueil.hpp"

using namespace sf;
using namespace std;


string		lancerFenetreAccueil()
{

  ////////////////// creation et init de la fenetre //////////////////

	RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : La bataille",Style::Default);
	window.setPosition(Vector2i(10, 10));


  ////////////////// creation et init des variables //////////////////

  string pseudoEntr_s = "";
  Event event;


  ////////////////// chargement des fonts et textures /////////////////

  Texture fondEcran_tex;
  if (!fondEcran_tex.loadFromFile("../client/img/accueil.png")){
  }
  Font main_font;
  main_font.loadFromFile("../client/fonts/main_font.ttf");
	

  //////////// creation des sprites et textures //////////////////////
			
  Sprite fondEcran_spr(fondEcran_tex);
  RectangleShape boutonValide(Vector2f(400,72));
  boutonValide.setPosition(300,628);
  boutonValide.setFillColor(Color(0,0,0,160));
	
	
  //////////// affichage de la fenetre ///////////////////////////////

  while (window.isOpen()){


  //////////// gestion de la boule d'evenements///////////////////////

    while (window.pollEvent(event)){
			
      switch (event.type){
				
      case Event::Closed :
	window.close();
	break;
				
      case Event::TextEntered :
	pseudoEntr_s.push_back((char)event.text.unicode);
						
	break;

      case Event::KeyPressed : 
	if (pseudoEntr_s.size() > 0 && event.key.code == Keyboard::BackSpace )
	  pseudoEntr_s.erase();
	if (pseudoEntr_s.size() > 0 && event.key.code == Keyboard::Return ){
	  window.close();
	  return pseudoEntr_s;}
	  
	break;
				
      case Event::MouseButtonPressed :
	if(	event.mouseButton.x < 700 && event.mouseButton.x >300 && 
		event.mouseButton.y < 700 && event.mouseButton.y > 628 &&
		pseudoEntr_s.size() > 0){	
	  window.close();
	  return pseudoEntr_s;}
	break;
			
      default:
	break;
      }	
    }


  //////////// creation des textes ////////////////////////////

    Text pseudoEntr_txt;
    pseudoEntr_txt.setFont(main_font);
    pseudoEntr_txt.setCharacterSize(80);	
    pseudoEntr_txt.setPosition(370,340);
    pseudoEntr_txt.setString(pseudoEntr_s);
	
  /////////////////gestion colorimetrie du bouton ////////////////
	
	if(pseudoEntr_s.size() > 0)
	  boutonValide.setFillColor(Color(0,0,0,0));


  ///////////// gestion de l'affichage ////////////////////////////	
   
    window.clear(Color::White); 	
	
    window.draw(fondEcran_spr);
    window.draw(pseudoEntr_txt);
	window.draw(boutonValide);
   
    window.display();
        
  }
}


