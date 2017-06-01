
#include "cin_acceuil.hpp"

//affichage de l'image de fond "metal brossé"
void aff_img_fond(){
	sf::Texture t_fondAccueil;
	if (!t_fondAccueil.loadFromFile("../img/fond.png"))
		{
		}		
	sf::Sprite s_fondAccueil;
	s_fondAccueil.setTexture(t_fondAccueil);
	window.draw(s_fondAccueil);
}
