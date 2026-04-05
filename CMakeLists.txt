cmake_minimum_required(VERSION 4.1)
project(Tarea_6_Lista_ordenada_compuesta)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tarea_6_Lista_ordenada_compuesta
        ListaDoble.hpp
        ListaDoble.tpp
        ListaOrdenada.hpp
        ListaOrdenada.tpp
        main.cpp
        CapturaSegura.hpp
        CapturaSegura.tpp)