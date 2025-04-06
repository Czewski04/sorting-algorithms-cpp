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
                FileReader::readFile(unsortedList, unsortedListSize);
                break;
            case 2:
                showGenerationMenu();
                getUserChoice();
                switch (userChoice) {
                    case 1:
                        NumbersGenerator::generateNumbers(unsortedList, 0, unsortedListSize);
                        break;
                    case 2:
                        NumbersGenerator::generateNumbers(unsortedList, 33, unsortedListSize);
                        break;
                    case 3:
                        NumbersGenerator::generateNumbers(unsortedList, 66,unsortedListSize);
                        break;
                    case 4:
                        NumbersGenerator::generateNumbers(unsortedList, -100,unsortedListSize);
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
                        lastSortingTime = SortingMachine::insertionSort(sortedList, sortedListSize);
                        break;
                    case 2:
                        showQuickSortMenu();
                        getUserChoice();
                        switch (userChoice) {
                            case 1:
                                lastSortingTime = SortingMachine::quickSort(sortedList,1, sortedListSize);
                                break;
                            case 2:
                                lastSortingTime = SortingMachine::quickSort(sortedList,2, sortedListSize);
                                break;
                            case 3:
                                lastSortingTime = SortingMachine::quickSort(sortedList,3, sortedListSize);
                                break;
                            case 4:
                                lastSortingTime = SortingMachine::quickSort(sortedList,4, sortedListSize);
                                break;
                            default:;
                        }
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 0:
                        break;
                    default: ;
                }
                if(presentationAfterSorting){
                    showUnsortedTable();
                    showSortedTable();
                }
                SortingMachine::checkSorting(sortedList, sortedListSize);
                showSortingTime();
                break;
            case 6:
                SortingMachine::checkSorting(sortedList, sortedListSize);
                break;
            case 7:
                showSortingTime();
            case 8:
                presentationAfterSorting = !presentationAfterSorting;
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
        "6. Check sorting\n"
        "7. Show last sorting time\n"
        "8. Turn on/off showing table after sorting\n";
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
    if (unsortedListSize == 0)
        cout<<"Unsorted table is empty.";
    else {
        cout << "Unsorted table: \n";
        for (int i = 0; i < unsortedListSize; i++) {
            cout << unsortedList[i] << " ";
        }
    }
    cout<<"\n\n";
}

template <typename T>   //wyświetlenie posortowanej tablicy
void SortingApp<T>::showSortedTable() const {
    if (sortedListSize == 0)
        cout<<"Sorted table is empty.";
    else{
        cout<<"Sorted table: \n";
        for(int i = 0; i < sortedListSize; i++) {
            cout << sortedList[i] << " ";
        }
    }
    cout<<"\n\n";
}

template <typename T>   //kopiowanie tablicy nieposortowanej
void SortingApp<T>::copyUnsortedToSorted() {
    delete[] sortedList;
    sortedListSize= unsortedListSize;
    sortedList = new T[sortedListSize];
    copy(unsortedList, unsortedList+unsortedListSize, sortedList);
}

template <typename T>   //wyświetlenie ostatniego czasu sortowania
void SortingApp<T>::showSortingTime() const {
    cout <<"Last sorting time: "<< lastSortingTime <<"ms\n";
    cout<<"\n";
}
