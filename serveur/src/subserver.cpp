#include	"network.hpp"

std::vector<myThreads*> mySubServers;

void		initSubServers(std::vector<myThreads*> *mySubServers, int port)
{
	/// \brief Permet de créer un sous-serveur 
  myThreads	*threads;

  for(int i = 0; i < 10; i++)
    {
      threads = new myThreads;
     
      threads->def.role = false;
      threads->isReady = true;
      threads->id = i;
      threads->def.port = port + i; 
      threads->myThread = new sf::Thread(&createServer, threads->def);
      mySubServers->push_back(threads);
    }
}

int		returnPortSubServer(std::vector<myThreads *> mySubServers, int i)
{
	/// \brief Retourne le port du sous-serveur passé en paramêtre
  return mySubServers.at(i)->def.port;
}

void		launchSubServer(std::vector<myThreads*> *mySubServers, int i)
{
	/// \brief Permet de lancer un sous-serveur
  mySubServers->at(i)->isReady = false;
  mySubServers->at(i)->myThread->launch();
}

void	stopSubServer(std::vector<myThreads *> *mySubServers, int port)
{
  for (int i = 0; i < 10; i++)
    {
      if (mySubServers->at(i)->def.port == port)
      {
		mySubServers->at(i)->myThread->terminate();
		mySubServers->at(i)->isReady = true;
	  }
    }
}

int		returnFirstSubReady(std::vector<myThreads *> mySubServers)
{
	/// \brief Permet de retourner le premier sous-serveur dont l'état est "Ready"
  for (int i = 0; i < 10; i++)
    {
      if (mySubServers.at(i)->isReady == true)
	return i;
    }
  return -1;
}
