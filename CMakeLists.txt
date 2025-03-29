cmake_minimum_required(VERSION 3.30)
project(sortingAlgorithms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,536870912") #powiekszenie stosu do 512MB


include_directories(
        include/algorithms
        include/io
        include/app
)

add_executable(sortingAlgorithms
        src/algorithms/SortingMachine.cpp
        src/App/Main.cpp
)
