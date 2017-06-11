cmake_minimum_required( VERSION 3.0 )

project( sfml-client-server )

#set(CMAKE_CXX_STANDARD 14)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -Wall -Wextra" )

find_package( PkgConfig REQUIRED )
pkg_check_modules( SFML REQUIRED sfml-all )
#find_package(SFML 2 COMPONENTS system network)
include_directories( ${SFML_INCLUDE_DIRS} include/)

add_executable(client.out client/src/Case.cpp
			  client/src/client.cpp
			  client/src/Pays.cpp
			  client/src/Grille.cpp
			  client/src/Bateau.cpp
		   	  client/src/Case.cpp
		   	  client/src/Joueur.cpp
			  client/src/fenetreAccueil.cpp
			  client/src/fenetrePosBateau.cpp
			  client/src/gestionGrille.cpp
			  client/src/fenetreJeu.cpp
			  client/src/fenetreLoose.cpp
			  client/src/fenetreWin.cpp
			  client/src/infos.cpp
			  client/src/gestionBateau.cpp
			  serveur/src/client.cpp
			  serveur/src/joueur.cpp
			  serveur/src/connect.cpp
			  serveur/src/packet.cpp
			  serveur/src/display.cpp
			  )
target_link_libraries(client.out ${SFML_LIBRARIES} )

add_executable(server.out  serveur/src/client.cpp
			   serveur/src/connect.cpp
		       serveur/src/display.cpp
			   serveur/src/joueur.cpp
			   serveur/src/packet.cpp
 			   serveur/src/server.cpp
		       client/src/Grille.cpp
			   client/src/Case.cpp)
target_link_libraries(server.out ${SFML_LIBRARIES} )


