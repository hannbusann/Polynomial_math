cmake_minimum_required(VERSION 2.8.3)
project(Polynomial)


find_package( Eigen3 REQUIRED )
include_directories( ${EIGEN3_INCLUDE_DIR} )

include_directories( Polynomial )

add_executable( testpolynomial test/testpolynomial.cpp )


