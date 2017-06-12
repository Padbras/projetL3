#ifndef FRANCE_HPP
#define FRANCE_HPP

#include "Pays.hpp"
#include "Case.hpp"
#include "Grille.hpp"

class France : public Pays {
	public :
		France(){}
		France(int cooldown);
	 virtual typeCase pouvoir(int x,int y,Grille &g) override;
	 	
};


#endif
