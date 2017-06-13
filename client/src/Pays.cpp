#include "Pays.hpp"
#include "France.hpp"
#include "Allemagne.hpp"
#include "Russie.hpp"
#include "Japon.hpp"
#include "Pirates.hpp"


void Pays::choixPouvoir(int p,int x,int y,Grille &g){
	switch(p){
		case 1:
			France::pouvoir(x,y,g);
		break;
		
		case 2:
			Allemagne::pouvoir(x,y,g);
		break;
		
		case 3:
			Russie::pouvoir(x,y,g);
		break;
		
		case 4:
			Japon::pouvoir(x,y,g);
		break;
		
		case 5:
			Pirates::pouvoir(x,y,g);
		break;
	}
}
