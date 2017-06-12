#include	"network.hpp"

int		nextPort;
  
void		createServer(defServer def)
{
  sf::TcpListener listener;
  std::list<Joueur> joueurs;
  std::list<sf::TcpSocket *> clients;
  sf::SocketSelector selector;

  displayInfo("Server started");
  std::cout << "On port " << def.port <<"With bool role " << def.role <<  std::endl;
  listener.listen(def.port);
  selector.add(listener);

  serverLoop(&listener, &selector, clients, def);
}

int		main(int ac, char **av)
{
  defServer	def;
  if (ac != 2)
    {
      displayError("Only one argument, specify the port please.");
      displayInfo("usage : ./server.out [PORT]");
      exit(-1);
    }
  def.role = true;
  def.port = atoi(av[1]);
  initSubServers(&mySubServers, def.port + 1);
  createServer(def);
  return 0;
}
