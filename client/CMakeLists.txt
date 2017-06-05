cmake_minimum_required( VERSION 3.0 )
project( projetL3 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )
set( CMAKE_BUILD_TYPE Debug )  # dans la vraie vie, ne pas mettre cette ligne

find_package( PkgConfig REQUIRED )
pkg_check_modules( SFML REQUIRED sfml-all )
include_directories( ${PKG_INCLUDE_DIRS} )

add_executable( main.out src/Case.cpp src/main.cpp src/Pays.cpp src/Grille.cpp src/Bateau.cpp src/Jeu.cpp src/Joueur.cpp)
target_link_libraries( main.out ${PKG_LIBRARIES} )
