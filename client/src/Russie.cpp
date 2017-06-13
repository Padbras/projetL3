#include "Russie.hpp"
#include <iostream> 

using namespace std;

Russie::Russie()
{
	_cooldown=4;
}

void Russie::pouvoir(int x,int y,Grille &g){ //tir en croix avec x et y coordonnées centre récuperées par la souris
	/*---coloration des cases visées---*/
	
	/*g.setColorCase(x-1,y,128,128,128,128);
	g.setColorCase(x+1,y,128,128,128,128);
	g.setColorCase(x,y-1,128,128,128,128);
	g.setColorCase(x,y+1,128,128,128,128);*/
	
	
	//case gauche
	if(g._grille[x-1][y]._type==boat){
		g.setTypeCase(x-1,y,touch);
		//g.setColorCase(x-1,y,255,0,0,128);
	}else if(g._grille[x-1][y]._type==mer){
		g.setTypeCase(x-1,y,miss);
	}
	
	
	//case droite
	if(g._grille[x+1][y]._type==boat){
		g.setTypeCase(x+1,y,touch);
		//g.setColorCase(x+1,y,255,0,0,128);
	}else if(g._grille[x+1][y]._type==mer){
		g.setTypeCase(x+1,y,miss);
	}
	
	
	//case haut
	if(g._grille[x][y-1]._type==boat){
		g.setTypeCase(x,y-1,touch);
		//g.setColorCase(x,y-1,255,0,0,128);
	}else if(g._grille[x][y-1]._type==mer){
		g.setTypeCase(x,y-1,miss);
	}
	
	
	//case bas
	if(g._grille[x][y+1]._type==boat){
		g.setTypeCase(x,y+1,touch);
		//g.setColorCase(x,y+1,255,0,0,128);
	}else if(g._grille[x][y+1]._type==mer){
		g.setTypeCase(x,y+1,miss);
	}
	
	
}
