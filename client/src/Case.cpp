#include "Case.hpp"

////////////////////// Constructeurs /////////////////////////////////// 

Case::Case(int px, int py, typeCase t, sf::RectangleShape rect) :
	_x(px),_y(py),_type(t),_case_rect(rect)
{
		/// \brief Constructeur par copie, prends en parametres les coordonnées,
		/// le type de la case et une forme rectangulaire (cf #sf::RectangleShape)
		_case_rect.setPosition(300,300);
		_case_rect.setFillColor(sf::Color(0, 255, 0, 0));
		
}

Case::Case(int px, int py, typeCase t) :
	_x(px),_y(py),_type(t)
{
	/// \brief Constructeur par copie, prends en parametres les coordonnées,
	/// le type de la case
}

Case::Case(){
	/// \brief Constructeur par defaut
}

