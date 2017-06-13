#ifndef ALLEMAGNE_HPP
#define ALLEMAGNE_HPP

#include "Pays.hpp"
#include "Case.hpp"
#include "Grille.hpp"

class Allemagne : public Pays {
	public :
		Allemagne();
		virtual void pouvoir(int x,int y,Grille &g);
	 	
};


#endif
