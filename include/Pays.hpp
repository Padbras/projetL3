#ifndef PAYS_HPP
#define PAYS_HPP

#include <string>
#include "Grille.hpp"

class Pays{
	private:
		int cooldown;
		int id;	

	public:
		Pays();
  //	 	void choixPouvoir(int p,int x,int y,Grille &g);
  //	virtual void pouvoir(int x,int y,Grille &g);
		void setId(int);
		int getId();
};

#endif
