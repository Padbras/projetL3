#include "pouvoir.hpp"

void pouvoirFrance(int x, int y, Grille *g)
{
	std::cout << "pvr france" << std::endl;
	if (g->getTypeCase(x, y) == mer)
		g->setColorCase(x, y, 255,0,0,160);
	else if (g->getTypeCase(x, y) == boat)
		g->setColorCase(x, y, 0, 255, 0, 160);
}

void pouvoirRussie(int x, int y, Grille *g)
{
		std::cout << "pvr russe" << std::endl;

	//case gauche
	if(g->getTypeCase(x - 1, y) == boat && x - 1 >= 0)
	{
		g->setTypeCase(x-1,y,touch);
		g->setColorCase(x-1,y,0,255,0,128);
	}
	else if(g->getTypeCase(x - 1, y) == mer && x - 1 >= 0)
	{
		g->setTypeCase(x - 1, y, miss);
		g->setColorCase(x-1,y,255,0,0,128);
	}
	
	
	//case droite
	if(g->getTypeCase(x + 1, y) == boat && x + 1 <= 10)
	{
		g->setTypeCase(x + 1, y, touch);
		g->setColorCase(x+1,y,0,255,0,128);
	}
	else if(g->getTypeCase(x + 1, y) == mer && x + 1 <= 10)
	{
		g->setTypeCase(x + 1, y, miss);
		g->setColorCase(x+1,y,255,0,0,128);
	}
	
	
	//case haut
	if(g->getTypeCase(x, y - 1) == boat && y - 1 >= 0)
	{
		g->setTypeCase(x, y - 1, touch);
		g->setColorCase(x,y-1,0,255,0,128);
	}
	else if(g->getTypeCase(x, y - 1) == mer && y - 1 >= 0)
	{
		g->setTypeCase(x, y - 1, miss);
		g->setColorCase(x,y-1,255,0,0,128);
	}
	
	
	//case bas
	if(g->getTypeCase(x, y + 1) == boat && y + 1 <= 10)
	{
		g->setTypeCase(x, y + 1, touch);
		g->setColorCase(x, y + 1, 0, 255, 0, 128);
	}
	else if(g->getTypeCase(x, y + 1) == mer && y + 1 <= 10)
	{
		g->setTypeCase(x, y + 1, miss);
		g->setColorCase(x, y + 1, 255, 0, 0, 128);
	}
	
}

void pouvoirAllemagne(int x, int y, Grille *g)
{
		//g.setColorCase(x,y,128,128,128,128);
	if(g->getTypeCase(x, y)==boat){
		g->setTypeCase(x,y,touch);
		//g.setColorCase(x,y,255,0,0,128);
	}else if(g->getTypeCase(x, y)==mer){
		g->setTypeCase(x,y,miss);
	}		
}


void pouvoirJapon(int x, int y, Grille *g)
{
	
}
void pouvoirPirate(int x, int y, Grille *g)
{
	
}
