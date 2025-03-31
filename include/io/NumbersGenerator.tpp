#include "NumbersGenerator.h"
#include <iostream>
#include <vector>
#include <random>
#include <ranges>

using namespace std;

int NumbersGenerator::askForArraySize(){        //wczytywanie rozmiaru tablicy od użytkownika
    int arraySize = 0;
    cout << "Enter number of elements to sort:\n";
    cin >> arraySize;
    return arraySize;
}

template <typename T>       //funkcja sterująca generowaniem liczb
void NumbersGenerator::generateNumbers(T*& unsortedList, int presortedPercentage, int& arraySize){
    delete[] unsortedList;
    arraySize = askForArraySize();
    unsortedList = new T[arraySize];

    if(is_same<T, int>::value){
        generateIntNumbers(unsortedList, presortedPercentage, arraySize);
    }
    else if(is_same<T, float>::value){
        generateFloatNumbers(unsortedList, presortedPercentage, arraySize);
    }

    cout << "All numbers ("<<arraySize<<") generated successfully.\n \n";
}

template <typename T>
void NumbersGenerator::generateIntNumbers(T*& unsortedList, int presortedPercentage, int arraySize){
    //generowanie tablicy posortowanej odwrotnie
    if (presortedPercentage == -100) {
        for (int i=0; i < arraySize; i++) {
            unsortedList[i]=arraySize-i;
        }
        return;
    }

    int sortedIndex = ((float)presortedPercentage/100.0f)*arraySize;    //obliczaczenie indeksu do którego tablica ma być posortowana

    //tworzenie generatora liczb
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(sortedIndex, arraySize);

    //generowanie posortowanej częsci tablicy
    if (sortedIndex>0) {
        for (int i=0; i<sortedIndex; i++) {
            unsortedList[i]=i;
        }
    }

    //generowanie nieposortowanej części tablicy
    for(int i = sortedIndex; i < arraySize; i++){
        unsortedList[i]=distribution(generator);
    }
}

template <typename T>
void NumbersGenerator::generateFloatNumbers(T *&unsortedList, int presortedPercentage, int arraySize) {
    //generowanie tablicy posortowanej odwrotnie
    if (presortedPercentage == -100) {
        for (int i=0; i < arraySize; i++) {
            unsortedList[i]=arraySize-i-0.5;
        }
        return;
    }

    int sortedIndex = ((float)presortedPercentage/100.0f)*arraySize;    //obliczaczenie indeksu do którego tablica ma być posortowana

    //tworzenie generatora liczb
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<float> distribution(sortedIndex, arraySize);

    //generowanie posortowanej częsci tablicy
    if (sortedIndex>0) {
        for (int i=0; i<sortedIndex; i++) {
            unsortedList[i]=i+0.5;
        }
    }

    //generowanie nieposortowanej części tablicy
    for(int i = sortedIndex; i < arraySize; i++){
        unsortedList[i]=distribution(generator);
    }

}

