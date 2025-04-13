#include "SortingApp.h"
#include "FileReader.h"
#include "NumbersGenerator.h"
#include "SortingMachine.h"
#include <iostream>
#include <algorithm>
#include <vector>

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
                    case 5:
                        NumbersGenerator::generateNumbers(unsortedList, 100,unsortedListSize);
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
                        lastSortingTime = SortingMachine::heapSort(sortedList, sortedListSize);
                        break;
                    case 4:
                        showShellSortMenu();
                        getUserChoice();
                        switch (userChoice) {
                            case 1:
                                lastSortingTime = SortingMachine::shellSortBasic(sortedList, sortedListSize);
                                break;
                            case 2:
                                lastSortingTime = SortingMachine::shellSortKnuth(sortedList, sortedListSize);
                                break;
                            default:;
                        }
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
                break;
            case 8:
                turnOnOffPresentation();
                break;
            case 9:
                sortingAutomation();
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
        "6. Check sorting.\n"
        "7. Show last sorting time\n"
        "8. Turn on/off showing table after sorting.\n"
        "9. Start automate sorting.\n";
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
        "5. 100% array is sorted"
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

template <typename T>   //wyświetlenie menu shellsorta
void SortingApp<T>::showShellSortMenu() {
    cout<<"1. Classic Shell sequence - Gap: N/(2^k).\n"<<
        "2. Knuth's sequence - Gap: (3^k - 1)/2.\n"
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

template <typename T>
void SortingApp<T>::turnOnOffPresentation() {
    if (presentationAfterSorting) cout << "Presentation turned off\n";
    else cout << "Presentation turned on\n";
    cout<<"\n";
    presentationAfterSorting = !presentationAfterSorting;
}

template<typename T>
void SortingApp<T>::sortingAutomation() {
    int iterator = 40;

    std::vector<double> sortingResults;

    int percentageList[] = {0,33,66,100,-100};
    int sizesList[] = {15000,20000,25000,30000,40000,60000,80000};
    string filenamesList[] = {
    //     "output_Int_0Perc_15k.csv", "output_Int_0Perc_20k.csv", "output_Int_0Perc_25k.csv", "output_Int_0Perc_30k.csv", "output_Int_0Perc_40k.csv", "output_Int_0Perc_60k.csv", "output_Int_0Perc_80k.csv",
    // "output_Int_33Perc_15k.csv", "output_Int_33Perc_20k.csv", "output_Int_33Perc_25k.csv", "output_Int_33Perc_30k.csv", "output_Int_33Perc_40k.csv", "output_Int_33Perc_60k.csv", "output_Int_33Perc_80k.csv",
    // "output_Int_66Perc_15k.csv", "output_Int_66Perc_20k.csv", "output_Int_66Perc_25k.csv", "output_Int_66Perc_30k.csv", "output_Int_66Perc_40k.csv", "output_Int_66Perc_60k.csv", "output_Int_66Perc_80k.csv",
    // "output_Int_inverted_Perc_15k.csv", "output_Int_inverted_Perc_20k.csv", "output_Int_inverted_Perc_25k.csv", "output_Int_inverted_Perc_30k.csv", "output_Int_inverted_Perc_40k.csv", "output_Int_inverted_Perc_60k.csv", "output_Int_inverted_Perc_80k.csv"
    // "output_Int_100Perc_15k.csv", "output_Int_100Perc_20k.csv", "output_Int_100Perc_25k.csv", "output_Int_100Perc_30k.csv", "output_Int_100Perc_40k.csv", "output_Int_100Perc_60k.csv", "output_Int_100Perc_80k.csv"
        // 0%
        "output_Float_0Perc_15k.csv", "output_Float_0Perc_20k.csv", "output_Float_0Perc_25k.csv", "output_Float_0Perc_30k.csv", "output_Float_0Perc_40k.csv", "output_Float_0Perc_60k.csv", "output_Float_0Perc_80k.csv",
        // 33%
        "output_Float_33Perc_15k.csv", "output_Float_33Perc_20k.csv", "output_Float_33Perc_25k.csv", "output_Float_33Perc_30k.csv", "output_Float_33Perc_40k.csv", "output_Float_33Perc_60k.csv", "output_Float_33Perc_80k.csv",
        // 66%
        "output_Float_66Perc_15k.csv", "output_Float_66Perc_20k.csv", "output_Float_66Perc_25k.csv", "output_Float_66Perc_30k.csv", "output_Float_66Perc_40k.csv", "output_Float_66Perc_60k.csv", "output_Float_66Perc_80k.csv",
        // 100%
        "output_Float_100Perc_15k.csv", "output_Float_100Perc_20k.csv", "output_Float_100Perc_25k.csv", "output_Float_100Perc_30k.csv", "output_Float_100Perc_40k.csv", "output_Float_100Perc_60k.csv", "output_Float_100Perc_80k.csv",
        // inverted (-1)
        "output_Float_inverted_Perc_15k.csv", "output_Float_inverted_Perc_20k.csv", "output_Float_inverted_Perc_25k.csv", "output_Float_inverted_Perc_30k.csv", "output_Float_inverted_Perc_40k.csv", "output_Float_inverted_Perc_60k.csv", "output_Float_inverted_Perc_80k.csv"
    };
    for (int p = 0; p < std::size(percentageList); p++) {
        for (int s = 0; s < std::size(sizesList); s++) {
            unsortedListSize = sizesList[s];
            for (int i = 0; i < iterator; i++) {
                sortingResults.clear();
                std::cout<<i<<". "<<percentageList[p]<<", "<<sizesList[s]<<"\n";
                NumbersGenerator::generateNumbers(unsortedList, percentageList[p], unsortedListSize, false);

                copyUnsortedToSorted();
                lastSortingTime = SortingMachine::insertionSort(sortedList, sortedListSize);
                sortingResults.push_back(lastSortingTime);

                copyUnsortedToSorted();
                lastSortingTime = SortingMachine::quickSort(sortedList,1, sortedListSize);
                sortingResults.push_back(lastSortingTime);

                copyUnsortedToSorted();
                lastSortingTime = SortingMachine::quickSort(sortedList,2, sortedListSize);
                sortingResults.push_back(lastSortingTime);

                copyUnsortedToSorted();
                lastSortingTime = SortingMachine::quickSort(sortedList,3, sortedListSize);
                sortingResults.push_back(lastSortingTime);

                copyUnsortedToSorted();
                lastSortingTime = SortingMachine::quickSort(sortedList,4, sortedListSize);
                sortingResults.push_back(lastSortingTime);

                copyUnsortedToSorted();
                lastSortingTime = SortingMachine::heapSort(sortedList, sortedListSize);
                sortingResults.push_back(lastSortingTime);

                copyUnsortedToSorted();
                lastSortingTime = SortingMachine::shellSortBasic(sortedList, sortedListSize);
                sortingResults.push_back(lastSortingTime);

                copyUnsortedToSorted();
                lastSortingTime = SortingMachine::shellSortKnuth(sortedList, sortedListSize);
                sortingResults.push_back(lastSortingTime);

                FileReader::saveToCSV(sortingResults, filenamesList[p*std::size(sizesList)+s]);
            }
        }
    }
}


