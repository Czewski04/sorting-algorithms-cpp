#include "NumbersGenerator.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void NumbersGenerator::generateNumbers(std::vector <int>& unsortedList, int presortedPercentage){
    unsortedList.clear();
    int arraySize = askForArraySize();

    if (presortedPercentage == 100) {
        for (int i=arraySize; i >= 1; i--) {
            unsortedList.push_back(i);
        }
        cout << "All numbers ("<<unsortedList.size()<<") generated successfully.\n \n";
        return;
    }

    int sortedIndex = ((float)presortedPercentage/100.0f)*arraySize;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(sortedIndex, arraySize);

    if (sortedIndex>0) {
        for (int i=0; i<sortedIndex; i++) {
            unsortedList.push_back(i);
        }
    }

    for(int i = sortedIndex; i < arraySize; i++){
      unsortedList.push_back(distribution(generator));
    }

    cout << "All numbers ("<<unsortedList.size()<<") generated successfully.\n \n";
}

int NumbersGenerator::askForArraySize(){
    int arraySize = 0;
    cout << "Enter number of elements to sort:\n";
    cin >> arraySize;
    return arraySize;
}
