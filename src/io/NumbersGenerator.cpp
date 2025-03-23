#include "NumbersGenerator.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void NumbersGenerator::generateNumbers(std::vector <int>& unsortedList){
    unsortedList.clear();
    int arraySize = askForArraySize();
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, arraySize);
    for(int i = 0; i < arraySize; i++){
      unsortedList.push_back(distribution(generator));
    }

    cout << "All numbers ("<<arraySize<<") generated successfully.\n \n";
}

int NumbersGenerator::askForArraySize(){
    int arraySize = 0;
    cout << "Enter number of elements to sort:\n";
    cin >> arraySize;
    return arraySize;
}
