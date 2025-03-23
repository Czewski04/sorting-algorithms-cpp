#ifndef SORTINGMACHINE_H
#define SORTINGMACHINE_H

#include <vector>

class SortingMachine {
public:
    static long long quickSort(std::vector <int>& sortedList);
    static long long insertionSort(std::vector <int>& sortedList);
    static long long heapSort(std::vector <int>& sortedList);
    static long long ShellSort(std::vector <int>& sortedList);
    static void checkSorting(std::vector <int>& sortedList);
};



#endif //SORTINGMACHINE_H
