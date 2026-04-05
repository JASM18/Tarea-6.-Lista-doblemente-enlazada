cmake_minimum_required(VERSION 4.1)
project(Tarea_6__Lista_doblemente_enlazada)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tarea_6__Lista_doblemente_enlazada
        ListaDoble.hpp
        ListaDoble.tpp
        ListaOrdenada.hpp
        ListaOrdenada.tpp
        main.cpp)