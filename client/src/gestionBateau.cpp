#include "gestionBateau.hpp"
#include "gestionGrille.hpp"


using namespace std; 

///////////// fonctions de verifications //////////////////////////////


// verifie que la case clickée soit bien de la mer
bool		verifMer(Grille *grille, int x, int y){
	/// \brief Permet de vérifier si le type de la case est de la mer 
				if(grille->getTypeCase(x,y) == mer)				
					return true;
				else		
					return false;
}

bool		verifBoat(Grille *grille, int x, int y){
	/// \brief Permet de vérifier si le type de la case est un bateau
				if(grille->getTypeCase(x,y) == boat)				
					return true;
				else		
					return false;
}

// verifie l'uniformité des cases (toutes du meme type sur une taille donnée

bool 		verifPlace(Grille *grille, int x, int y, int taille, int rotate){
	/// \brief Permet de vérifier si la place pour le bateau est disponible
				switch (rotate){
					case 0:
						if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y-1)))
							return verifPlace(grille, x, y-1, taille-1, rotate);
						else if (taille == 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y-1)))
							return true;
						else
							return false;
					break;
				
					case 1:
						if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x+1,y)))
							return verifPlace(grille, x+1, y, taille-1, rotate) ;
						else if (taille == 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x+1,y)))
							return true;
						else 
							return false;					
					break;
					
					case 2:
						if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y+1)))
							return verifPlace(grille, x, y+1, taille-1, rotate) ;
						else if (taille == 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x,y+1)))
							return true;
						else 
							return false;			
					break;
					
					case 3:
						if (taille > 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x-1,y)))
							return verifPlace(grille, x-1, y, taille-1, rotate) ;
						else if (taille == 2 && (grille->getTypeCase(x,y) == grille->getTypeCase(x-1,y)))
							return true;
						else 
							return false;					
					break;
				}
				return false;
}

////////////////////// fonction de set de cases /////////////

void		setBateau(Grille *grille, int x, int y){
				grille->setTypeCase( x, y, boat);
				grille->setColorCase( x, y, 0, 255, 0, 128);
				grille->setPosCase( x, y, pxX(x), pxY(y));	
}

void 		setMer(Grille *grille, int x, int y){
				grille->setTypeCase( x, y, mer);
				grille->setColorCase( x, y, 0, 0, 0, 0);
				grille->setPosCase( x, y, pxX(x), pxY(y));	
}

void 		setErreur(Grille *grille, int x, int y){
				grille->setTypeCase( x, y, mer);
				grille->setColorCase( x, y, 255, 0, 0, 128);
				grille->setPosCase( x, y, pxX(x), pxY(y));	
}

/////////// positionne le bateau dans n'importe quel sens /////////////////

bool		posBateau(Grille *grille, int x, int y, int taille, int rotate){
				switch (rotate){
					case 0 :
						if(verifMer( grille , x, y) && (y-taille) > -2 && verifPlace( grille, x, y, taille, rotate)){
							while(taille > 0){
							setBateau( grille, x, y);
							taille--;
							y--;
							}
						} else {
							setErreur(grille, x, y);
							return false;
						}
					break;
						
					case 1 :
						if(verifMer(grille , x, y) && (x+taille) < 11 && verifPlace( grille, x, y, taille, rotate)){
							while(taille > 0){
							setBateau( grille, x, y);
							taille--;
							x++;
							}					
						} else {
							setErreur(grille, x, y);
							return false;
						}		
					break;

					case 2 :
						if(verifMer(grille , x, y) && (y+taille) < 11 && verifPlace( grille, x, y, taille, rotate)){
							while(taille > 0){
							setBateau( grille, x, y);
							taille--;
							y++;
							}					
						} else {
							setErreur(grille, x, y);
							return false;
						}		
					break;
						
					case 3 :
						if(verifMer(grille , x, y) && (x-taille) > -2 && verifPlace( grille, x, y, taille, rotate)){
							while(taille > 0){
							setBateau( grille, x, y);
							taille--;
							x--;
							}					
						} else {
							setErreur( grille, x, y);
							return false;
						}		
					break;				
				}
				return true;
}

////////////////fonction de suppression de bateau /////////////////////

void		eraseBateau(Grille *grille, int x, int y, int taille, int rotate){
				switch (rotate){
					case 0 :
						while(taille > 0){
							setMer( grille, x, y);
							taille--;
							y--;
						}	
					break;
						
					case 1 :
						while(taille > 0){
							setMer( grille, x, y);
							taille--;
							x++;
						}	
					break;

					case 2 :
						while(taille > 0){
						setMer( grille, x, y);
						taille--;
						y++;
						}		
					break;
						
					case 3 :
						while(taille > 0){
							setMer( grille, x, y);
							taille--;
							x--;
						}		
					break;				
				}
}
