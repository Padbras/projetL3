#include "gestionBateau.hpp"
#include "gestionGrille.hpp"

using namespace std; 



bool		verifMer(Grille *grille, int x, int y){
				if(grille->getTypeCase(x,y) == mer)				
					return true;
				else		
					return false;
}

bool		verifPlaceNord(Grille *grille, int x, int y, int taille){
				if((y - taille) > -1){  
					if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y--))){
						cout << "if 1 " << taille << endl;
						y--;
						taille--;
						verifPlaceNord(grille, x, y, taille);
					else if ((taille == 2) && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y--))){
												cout << "if 2 " << taille << endl;
						return true;}
					else{ 
												cout << "return false" << taille << endl;
						return false;}
				}
}
	
bool		verifPlaceSud(Grille *grille, int x, int y, int taille){
				if((y + taille) < 10){
					if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y++)))
						return verifPlaceSud(grille, x, y++, taille--) ;
					else if ((taille == 2) && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y++)))
						return true;
					else 
						return false;
				}
}

bool		verifPlaceOuest(Grille *grille, int x, int y, int taille){
				if((x - taille) > -1){				
					if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x--,y)))
						return verifPlaceOuest(grille, x--, y, taille--) ;
					else if ((taille == 2) && (grille->getTypeCase(x,y) == grille->getTypeCase(x--,y)))
						return true;
					else 
						return false;
				}
}

bool		verifPlaceEst(Grille *grille, int x, int y, int taille){
				if((x + taille) < 10){				
					if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x++,y)))
						return verifPlaceEst(grille, x++, y, taille--) ;
					else if ((taille == 2) && (grille->getTypeCase(x,y) == grille->getTypeCase(x++,y)))
						return true;
					else 
						return false;
				}
}		

void		setBateau(Grille *grille, int x, int y){
				grille->setTypeCase(pxX(x),pxY(x),boat);
				grille->setColorCase( x, y, 0, 255, 0, 128);
				grille->setPosCase( x, y);		
}

void		posBateauNord(Grille *grille, int x, int y, int taille){
				if(verifPlaceNord(grille , x, y, taille)){
					while(taille > 0){
						setBateau( grille, x, y);
						taille--;
						y--;
					}
				}
				
}

void		posBateauSud(Grille *grille, int x, int y, int taille){
				if(verifPlaceSud(grille , x, y, taille)){
					while(taille > 0){
						setBateau( grille, x, y);
						taille--;
						y++;
					}					
				}				
}

void		posBateauOuest(Grille *grille, int x, int y, int taille){
				if(verifPlaceOuest(grille , x, y, taille)){
					while(taille > 0){
						setBateau( grille, x, y);
						taille--;
						x--;
					}					
				}				
}

void		posBateauEst(Grille *grille, int x, int y, int taille){
				if(verifPlaceEst(grille , x, y, taille)){
					while(taille > 0){
						setBateau( grille, x, y);
						taille--;
						x++;
					}					
				}				
}
