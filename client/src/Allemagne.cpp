#include "Allemagne.hpp"
#include <iostream> 

using namespace std;

Allemagne::Allemagne()
{
	_cooldown=7;
}


void Allemagne::pouvoir(int x,int y,Grille &g){ //tire 5fois (via boucle) tous les 7 tours
	
	//g.setColorCase(x,y,128,128,128,128);
	if(g._grille[x][y]._type==boat){
		g.setTypeCase(x,y,touch);
		//g.setColorCase(x,y,255,0,0,128);
	}else if(g._grille[x][y]._type==mer){
		g.setTypeCase(x,y,miss);
	}		
}
