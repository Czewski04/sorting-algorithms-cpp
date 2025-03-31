#ifndef SORTINGMACHINE_H
#define SORTINGMACHINE_H

#include <vector>

class SortingMachine {
public:
    //dekalracja funkcji sortujących
    template<typename T>
    static long long quickSort(T*& sortedList, int pivotPosition, int arraySize);
    template<typename T>
    static void quickSortImplementation(T*& sortedList, int begin , int end, int pivotPosition);
    template<typename T>
    static long long insertionSort(T*& sortedList, int arraySize);
//    template<typename T>
//    static long long heapSort(T*& sortedList, int arraySize);
//    template<typename T>
//    static long long shellSort(T*& sortedList, int arraySize);
    template<typename T>
    static void checkSorting(T*& sortedList, int arraySize);
};
#include "SortingMachine.tpp"
#endif //SORTINGMACHINE_H
