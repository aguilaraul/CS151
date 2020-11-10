cmake_minimum_required(VERSION 3.17)
project(FM20StaffFinder)

set(CMAKE_CXX_STANDARD 14)

add_executable(FM20StaffFinder main.cpp Person.cpp Person.h Staff.cpp Staff.h Player.cpp Player.h)