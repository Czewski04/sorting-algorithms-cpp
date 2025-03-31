#include "SortingApp.h"
#include "FileReader.h"
#include "NumbersGenerator.h"
#include "SortingMachine.h"
#include <iostream>
#include <algorithm>

template <typename T>   //funckja zarządzająca menu aplikacji
[[noreturn]] void SortingApp<T>::runApp() {
    while(true) {
        showMenu();
        getUserChoice();
        switch (userChoice) {
            case 1:
                FileReader::readFile(unsortedList, listSize);
                break;
            case 2:
                showGenerationMenu();
                getUserChoice();
                switch (userChoice) {
                    case 1:
                        NumbersGenerator::generateNumbers(unsortedList, 0, listSize);
                        break;
                    case 2:
                        NumbersGenerator::generateNumbers(unsortedList, 33, listSize);
                        break;
                    case 3:
                        NumbersGenerator::generateNumbers(unsortedList, 66,listSize);
                        break;
                    case 4:
                        NumbersGenerator::generateNumbers(unsortedList, -100,listSize);
                        break;
                    default: ;
                }
                break;
            case 3:
                showUnsortedTable();
                break;
            case 4:
                showSortedTable();
                break;
            case 5:
                showSortingMenu();
                copyUnsortedToSorted();
                getUserChoice();
                switch (userChoice) {
                    case 1:
                        lastSortingTime = SortingMachine::insertionSort(sortedList, listSize);
                        showUnsortedTable();
                        showSortedTable();
                        std::cout <<"\nSorting time: "<< lastSortingTime <<"ms\n";
                        break;
                    case 2:
                        showQuickSortMenu();
                        getUserChoice();
                        switch (userChoice) {
                            case 1:
                                lastSortingTime = SortingMachine::quickSort(sortedList,1, listSize);
                                break;
                            case 2:
                                lastSortingTime = SortingMachine::quickSort(sortedList,2, listSize);
                                break;
                            case 3:
                                lastSortingTime = SortingMachine::quickSort(sortedList,3, listSize);
                                break;
                            case 4:
                                lastSortingTime = SortingMachine::quickSort(sortedList,4, listSize);
                                break;
                            default:;
                        }
                        showUnsortedTable();
                        showSortedTable();
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 0:
                        break;
                    default: ;
                }
                break;
            case 6:
                SortingMachine::checkSorting(sortedList, listSize);
                break;
            default: ;
        }
    }
}

template <typename T>   //funkcja pobierająca wybór użytkownika
void SortingApp<T>::getUserChoice() {
    std::cin>>userChoice;
}

template <typename T>   //wyświetlenie menu głównego
void SortingApp<T>::showMenu() {
    cout<<"1. Read file.\n"<<
        "2. Generating numbers menu.\n"
        "3. Show actually using unsorted table.\n"
        "4. Show sorted table.\n"
        "5. Sorting menu.\n"
        "6. Check sorting\n";
}

template <typename T>   //wyświetlenie menu sortowania
void SortingApp<T>::showSortingMenu() {
    cout<<"1. Insertion sort.\n"<<
        "2. Quick sort.\n"
        "3. Heap sort.\n"
        "4. Shell sort.\n"
        "0. Exit\n";
}

template <typename T>   //wyświetlenie menu generowania liczb
void SortingApp<T>::showGenerationMenu() {
    cout<<"1. 0% array is sorted.\n"<<
        "2. 33% array is sorted.\n"
        "3. 66% array is sorted.\n"
        "4. Array sorted descending\n"
        "0. Exit\n";
}

template <typename T>   //wyświetlenie menu quicksorta
void SortingApp<T>::showQuickSortMenu() {
    cout<<"1. Pivot on the left.\n"<<
        "2. Pivot on the right.\n"
        "3. Pivot in the middle.\n"
        "4. Random pivot place\n"
        "0. Exit\n";
}

template <typename T>   //wyświetlenie nieposortowanej tablicy
void SortingApp<T>::showUnsortedTable() const {
    if (listSize == 0)
        cout<<"Unsorted table is empty."<<endl;
    else
        cout<<"Unsorted table: \n";
    for(int i=0; i<listSize; i++){
        cout<<unsortedList[i]<<"\n";
    }
    cout<<"\n";
}

template <typename T>   //wyświetlenie posortowanej tablicy
void SortingApp<T>::showSortedTable() const {
    if (listSize == 0)
        cout<<"Sorted table is empty."<<endl;
    else
        cout<<"Sorted table: \n";
    for(int i = 0; i < listSize; i++) {
        cout << sortedList[i] << "\n";
    }
    cout <<"\nLast sorting time: "<< lastSortingTime <<"ms\n";
    cout<<"\n";
}

template <typename T>   //kopiowanie tablicy nieposortowanej
void SortingApp<T>::copyUnsortedToSorted() {
    delete[] sortedList;
    sortedList = new T[listSize];
    copy(unsortedList, unsortedList+listSize, sortedList);
}