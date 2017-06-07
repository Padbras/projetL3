#include "gestionBateau.hpp"



bool		verifMer(Grille *grille, int x, int y, int taille){
		//		if(grille->_grille[x][y];

}


bool		verifTypeNord(Grille *grille, int x, int y,int taille){
				if (taille > 2 && (grille->_grille[x][y]._type == grille->_grille[x][y--]._type))
					return verifTypeNord(grille, x, y--, taille--) ;
				else if ((taille == 2) && (grille->_grille[x][y]._type == grille->_grille[x][y--]._type))
					return true;
				else 
					return false;
			}
	
bool		verifTypeSud(Grille *grille, int x, int y,int taille){
				if (taille > 2 && (grille->_grille[x][y]._type == grille->_grille[x][y++]._type))
					return verifTypeNord(grille, x, y++, taille--) ;
				else if ((taille == 2) && (grille->_grille[x][y]._type == grille->_grille[x][y++]._type))
					return true;
				else 
					return false;
			}

bool		verifTypeOuest(Grille *grille, int x, int y,int taille){
				if (taille > 2 && (grille->_grille[x][y]._type == grille->_grille[x--][y]._type))
					return verifTypeNord(grille, x--, y, taille--) ;
				else if ((taille == 2) && (grille->_grille[x][y]._type == grille->_grille[x--][y]._type))
					return true;
				else 
					return false;
			}

bool		verifTypeEst(Grille *grille, int x, int y,int taille){
				if (taille > 2 && (grille->_grille[x][y]._type == grille->_grille[x++][y]._type))
					return verifTypeNord(grille, x++, y, taille--) ;
				else if ((taille == 2) && (grille->_grille[x][y]._type == grille->_grille[x++][y]._type))
					return true;
				else 
					return false;
			}			
