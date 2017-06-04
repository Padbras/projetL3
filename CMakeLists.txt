cmake_minimum_required( VERSION 3.0 )

project( sfml-client-server )

#set(CMAKE_CXX_STANDARD 14)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )

find_package( PkgConfig REQUIRED )
pkg_check_modules( SFML REQUIRED sfml-all )
#find_package(SFML 2 COMPONENTS system network)
include_directories( ${SFML_INCLUDE_DIRS} serveur/include )

#add_executable( PSonline_client.out src/fenetreAccueil.cpp )
#target_link_libraries( PSonline_client.out ${SFML_LIBRARIES} )

add_executable(PSOnline_client.out client/src/Case.cpp client/src/main.cpp client/src/Pays.cpp client/src/Grille.cpp client/src/Bateau.cpp client/src/Jeu.cpp client/src/fenetreAccueil.cpp  serveur/src/client.cpp serveur/src/joueur.cpp serveur/src/connect.cpp  serveur/src/packet.cpp serveur/src/display.cpp )
target_link_libraries( PSOnline_client.out ${SFML_LIBRARIES} )

add_executable( PSonline_server.out  serveur/src/client.cpp serveur/src/connect.cpp serveur/src/display.cpp serveur/src/joueur.cpp serveur/src/packet.cpp  serveur/src/server.cpp client/src/Grille.cpp client/src/Case.cpp)
target_link_libraries( PSonline_server.out ${SFML_LIBRARIES} )


