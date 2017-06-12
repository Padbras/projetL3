#ifndef ALLEMAGNE_HPP
#define ALLEMAGNE_HPP

#include "Pays.hpp"
#include "Case.hpp"
#include "Grille.hpp"

class Allemagne : public Pays {
	public :
		Allemagne(){}
		Allemagne(int cooldown);
		virtual Grille pouvoir(Grille &g);
	 	
};


#endif
