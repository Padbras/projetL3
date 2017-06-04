#include	"client.hpp"

void		startClient(char *ip, int port)
{
  std::string	pseudo;
  sf::TcpSocket	socketToServer;
  
  pseudo = lancerFenetreAccueil();
  if (connectToServer(&socketToServer, ip, port) == true)
    {
      fenetrePosBateau();
    }
}

int		main(int ac, char **av)
{
  if (ac != 3)
    {
      displayError("Need two arguments, specify the ip and the port");
      displayInfo("Usage : ./client.out [IP] [PORT]");                                      
      return -1;  
    }
  startClient(av[1], atoi(av[2]));
  return 0;
}
