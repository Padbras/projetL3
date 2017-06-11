#ifndef PIRATES_HPP
#define PIRATES_HPP

#include "Pays.hpp"
#include "Case.hpp"
#include "Grille.hpp"

class Pirates : public Pays {
	public :
		Pirates(){}
		Pirates(int cooldown);
		virtual typeCase pouvoir(int x,int y,Grille &g);
	 	
};


#endif
