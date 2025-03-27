#ifndef SORTINGAPP_H
#define SORTINGAPP_H
#include <vector>

class SortingApp {
public:
    [[noreturn]] void runApp();

private:
    int userChoice = 0;
    long long lastSortingTime = 0;
    std::vector<int> unsortedList;
    std::vector<int> sortedList;

    void getUserChoice();
    void showUnsortedTable() const;
    void showSortedTable() const;
    void copyUnsortedToSorted();

    static void showMenu();
    static void showSortingMenu();
    static void showGenerationMenu();
    static void showQuickSortMenu();
};

#endif //SORTINGAPP_H
