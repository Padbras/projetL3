# projet L3 Informatique 
## Bataille Navale multijoueur

### Ce jeu est composé de deux applications, un serveur pour gérer les différentes interactions entre les joueurs et un client, qui lance le jeu en lui même avec l'interface graphique.


##### Commandes pour compiler : 
	mkdir build
	cd build
	cmake ..
	make

##### Commande pour lancer le serveur :
	./serveur.out 8888     // 8888 étant le port sur lequel se connecter

##### Commande pour lancer le client :
	./client.out 127.0.0.1 8888   // 127.0.0.1 est l'adresse IP du serveur sur lequel on veut 									//se connecter

#### NB : La gestion de la rotation et de la collision des bateaux lors de leur placement n'a pas encore été gérée dans l'interface graphique.
