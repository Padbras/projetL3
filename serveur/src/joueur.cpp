#include	"network.hpp"

void		displayListJoueur(std::list<Joueur> myList)
{
	/// \brief Affiche la liste des joueurs connectés au serveur
  for (std::list<Joueur>::iterator it = myList.begin();
       it != myList.end(); ++it)
    {
      Joueur myJoueur = *it;
      displayJoueur(myJoueur);
      std::cout << std::endl;
    }
}

void		displayJoueur(Joueur myJoueur)
{
	/// \brief Affiche les informations d'un joueur
  displayInfo("Player informations :");
  std::cout << "Pseudo : " << myJoueur.pseudo << std::endl;
  std::cout << "Ip : " << myJoueur.socket->getRemoteAddress().toString() << std::endl;
  std::cout << "Port : " << myJoueur.socket->getLocalPort() << std::endl;
}

Joueur		*createJoueur(std::string pseudo, sf::TcpSocket *socket)
{
	/// \brief Crée un joueur avec son socket et son pseudo associé puis le retourne
  Joueur	*myJoueur;

  myJoueur = new Joueur;
  myJoueur->socket = socket;
  myJoueur->pseudo = pseudo;
  return myJoueur;
}
