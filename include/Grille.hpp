#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Case.hpp"


class Grille{
	public :
	Case _grille[10][10];
	Grille();
	void afficherGrille();
};

#endif


