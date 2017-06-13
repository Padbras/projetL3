#ifndef FRANCE_HPP
#define FRANCE_HPP

#include "Pays.hpp"
#include "Case.hpp"
#include "Grille.hpp"

class France : public Pays {
	public :
		France();
		void pouvoir(int x,int y,Grille &g);
	 	
};


#endif
