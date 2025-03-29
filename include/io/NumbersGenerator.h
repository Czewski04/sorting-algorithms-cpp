#ifndef NUMBERSGENERATOR_H
#define NUMBERSGENERATOR_H

#include <vector>

class NumbersGenerator {
public:
    template<typename T>
    static void generateNumbers(T*& unsortedList, int presortedPercentage, int& arraySize);

    template<typename T>
    static void generateFloatNumbers(T*& unsortedList, int presortedPercentage, int arraySize);

    template<typename T>
    static void generateIntNumbers(T*& unsortedList, int presortedPercentage, int arraySize);

    static int askForArraySize();
};


#include "NumbersGenerator.tpp"
#endif //NUMBERSGENERATOR_H
