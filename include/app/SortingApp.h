#ifndef SORTINGAPP_H
#define SORTINGAPP_H

template<typename T>
class SortingApp {
public:             //utworzenie struktury aplikacji
    [[noreturn]] void runApp();
private:
    int userChoice = 0;
    double lastSortingTime = 0;
    T* unsortedList = nullptr;
    T* sortedList = nullptr;
    int sortedListSize=0;
    int unsortedListSize = 0;
    bool presentationAfterSorting = true;

    void getUserChoice();
    void showUnsortedTable() const;
    void showSortedTable() const;
    void showSortingTime() const;
    void copyUnsortedToSorted();
    void turnOnOffPresentation();
    void sortingAutomation();

    static void showMenu();
    static void showSortingMenu();
    static void showGenerationMenu();
    static void showQuickSortMenu();
    static void showShellSortMenu();
};

#include "SortingApp.tpp"
#endif //SORTINGAPP_H
