#include "gestionGrille.hpp"

int retGrDroitX(int x)
{
  return (533 + 40 * x);
}

int retGrDroitY(int y)
{
  return (200 + 40 * y);
}

int retGrGauchX(int x)
{
  return (66 + 40 * x);
}

int retGrGauchY(int y)
{
  return (200 + 40 * y);
}

// retour X et Y pour une grille centrale
int gdRetourX(int mouseX){
	return (mouseX- 300)/40;
}

int gdRetourY(int mouseY){
	return (mouseY- 300)/40;
}

// retour X et Y pour 2 grilles laterales
int ptRetourX(int mouseX){
	return (mouseX- 533)/40;
}

int ptRetourY(int mouseY){
	return (mouseY- 200)/40;
}

int pxX(int x)
{
  return (300 + 40 * x);
}

int pxY(int y)
{
  return (300 + 40 * y);
}

void		placeBateau(Grille *grille, int x, int y, int taille, int rotate)
{
  std::cout << "placebateau" << std::endl;
  if (grille->_grille[x][y]._type != mer)
    return ;
  grille->_grille[x][y]._case_rect.setPosition(pxX(x),pxY(y));
  grille->_grille[x][y]._case_rect.setFillColor(sf::Color(0, 255, 0, 128));	     
  grille->_grille[x][y]._type = boat;
  switch (rotate)
    {
    case 0 :
      // std::cout << "rotate 0 " << rotate << std::endl;
      for (int j = 1; j < taille; j++)
	for (int i = 1; i < taille; i++)
	  {
	    // if (grille->_grille[x][y - j]._type != mer)
	    //   return ;
	    // else
	    //   {
		grille->_grille[x][y - j]._case_rect.setPosition(pxX(x),pxY(y - j));
		grille->_grille[x][y - j]._case_rect.setFillColor(sf::Color(0, 255, 0, 128));
		grille->_grille[x][y - j]._type = boat;
		// }
	  }
      break;
    }      
    // case 1 :
    //   std::cout << "rotate 1 " << rotate << std::endl;
    //   for (int j = 1; j < taille; j++)
    // 	for (int i = 1; i < taille; i++)
    // 	  {
    // 	    if (grille->_grille[x + i][y]._type != mer)
    // 	      return ;
    // 	    else
    // 	      {
    // 		grille->_grille[x + i][y]._case_rect.setPosition(pxX(x + i),pxY(y));
    // 		grille->_grille[x + i][y]._case_rect.setFillColor(sf::Color(255, 0, 0, 128));
    // 	      }
    // 	  }
    //   break;
      
    // case 2 :
    //   std::cout << "rotate 2 " << rotate << std::endl;
    //   for (int j = 1; j < taille; j++)
    // 	for (int i = 1; i < taille; i++)
    // 	  {
    // 	    if (grille->_grille[x][y + j]._type != mer)
    // 	      return ;
    // 	    else
    // 	      {
    // 		grille->_grille[x][y + j]._case_rect.setPosition(pxX(x),pxY(y + j));
    // 		grille->_grille[x][y + j]._case_rect.setFillColor(sf::Color(255, 0, 0, 128));
    // 	      }
    // 	  }
    //   break;
      
    // case 3 :
    //   std::cout << "rotate 3 " << rotate << std::endl;
    //   for (int j = 1; j < taille; j++)
    // 	for (int i = 1; i < taille; i++)
    // 	  {
    // 	    if (grille->_grille[x - i][y]._type != mer)
    // 	      return ;
    // 	    else
    // 	      {
    // 		grille->_grille[x - i][y]._case_rect.setPosition(pxX(x - i),pxY(y));
    // 		grille->_grille[x - i][y]._case_rect.setFillColor(sf::Color(255, 0, 0, 128));
    // 	      }
    // 	  }
    //   break;
    // }     
}
