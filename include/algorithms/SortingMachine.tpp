#include "SortingMachine.h"

#include <chrono>
#include <iostream>
#include <utility>

template<typename T> //implementacja algorytmu sortowania przez wstawiania
double SortingMachine::insertionSort(T* sortedList, int arraySize) {
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
    auto duration = std::chrono::duration<double, std::milli>(end - start);

    return duration.count();
}

template<typename T> //funkcja sterująca sortowaniem szybkim
double SortingMachine::quickSort(T* sortedList, int pivotPosition, int arraySize) {
    auto start = std::chrono::high_resolution_clock::now();

    quickSortImplementation(sortedList, 0, arraySize-1, pivotPosition);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);

    return duration.count();
}

template<typename T> //implementacja algorytmu sortowania szybkiego
void SortingMachine::quickSortImplementation(T* sortedList, int begin, int end, int pivotPosition) {
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

    std::swap(sortedList[left], sortedList[end]);       // zamiana miejsc pivota

    quickSortImplementation(sortedList, begin, left-1, pivotPosition); // lewa podtablica
    quickSortImplementation(sortedList, left+1, end, pivotPosition); // prawa podtablica
}

template<typename T>
double SortingMachine::heapSort(T *sortedList, int arraySize) {
    auto start = std::chrono::high_resolution_clock::now();

    // Budowanie kopca max-heap
    for (int i = arraySize / 2 - 1; i >= 0; i--)
        heapify(sortedList, arraySize, i);

    // Wyciąganie elementów z kopca jeden po drugim
    for (int i = arraySize - 1; i > 0; i--) {
        std::swap(sortedList[0], sortedList[i]);           // Zamiana korzenia z ostatnim elementem
        heapify(sortedList, i, 0);                  // Heapowanie zmniejszonej tablicy
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);

    return duration.count();
}

template<typename T>
void SortingMachine::heapify(T* sortedList, int arraySize, int rootIndex) {
    int largest = rootIndex;
    int left = 2 * rootIndex + 1;
    int right = 2 * rootIndex + 2;

    // sprawdzanie lewego dziecka
    if (left < arraySize && sortedList[left] > sortedList[largest])
        largest = left;

    // sprawdzanie prawego dziecka
    if (right < arraySize && sortedList[right] > sortedList[largest])
        largest = right;

    // zamiana z korzeniem i heapowanie
    if (largest != rootIndex) {
        std::swap(sortedList[rootIndex], sortedList[largest]);
        heapify(sortedList, arraySize, largest);
    }
}

template<typename T>
double SortingMachine::shellSortBasic(T *sortedList, int arraySize) {
    auto start = std::chrono::high_resolution_clock::now();

    int gap = arraySize / 2;    //obliczanie największego odstępu
    while (gap>0) {
        for (int i = gap; i < arraySize; i++) {
            T temp = sortedList[i];
            int j;
            for (j = i; j >= gap && sortedList[j - gap] > temp; j -= gap) {
                sortedList[j] = sortedList[j - gap];
            }
            sortedList[j] = temp;
        }
        gap /= 2; // obliczanie odstępów
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);

    return duration.count();
}

template<typename T>
double SortingMachine::shellSortKnuth(T *sortedList, int arraySize) {
    auto start = std::chrono::high_resolution_clock::now();

    int gap = 1;
    while (gap < arraySize/3) { //obliczanie największego odstępu
        gap  = 3 * gap +1;
    }

    while (gap>0) {
        for (int i = gap; i < arraySize; i++) {
            T temp = sortedList[i];
            int j;
            for (j = i; j >= gap && sortedList[j - gap] > temp; j -= gap) {
                sortedList[j] = sortedList[j - gap];
            }
            sortedList[j] = temp;
        }
        gap = (gap-1)/3;    //obliczanie odstępów
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);

    return duration.count();
}



template<typename T> //funkcja testująca poprawność sortowania
void SortingMachine::checkSorting(T* sortedList, int arraySize) {
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



