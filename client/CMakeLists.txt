cmake_minimum_required( VERSION 3.0 )

project( sfml-client-server )

#set(CMAKE_CXX_STANDARD 14)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )

find_package( PkgConfig REQUIRED )
pkg_check_modules( SFML REQUIRED sfml-all )
#find_package(SFML 2 COMPONENTS system network)
include_directories( ${SFML_INCLUDE_DIRS} )

add_executable( PSonline_client.out src/client.cpp src/aff_elements.cpp )
target_link_libraries( PSonline_client.out ${SFML_LIBRARIES} )

add_executable(main.out src/Case.cpp src/main.cpp src/Pays.cpp src/Grille.cpp src/Bateau.cpp src/Jeu.cpp)
target_link_libraries( main.out ${PKG_LIBRARIES} )

#add_executable( PSonline_server.out src/server.cpp )
#target_link_libraries( server.out ${SFML_LIBRARIES} )

#install (TARGETS client.out DESTINATION bin)

