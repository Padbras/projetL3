#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Case.hpp"
#include "gestionGrille.hpp"


class Grille{
	public:
	Case _grille[10][10];
  
	Grille();
	void afficherGrille();
	
	void setPosCase( int, int, int, int);
	void setColorCase( int, int, int, int, int, int);
	typeCase getTypeCase( int, int);
	void setTypeCase( int, int, enum typeCase);
	sf::RectangleShape getRect(int , int);
	void convertGrilleDroit(Grille *);
	void convertGrilleGauche(Grille *);
};

#endif


