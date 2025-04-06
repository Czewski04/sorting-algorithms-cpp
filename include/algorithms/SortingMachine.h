#ifndef SORTINGMACHINE_H
#define SORTINGMACHINE_H

class SortingMachine {
public:
    //dekalracja funkcji sortujących
    template<typename T>
    static double quickSort(T* sortedList, int pivotPosition, int arraySize);
    template<typename T>
    static void quickSortImplementation(T* sortedList, int begin , int end, int pivotPosition);
    template<typename T>
    static double insertionSort(T* sortedList, int arraySize);
//    template<typename T>
//    static double heapSort(T* sortedList, int arraySize);
//    template<typename T>
//    static double shellSort(T* sortedList, int arraySize);
    template<typename T>
    static void checkSorting(T* sortedList, int arraySize);
};
#include "SortingMachine.tpp"
#endif //SORTINGMACHINE_H
