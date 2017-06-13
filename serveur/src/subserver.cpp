#include	"network.hpp"

std::vector<myThreads*> mySubServers;

void		initSubServers(std::vector<myThreads*> *mySubServers, int port)
{
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
  return mySubServers.at(i)->def.port;
}

void		launchSubServer(std::vector<myThreads*> *mySubServers, int i)
{
  mySubServers->at(i)->isReady = false;
  mySubServers->at(i)->myThread->launch();
}

int		returnFirstSubReady(std::vector<myThreads *> mySubServers)
{
  for (int i = 0; i < 10; i++)
    {
      if (mySubServers.at(i)->isReady == true)
	return i;
    }
  return -1;
}
