#include	"network.hpp"

int nextPort; 

void		createServer(bool role)
{
  sf::TcpListener listener;
  std::list<Joueur> joueurs;
  std::list<sf::TcpSocket *> clients;
  sf::SocketSelector selector;

  displayInfo("Server started");
  std::cout << "On port " << nextPort <<"With bool role " << role <<  std::endl;
  listener.listen(nextPort);
  selector.add(listener);

  serverLoop(&listener, &selector, clients, role );
}

int		main(int ac, char **av)
{ 
  if (ac != 2)
    {
      displayError("Only one argument, specify the port please.");
      displayInfo("usage : ./server.out [PORT]");
      exit(-1);
    }
  nextPort = atoi(av[1]); 
  sf::Thread fred(&createServer, true);
  fred.launch();
  return 0;
}
