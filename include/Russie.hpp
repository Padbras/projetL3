#ifndef RUSSIE_HPP
#define RUSSIE_HPP

#include "Pays.hpp"
#include "Case.hpp"
#include "Grille.hpp"

class Russie : public Pays {
	public :
		Russie();
		virtual void pouvoir(int x,int y,Grille &g);
	 	
};


#endif
