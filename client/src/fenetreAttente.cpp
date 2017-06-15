#include "fenetreAttente.hpp"

using namespace sf;
using namespace std;

void fenetreAttente(int code){
  ////////////////// creation et init de la fenetre //////////////////

  RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : En recherche de ton adversaire !! ",Style::Titlebar);
  window.setPosition(Vector2i(10, 10));

  std::cout << "fenetreattente" << std::endl;

  ////////////////// chargement des fonts et textures /////////////////

  Texture fondEcran_tex;
  if(code == 1){
    if (!fondEcran_tex.loadFromFile("../client/img/recherche.png"))
      {
      }
  }
  else
    {
      if (!fondEcran_tex.loadFromFile("../client/img/attente.png"))
	{
	}
    }
	
	
  //////////// creation des textes, sprites et textures //////////////
	
  Sprite fondEcran_spr(fondEcran_tex);
	
	
  //////////// affichage de la fenetre ///////////////////////////////

  while (window.isOpen()){
		
		
    ///////////// gestion de l'affichage //////////////////
	
    window.clear(Color::White); 	
    window.draw(fondEcran_spr);	
    window.display();     
  }
}
