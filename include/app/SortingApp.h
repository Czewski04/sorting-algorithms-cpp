#ifndef SORTINGAPP_H
#define SORTINGAPP_H
#include <vector>

class SortingApp {
public:
    void runApp();
    void getUserChoice();
    void showUnsortedTable() const;
    void showSortedTable() const;
    void copyUnsortedToSorted();

    static void showMenu();
    static void showSortingMenu();
private:
    int userChoice = 0;
    std::vector<int> unsortedList;
    std::vector<int> sortedList;
};

#endif //SORTINGAPP_H
