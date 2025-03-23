#include "SortingApp.h"
#include "FileReader.h"
#include "NumbersGenerator.h"
#include "SortingMachine.h"
#include <iostream>
#include <fstream>



void SortingApp::runApp() {
    long long sortingTime = 0;
    while(true) {
        showMenu();
        getUserChoice();
        switch (userChoice) {
            case 1:
                FileReader::readFile(unsortedList);
                break;
            case 2:
                NumbersGenerator::generateNumbers(unsortedList);
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
                }
                break;
            case 6:
                break;
            case 7:
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
        "2. Generate numbers.\n"
        "3. Show actually using unsorted table.\n"
        "4. Show sorted table.\n"
        "5. Sorting menu.\n"
        "6. Presorting settings\n"
        "7. Check sorting\n";
}

void SortingApp::showSortingMenu() {
    cout<<"1. Insertion sort.\n"<<
        "2. Quick sort.\n"
        "3. Heap sort.\n"
        "4. Shell sort.\n"
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


