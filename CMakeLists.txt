cmake_minimum_required(VERSION 3.30)
project(sortingAlgorithms)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        include/algorithms
        include/io
        include/app
)

add_executable(sortingAlgorithms
        src/algorithms/SortingMachine.cpp
        src/io/NumbersGenerator.cpp
        src/io/FileReader.cpp
        src/app/SortingApp.cpp
        src/App/Main.cpp
)
