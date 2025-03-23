#include "SortingMachine.h"

#include <chrono>
#include <vector>
#include <iostream>

long long SortingMachine::insertionSort(std::vector <int>& sortedList) {
    int j=0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < sortedList.size(); i++) {
        int key = sortedList[i];
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

long long SortingMachine::quickSort(std::vector <int>& sortedList) {
    auto start = std::chrono::high_resolution_clock::now();



    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return duration.count();
}

void SortingMachine::checkSorting(std::vector <int>& sortedList) {
    bool isSorted = true;
    for (int i=1; i<sortedList.size(); i++) {
        if (sortedList[i] < sortedList[i-1]) {
            std::cout << "Table isn't sorted correctly!";
            isSorted = false;
        }
    }
    if (isSorted == true) {
        std::cout << "Table is sorted correctly!\n";
    }
}

