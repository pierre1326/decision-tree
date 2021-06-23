# cmake version
cmake_minimum_required( VERSION 3.0 )

#project name
project( decision-tree )

#flags

#files

#include
include_directories( ./include ./src ./lib/nlohmann/include )

#target
add_executable( 
  decisionTree 
  ./src/Main/main.cpp
  ./src/File/File.cpp
  ./src/List/List.cpp
  ./src/Tree/Tree.cpp
  ./src/Cart/Cart.cpp
  ./src/Bot/Bot.cpp
)

#external libs