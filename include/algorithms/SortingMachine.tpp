#include "SortingMachine.h"

#include <chrono>
#include <vector>
#include <iostream>
#include <utility>
#include <random>

template<typename T> //implementacja algorytmu sortowania przez wstawiania
long long SortingMachine::insertionSort(T*& sortedList, int arraySize) {
    int j=0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i <arraySize; i++) {
        T key = sortedList[i];
        j=i-1;
        while (j>=0 && key < sortedList[j]) {
            sortedList[j+1] = sortedList[j];
            j--;
        }
        sortedList[j+1] = key;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return duration.count();
}

template<typename T> //funkcja sterująca sortowaniem szybkim
long long SortingMachine::quickSort(T*& sortedList, int pivotPosition, int arraySize) {
    auto start = std::chrono::high_resolution_clock::now();

    quickSortImplementation(sortedList, 0, arraySize-1, pivotPosition);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return duration.count();
}

template<typename T> //funkcja testująca poprawność sortowania
void SortingMachine::checkSorting(T*& sortedList, int arraySize) {
    bool isSorted = true;
    if (arraySize == 0) {
        std::cout << "Empty sorted list.\n\n";
        return;
    }
    for (int i=1; i<arraySize; i++) {
        if (sortedList[i] < sortedList[i-1]) {
            isSorted = false;
        }
    }
    if (isSorted == true) {
        std::cout << "Table is sorted correctly!\n";
    }
    else
        std::cout << "Table is not sorted correctly!\n";
    std::cout<<"\n";
}

template<typename T> //implementacja algorytmu sortowania szybkiego
void SortingMachine::quickSortImplementation(T *&sortedList, int begin, int end, int pivotPosition) {
    if (begin >= end) return;
    T pivot=0;              //wybór pivota
    if (pivotPosition==1) {
        pivot = sortedList[begin];
        std::swap(sortedList[begin], sortedList[end]);
    }
    else if (pivotPosition==2) {
        pivot = sortedList[end];
    }
    else if (pivotPosition==3) {
        pivot = sortedList[((end-begin)/2)+begin];
        std::swap(sortedList[((end-begin)/2)+begin], sortedList[end]);
    }
    else if (pivotPosition==4) {
        std::srand(std::time(nullptr));
        int pivotIndex = begin + std::rand() % (end - begin + 1);
        pivot = sortedList[pivotIndex];
        std::swap(sortedList[pivotIndex], sortedList[end]);
    }

    int left = begin;
    int right = end-1;

    while (left <= right) {
        while (left <= right && sortedList[left] < pivot) {
            left++;
        }
        while (left <= right && sortedList[right] > pivot) {
            right--;
        }
        if (left <= right) {
            std::swap(sortedList[left], sortedList[right]);
            left++;
            right--;
        }
    }

    std::swap(sortedList[left], sortedList[end]);

    quickSortImplementation(sortedList, begin, left-1, pivotPosition); // left array
    quickSortImplementation(sortedList, left+1, end, pivotPosition); // right array
}




