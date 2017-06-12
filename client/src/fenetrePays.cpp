#include	"fenetrePays.hpp"

using namespace std;


int		fenetrePays()
{

  ////////////////// creation et init de la fenetre //////////////////

	sf::RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : La bataille",sf::Style::Default);
	window.setPosition(sf::Vector2i(10, 10));


  ////////////////// creation et init des variables //////////////////

  sf::Event event;
  int choix = 0;


  ////////////////// chargement des fonts et textures /////////////////

  sf::Texture fondEcran_tex;
  if (!fondEcran_tex.loadFromFile("../client/img/choixpays.png"))
  {
  }
  
  sf::Font main_font;
  main_font.loadFromFile("../client/fonts/main_font.ttf");

  //////////// creation des sprites et textures //////////////////////
			
  sf::Sprite fondEcran_spr(fondEcran_tex);
  
  sf::RectangleShape boutonValide(sf::Vector2f(400,78));
  boutonValide.setPosition(300,711);
  boutonValide.setFillColor(sf::Color(0,0,0,160));
  
  sf::RectangleShape boutonFrance(sf::Vector2f(400,78));
  boutonFrance.setPosition(50,161);;

  sf::RectangleShape boutonAllemagne(sf::Vector2f(400,78));
  boutonAllemagne.setPosition(50,261);

  sf::RectangleShape boutonRussie(sf::Vector2f(400,78));
  boutonRussie.setPosition(50,361);
  
  sf::RectangleShape boutonJapon(sf::Vector2f(400,78));
  boutonJapon.setPosition(50,461);
  
  sf::RectangleShape boutonPirates(sf::Vector2f(400,78));
  boutonPirates.setPosition(50,561);
	
	
  //////////// affichage de la fenetre ///////////////////////////////

  while (window.isOpen()){


  //////////// gestion de la boule d'evenements///////////////////////

    while (window.pollEvent(event)){
			
      switch (event.type){
				
      case sf::Event::Closed :
	window.close();
	break;
				
      case sf::Event::MouseButtonPressed :
	//bouton valide
	if(	event.mouseButton.x < 700 && event.mouseButton.x > 300 && 
		event.mouseButton.y < 789 && event.mouseButton.y > 711 &&
		choix != 0)
	{
	  window.close();
	  return choix;
	}
	
	//bouton france
	else if(event.mouseButton.x < 450 && event.mouseButton.x >50 && 
			event.mouseButton.y < 239 && event.mouseButton.y > 161)
		choix = 1;
	
	//bouton allemagne	
	else if(event.mouseButton.x < 450 && event.mouseButton.x >50 && 
			event.mouseButton.y < 339 && event.mouseButton.y > 261)
		choix = 2;
	
	//bouton Russie
	else if(event.mouseButton.x < 450 && event.mouseButton.x >50 && 
			event.mouseButton.y < 439 && event.mouseButton.y > 361)
		choix = 3;
	
	//bouton Japon
	else if(event.mouseButton.x < 450 && event.mouseButton.x >50 && 
			event.mouseButton.y < 539 && event.mouseButton.y > 461)
		choix = 4;
	
	//bouton Pirates	
	else if(event.mouseButton.x < 450 && event.mouseButton.x >50 && 
			event.mouseButton.y < 639 && event.mouseButton.y > 561)
		choix = 5;				
			
	break;
			
      default:
	break;
      }	
    }


  //////////// creation des textes ////////////////////////////

	// texte de la france
    sf::Text france_txt;
    france_txt.setFont(main_font);
    france_txt.setCharacterSize(50);	
    france_txt.setPosition(510,171);
    france_txt.setString("France");

	// texte de l'Allemagne
    sf::Text allemagne_txt;
    allemagne_txt.setFont(main_font);
    allemagne_txt.setCharacterSize(50);	
    allemagne_txt.setPosition(510,171);
    allemagne_txt.setString("Allemagne");
    
	// texte de la Russie
    sf::Text russie_txt;
    russie_txt.setFont(main_font);
    russie_txt.setCharacterSize(50);	
    russie_txt.setPosition(510,171);
    russie_txt.setString("Russie");
    
	// texte du Japon
    sf::Text japon_txt;
    japon_txt.setFont(main_font);
    japon_txt.setCharacterSize(50);	
    japon_txt.setPosition(510,171);
    japon_txt.setString("Japon");
    
	// texte des Pirates
    sf::Text pirates_txt;
    pirates_txt.setFont(main_font);
    pirates_txt.setCharacterSize(50);	
    pirates_txt.setPosition(510,171);
    pirates_txt.setString("France");
    
    
  /////////////////gestion colorimetrie des boutons ////////////////
	
	//on grise tout les boutons de pays
	boutonFrance.setFillColor(sf::Color(0,0,0,160));
	boutonAllemagne.setFillColor(sf::Color(0,0,0,160));
	boutonRussie.setFillColor(sf::Color(0,0,0,160));
	boutonJapon.setFillColor(sf::Color(0,0,0,160));
	boutonPirates.setFillColor(sf::Color(0,0,0,160));
	
	// on degrise la validation si on a fait son choix
	if(choix > 0)
	  boutonValide.setFillColor(sf::Color(0,0,0,0));
	
	//on degrise le pays selectionné  
	switch(choix){
		
		case 1 : 
			boutonFrance.setFillColor(sf::Color(0,0,0,0));
		break;

		case 2 : 
			boutonAllemagne.setFillColor(sf::Color(0,0,0,0));
		break;

		case 3 : 
			boutonRussie.setFillColor(sf::Color(0,0,0,0));
		break;
		
		case 4 : 
			boutonJapon.setFillColor(sf::Color(0,0,0,0));
		break;
		
		case 5 : 
			boutonPirates.setFillColor(sf::Color(0,0,0,0));
		break;		
		
	}


  ///////////// gestion de l'affichage ////////////////////////////	
   
    window.clear(sf::Color::White); 	
	
    window.draw(fondEcran_spr);
	window.draw(boutonValide);
	window.draw(boutonFrance);
	window.draw(boutonAllemagne);
	window.draw(boutonRussie);
	window.draw(boutonJapon);
	window.draw(boutonPirates);
	switch(choix){ // affichage du texte en fonction du choix
		
		case 1 : 
			window.draw(france_txt);
		break;

		case 2 : 
			window.draw(allemagne_txt);
		break;

		case 3 : 
			window.draw(russie_txt);
		break;
		
		case 4 : 
			window.draw(japon_txt);
		break;
		
		case 5 : 
			window.draw(pirates_txt);
		break;		
		
	}
   
    window.display();
      
  }
  return -1;
}



