cmake_minimum_required(VERSION 3.12)
project(Korean-English-Esports-Glossary)

set(CMAKE_CXX_STANDARD 17)

add_executable(Korean-English-Esports-Glossary
    src/main.cpp
    src/Parser.cpp
    src/Search.cpp
    src/Term.hpp
)