#ifndef JAPON_HPP
#define JAPON_HPP

#include "Pays.hpp"
#include "Case.hpp"
#include "Grille.hpp"

class Japon : public Pays {
	public :
		Japon();
		virtual void pouvoir(int x,int y,Grille &g);
	 	
};


#endif
