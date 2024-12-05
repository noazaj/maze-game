cmake_minimum_required(VERSION 3.0)
project(SFML_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

add_executable(SFML_Project src/main.cpp)
target_link_libraries(SFML_Project sfml-graphics sfml-audio sfml-window sfml-system)
