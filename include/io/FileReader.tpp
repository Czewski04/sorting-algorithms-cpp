#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>

template <typename T>
void FileReader::readFile(T*& unsortedList, int& arraySize) {
    delete[] unsortedList;
    ifstream file(askForFilename());
    if (!file) {
        cout << "File cannot be opened" << endl;
    }

    string line;
    getline(file, line);
    arraySize = stoi(line);
    unsortedList = new T[arraySize];

    if(is_same<T, int>::value){
        for(int i=0; i<arraySize; i++){
            getline(file,line);
            unsortedList[i]= stoi(line);
        }
    }
    else if(is_same<T,float>::value){
        for(int i=0; i<arraySize; i++){
            getline(file,line);
            unsortedList[i]= stof(line);
        }
    }

    cout << "All numbers ("<<arraySize <<") added successfully.\n \n";
}

string FileReader::askForFilename() {
    cout << "Please enter the file name: \n";
    string fileName;
    cin >> fileName;
    return fileName;
}