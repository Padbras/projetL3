#ifndef PAYS_HPP
#define PAYS_HPP

#include <string>
#include "Grille.hpp"

class Pays{
	public:
		int _cooldown;

	public:
		Pays();
		Pays(int cooldown);
		virtual typeCase pouvoir(int x,int y, Grille &){};
};

#endif
