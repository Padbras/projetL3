#ifndef JAPON_HPP
#define JAPON_HPP

#include "Pays.hpp"
#include "Case.hpp"
#include "Grille.hpp"

class Japon : public Pays {
	public :
		Japon(){}
		Japon(int cooldown);
		virtual Grille pouvoir(Grille &g);
	 	
};


#endif
