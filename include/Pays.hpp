#ifndef PAYS_HPP
#define PAYS_HPP

#include <string>
#include "Grille.hpp"

class Pays{
	public:
		int _cooldown;

	public:
		Pays(){};
		virtual void pouvoir(int x,int y,Grille &g){};
};

#endif
