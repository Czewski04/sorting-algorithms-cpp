#ifndef NUMBERSGENERATOR_H
#define NUMBERSGENERATOR_H

#include <vector>

class NumbersGenerator {
public:
    static void generateNumbers(std::vector <int>& unsortedList, int presortedPercentage);
    static int askForArraySize();
};



#endif //NUMBERSGENERATOR_H
