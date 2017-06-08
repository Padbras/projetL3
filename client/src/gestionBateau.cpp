#include "gestionBateau.hpp"
#include "gestionGrille.hpp"


using namespace std; 

///////////// fonctions de verifications //////////////////////////////


// verifie que la case clickée soit bien de la mer
bool		verifMer(Grille *grille, int x, int y){
				if(grille->getTypeCase(x,y) == mer)				
					return true;
				else		
					return false;
}

// verifie l'uniformité des cases (toutes du meme type sur une taille donnée
bool		verifPlaceNord(Grille *grille, int x, int y, int taille){
					if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y-1)))
						verifPlaceNord(grille, x, y-1, taille-1);
					else if ((taille == 2) && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y-1)))
						return true;
					else
						return false;
}


bool		verifPlaceSud(Grille *grille, int x, int y, int taille){
					if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y+1)))
						verifPlaceSud(grille, x, y+1, taille-1) ;
					else if ((taille == 2) && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y+1)))
						return true;
					else 
						return false;
}

bool		verifPlaceOuest(Grille *grille, int x, int y, int taille){			
					if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x-1,y)))
						verifPlaceOuest(grille, x-1, y, taille-1) ;
					else if ((taille == 2) && (grille->getTypeCase(x,y) == grille->getTypeCase(x-1,y)))
						return true;
					else 
						return false;
}

bool		verifPlaceEst(Grille *grille, int x, int y, int taille){		
					if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x+1,y)))
						verifPlaceEst(grille, x+1, y, taille-1) ;
					else if ((taille == 2) && (grille->getTypeCase(x,y) == grille->getTypeCase(x+1,y)))
						return true;
					else 
						return false;;
}		


////////////////////// fonction de positionnement des bateaux /////////////

// rentre les infos dans la grille
void		setBateau(Grille *grille, int x, int y){
				grille->setTypeCase( x, y, boat);
				grille->setColorCase( x, y, 0, 255, 0, 128);
				grille->setPosCase( x, y, pxX(x), pxY(y));	
}


// realisation des tests en fonction de l'orientation et rentre les infos
void		posBateauNord(Grille *grille, int x, int y, int taille){
				if(verifMer( grille , x, y) && (y-taille) > -2 && verifPlaceNord( grille , x, y, taille)){
					while(taille > 0){
						setBateau( grille, x, y);
						taille--;
						y--;
					}
				}
				
}

void		posBateauSud(Grille *grille, int x, int y, int taille){
				if(verifMer(grille , x, y) && (y+taille) < 11 && verifPlaceSud( grille , x, y, taille)){
					while(taille > 0){
						setBateau( grille, x, y);
						taille--;
						y++;
					}					
				}				
}

void		posBateauOuest(Grille *grille, int x, int y, int taille){
				if(verifMer(grille , x, y) && (x-taille) < -2 && verifPlaceOuest( grille , x, y, taille)){
					while(taille > 0){
						setBateau( grille, x, y);
						taille--;
						x--;
					}					
				}				
}

void		posBateauEst(Grille *grille, int x, int y, int taille){
				if(verifMer(grille , x, y) && (x+taille) < 11 && verifPlaceEst( grille , x, y, taille)){
					while(taille > 0){
						setBateau( grille, x, y);
						taille--;
						x++;
					}					
				}				
}


void		posBateau(Grille *grille, int x, int y, int taille, int rotate){
				switch (rotate){
					case 0 :
						posBateauNord( grille, x, y, taille);
						break;
						
					case 1 :
						posBateauEst( grille, x, y, taille);
						break;

					case 2 :
						posBateauSud( grille, x, y, taille);
						break;
						
					case 3 :
						posBateauOuest( grille, x, y, taille);
						break;				
				}
}
