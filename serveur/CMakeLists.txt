cmake_minimum_required( VERSION 3.0 )

project( sfml-client-server )

#set(CMAKE_CXX_STANDARD 14)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )

find_package( PkgConfig REQUIRED )
pkg_check_modules( SFML REQUIRED sfml-all )
#find_package(SFML 2 COMPONENTS system network)
include_directories( ${SFML_INCLUDE_DIRS} include )

add_executable( client.out src/client.cpp
			   src/display.cpp
			   src/connect.cpp
			   src/packet.cpp)
target_link_libraries( client.out ${SFML_LIBRARIES} )

add_executable( server.out src/server.cpp
			   src/display.cpp
			   src/connect.cpp
			   src/packet.cpp)
target_link_libraries( server.out ${SFML_LIBRARIES} )

install (TARGETS client.out server.out DESTINATION bin)

