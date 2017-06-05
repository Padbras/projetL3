cmake_minimum_required( VERSION 3.0 )

project( sfml-client-server )

#set(CMAKE_CXX_STANDARD 14)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )

find_package( PkgConfig REQUIRED )
pkg_check_modules( SFML REQUIRED sfml-all )
#find_package(SFML 2 COMPONENTS system network)
include_directories( ${SFML_INCLUDE_DIRS} serveur/include client/include)

add_executable(test.out  client/src/gestionGrille.cpp
			   client/src/fenetrePosBateau.cpp
			   client/src/fenetreJeu.cpp
			   client/src/fenetreWin.cpp
			   client/src/fenetreLoose.cpp)
target_link_libraries(test.out ${SFML_LIBRARIES} )
