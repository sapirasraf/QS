cmake_minimum_required(VERSION 3.16)
project(QS)

set(CMAKE_CXX_STANDARD 17)

add_executable(QS main.cpp Series.cpp Series.h Encode.cpp Encode.h cmake-build-debug/NoDiv.h cmake-build-debug/NoDiv.cpp)