#include "SortingApp.h"
#include "FileReader.h"
#include "NumbersGenerator.h"
#include "SortingMachine.h"
#include <iostream>
#include <fstream>


[[noreturn]] void SortingApp::runApp() {
    long long sortingTime = 0;
    while(true) {
        showMenu();
        getUserChoice();
        switch (userChoice) {
            case 1:
                FileReader::readFile(unsortedList);
                break;
            case 2:
                showGenerationMenu();
                getUserChoice();
                switch (userChoice) {
                    case 1:
                        NumbersGenerator::generateNumbers(unsortedList, 0);
                        break;
                    case 2:
                        NumbersGenerator::generateNumbers(unsortedList, 33);
                        break;
                    case 3:
                        NumbersGenerator::generateNumbers(unsortedList, 66);
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
                        sortingTime = SortingMachine::insertionSort(sortedList);
                        showUnsortedTable();
                        showSortedTable();
                        std::cout <<"\nSorting time: "<< sortingTime <<"ms\n";
                        break;
                    case 2:
                        showQuickSortMenu();
                        getUserChoice();
                        switch (userChoice) {
                            case 1:
                                sortingTime = SortingMachine::quickSort(sortedList,1);
                                break;
                            case 2:
                                sortingTime = SortingMachine::quickSort(sortedList,2);
                                break;
                            case 3:
                                sortingTime = SortingMachine::quickSort(sortedList,3);
                                break;
                            case 4:
                                sortingTime = SortingMachine::quickSort(sortedList,4);
                                break;
                            default:;
                        }
                        showUnsortedTable();
                        showSortedTable();
                        std::cout <<"\nSorting time: "<< sortingTime <<"ms\n";
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
                SortingMachine::checkSorting(sortedList);
                break;
            default: ;
        }
    }
}

void SortingApp::getUserChoice() {
    std::cin>>userChoice;
}

void SortingApp::showMenu() {
    cout<<"1. Read file.\n"<<
        "2. Generating numbers menu.\n"
        "3. Show actually using unsorted table.\n"
        "4. Show sorted table.\n"
        "5. Sorting menu.\n"
        "6. Check sorting\n";
}

void SortingApp::showSortingMenu() {
    cout<<"1. Insertion sort.\n"<<
        "2. Quick sort.\n"
        "3. Heap sort.\n"
        "4. Shell sort.\n"
        "0. Exit\n";
}

void SortingApp::showGenerationMenu() {
    cout<<"1. 0% array is sorted.\n"<<
        "2. 33% array is sorted.\n"
        "3. 66% array is sorted.\n"
        "0. Exit\n";
}

void SortingApp::showQuickSortMenu() {
    cout<<"1. Pivot on the left.\n"<<
        "2. Pivot on the right.\n"
        "3. Pivot in the middle.\n"
        "4. Random pivot place\n"
        "0. Exit\n";
}



void SortingApp::showUnsortedTable() const {
    if (unsortedList.size() == 0)
        cout<<"Unsorted table is empty."<<endl;
    else
        cout<<"Unsorted table: \n";
    for(int i = 0; i < unsortedList.size(); i++) {
        cout << unsortedList[i] << "\n";
    }
    cout<<"\n";
}

void SortingApp::showSortedTable() const {
    if (sortedList.size() == 0)
        cout<<"Sorted table is empty."<<endl;
    else
        cout<<"Sorted table: \n";
    for(int i = 0; i < sortedList.size(); i++) {
        cout << sortedList[i] << "\n";
    }
    cout<<"\n";
}

void SortingApp::copyUnsortedToSorted() {
    sortedList.clear();
    sortedList = unsortedList;
}


