cmake_minimum_required(VERSION 3.17)
project(FM20Compare)

set(CMAKE_CXX_STANDARD 14)

add_executable(FM20Compare main.cpp App.cpp App.h Person.cpp Person.h Player.cpp Player.h Staff.cpp Staff.h AttributeRange.h)