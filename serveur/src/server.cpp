#include	"network.hpp"
#include	"client.hpp"
#include	"Grille.hpp"
  
Grille		g_GrilleP2;
Grille       	g_GrilleP1;

bool		sendGrille(sf::TcpSocket *mySocket, Grille myGrille)
{
  sf::Packet	myPacket;
  int		x, y, type;

  for (int j = 0; j < 10; j++)
    for (int i = 0; i < 10; i++)
      {
	myPacket.clear();
	x = myGrille._grille[i][j]._x;
	y = myGrille._grille[i][j]._y;
	if (myGrille._grille[i][j]._type == mer)
	  type = 0;
	else
	  type = 1;
	myPacket << x << y << type;
	if (sendPacket(&myPacket, mySocket) == false)
	  return false;
      }
  return true;
}

Grille		receiveGrille(sf::TcpSocket *mySocket)
{
  sf::Packet	myPacket;
  Grille	myGrille;
  int		type;
  
  for (int j = 0; j < 10; j++)
    for (int i = 0; i < 10; i++)
      {
	myPacket.clear();
	myPacket = receivePacket(mySocket);
	myPacket >> myGrille._grille[i][j]._x
		 >> myGrille._grille[i][j]._y
		 >> type;
	if (type == 0)
	  myGrille._grille[i][j]._type = mer;
	else
	  myGrille._grille[i][j]._type = boat;
      }
  myGrille.afficherGrille();
  return myGrille;
}

bool		transmitFirstInfo(Joueur joueurUn, Joueur joueurDeux)
{
  sf::Packet	myPacket1;
  sf::Packet	myPacket2;
  // displayJoueur(joueurUn);
  // displayJoueur(joueurDeux);
  
  g_GrilleP1 = receiveGrille(joueurUn.socket);
  g_GrilleP2 = receiveGrille(joueurDeux.socket);
  // displayInfo("Grille joueur 1");
  // g_GrilleP1.afficherGrille();
  // displayInfo("Grille joueur 2");
  // g_GrilleP2.afficherGrille();
  if (sendGrille(joueurDeux.socket, g_GrilleP1) == false)
    return false;
  if (sendGrille(joueurUn.socket, g_GrilleP2) == false)
    return false;
  return true;  
}

void		gameLoop(std::list<Joueur> joueurs, sf::TcpListener *listener,
			 sf::SocketSelector *selector)
{
  bool		running = true;
  sf::Packet	myPacket;
  Joueur	joueurUn = joueurs.front();
  Joueur	joueurDeux = joueurs.back();

  myPacket << true;
  if (sendPacket(&myPacket, joueurUn.socket) == false)
    {
      displayError("Failed to send packet (bool to j1)");
    }
  if (sendPacket(&myPacket, joueurDeux.socket) == false)
    {

      displayError("Failed to send packet (bool to j2)");
    }
  if (transmitFirstInfo(joueurUn, joueurDeux) == false)
    {
      displayError("Failed to transmit");
    }
  displayInfo("First Info transmit");
  
}

std::list<Joueur> serverLoop(sf::TcpListener *listener, sf::SocketSelector *selector,
			     std::list<sf::TcpSocket *> clients)
{
  bool		running = true;
  std::list<Joueur> joueurs;
  
  while (running)
    {
      if (selector->wait())
	{
	  if (selector->isReady(*listener))
	    {
	      // We found a connection
	      sf::TcpSocket *client = new sf::TcpSocket;
	      if (listener->accept(*client) == sf::Socket::Done)
		{
		  clients.push_back(client);
		  selector->add(*client);
		  displayInfo("Client connected");
		  displayInfo("Client add to the selector"); 
		}
	      else
		delete client;
	    }	  
	  else
	    {
	      for (std::list<sf::TcpSocket *>::iterator it = clients.begin();
		   it != clients.end(); ++it)
		{
		  sf::TcpSocket &client = **it;
		  if (selector->isReady(client))
		    {
		      sf::Packet packet;
		      if (client.receive(packet) == sf::Socket::Done)
			{
			  std::string pseudo;
			  packet >> pseudo;
			  Joueur *newJoueur = createJoueur(pseudo, &client);
			  joueurs.push_back(*newJoueur);
			  displayInfo("Client add to list");
			  displayInfo("Pseudo received from client");
			  std::cout << pseudo << std::endl;
			}
		    }   
		}
	    } 
	}
      if (joueurs.size() == 2)
	{
	  running = false;
	}
    }
  gameLoop(joueurs, listener, selector); 
  return joueurs;
}

void		createServer(int port)
{
  sf::TcpListener listener;
  std::list<Joueur> joueurs;
  std::list<sf::TcpSocket *> clients;
  sf::SocketSelector selector;

  displayInfo("Server started");
  listener.listen(port);
  selector.add(listener);

  joueurs = serverLoop(&listener, &selector, clients);
  // displayListJoueur(joueurs);
}


int		main(int ac, char **av)
{
  if (ac != 2)
    {
      displayError("Only one argument, specify the port please.");
      displayInfo("usage : ./server.out [PORT]");
      exit(-1);
    }
  createServer(atoi(av[1]));
  return 0;
}

  // sf::Packet	toTransmit;
  // sf::Packet	grilleJ1;
  // Joueur	joueurUn = joueurs.front();
  // Joueur	joueurDeux = joueurs.back();
  // bool		running = true;
  // std::string	str;
  
  // while (running)
  //   {
  //     // if (joueurUn.socket->receive == sf::Socket::Done)
  //     // 	{
  //     toTransmit.clear();
  //     toTransmit = receivePacket(joueurUn.socket);
  //     toTransmit >> str;
  //     std::cout << str << std::endl;
  //     if (sendPacket(&toTransmit, joueurDeux.socket) == false)
  // 	displayError("failed to send packet");
  //     else
  // 	displayInfo("packet sent");
  //     // 	}
  //     // if (joueurDeux.socket == sf::Socket::Done)
  //     // 	{
  //     toTransmit.clear();
  //     toTransmit = receivePacket(joueurDeux.socket);
  //     toTransmit >> str;
  //     std::cout << str << std::endl;
  //     if (sendPacket(&toTransmit, joueurUn.socket) == false)
  // 	displayError("failed to send packet");
  //     else
  // 	displayInfo("packet sent");

//bool		sendPacket(sf::Packet *, sf::TcpSocket *);

	
		/*grilleJ1 = receivePacket(joueurUn.socket);
		grilleJ1 >> grilleP1;
		grilleP1.afficherGrille();*/
		
	


      // }
