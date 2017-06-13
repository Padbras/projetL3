#include "Japon.hpp"
#include <iostream> 

using namespace std;

Japon::Japon()
{
	_cooldown=3;
}

void Japon::pouvoir(int x,int y,Grille &g){ //gerer au niveau de l'appel de la fonction si (nbParttouchées)%(cooldown)==0 
								// + boucle pour tirer 2 fois
	//g.setColorCase(x,y,128,128,128,128);
	if(g._grille[x][y]._type==boat){
		g.setTypeCase(x,y,touch);
		//g.setColorCase(x,y,255,0,0,128);
	}else if(g._grille[x][y]._type==mer){
		g.setTypeCase(x,y,miss);
	}		
}
