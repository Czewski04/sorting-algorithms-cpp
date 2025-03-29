#include "SortingApp.h"

int main() {
    int choice;
    SortingApp<int>* appInt = nullptr;
    SortingApp<float>* appFloat = nullptr;
    std::cout<<"Choose data type:\n"
               "1. int\n"
               "2. float\n";
    std::cin>>choice;
    if(choice==1){
        appInt = new SortingApp<int>();
        appInt->runApp();
    }
    else if(choice==2) {
        appFloat = new SortingApp<float>();
        appFloat->runApp();
    }
    return 0;
}
