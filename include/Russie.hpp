#ifndef RUSSIE_HPP
#define RUSSIE_HPP

#include "Pays.hpp"
#include "Case.hpp"
#include "Grille.hpp"

class Russie : public Pays {
	public :
		Russie(){}
		Russie(int cooldown);
		virtual Grille pouvoir(int x,int y,Grille &g);
	 	
};


#endif
