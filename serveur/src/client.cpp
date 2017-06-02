#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <thread>
#include <SFML/Network.hpp>

//using namespace std; 

int main()
{

    std::cout << "begin client" << std::endl;

    // connect to server
    sf::TcpSocket socketToServer;
    if (socketToServer.connect("127.0.0.1", 8888) != sf::Socket::Done)
      exit(-1);
    // envoi pseudo au server
    
    std::string pseudo;
    std::cout << "Pseudo ? " << std::endl;
    std::cin >> pseudo;
    // pseudo << "Engelbarte";
    sf::Packet monBeauPseudo;
    monBeauPseudo << pseudo;
        if (socketToServer.send(monBeauPseudo) != sf::Socket::Done)
      exit(-1); // Erreur à l'envoi
    std::cout << "pseudo envoye" << std::endl; 
    
    // connexion au deuxieme server
    // int port;
    sf::Packet pseudoAutre;
    std::string pseudo_autre;
    if (socketToServer.receive(pseudoAutre) != sf::Socket::Done)
      {
    	std::cout << "non recu" << std::endl;
    	exit(-1);
      }
    pseudoAutre >> pseudo_autre;
    std::cout << "Pseudo autre client : " << pseudo_autre << std::endl;
    // socketToServer.disconnect();    
    // portNouveauServeur >> port;
    // portNouveauServeur.getDataSize();
    // std::cout << "port:" << port << std::endl;
    std::string msg;
    sf::Packet packetMsg;
    sf::Packet msgAutre;
    std::string msgRecu;
    while (true)
      {
	std::cout << pseudo << " ";
	std::cin >> msg;
	packetMsg << msg;
        if (socketToServer.send(monBeauPseudo) != sf::Socket::Done)
	  exit(-1); // Erreur à l'envoi
	std::cout << "v send" << std::endl;
	
	if (socketToServer.receive(msgAutre) != sf::Socket::Done)
	  {
	    exit(-1);
	  }
	msgAutre >> msgRecu;
	std::cout << pseudo_autre << " : " << msgRecu << std::endl;
      }
    // if (socketdeux.connect("127.0.0.1", port) != sf::Socket::Done)
    //    exit(-1);  
    //  if (socketdeux.send(monBeauPseudo) != sf::Socket::Done)
    //   exit(-1); // Erreur à l'envoi
    return 0;
}


