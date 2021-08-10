# cmake version
cmake_minimum_required( VERSION 3.0 )

#project name
project( decision-tree )

#flags

#files

#include
include_directories( ./include ./src ./lib/rapidjson/include )

#target
add_executable( 
  decisionTree 
  ./src/Main/main.cpp
  ./src/Parser/ParserModbus.cpp
)

#external libs