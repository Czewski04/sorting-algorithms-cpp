#include <algorithm>

#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>

template <typename T>   //funkcja wczytująca plik danych
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


void FileReader::saveToCSV(std::vector<double> results, string filename) {
    std::ofstream file;
    string doubleTxt = "";

    bool fileExists = std::filesystem::exists(filename);

    file.open(filename, std::ios::app);

    if (!file.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku: " + filename);
    }

    if (!fileExists) {
        file << "Insert; QS pivot left; QS pivot right; QS pivot middle; QS pivot random; Heap; ShellBasic; ShellKnuth;\n";
    }

    for (double result:results) {
        doubleTxt = to_string(result);
        std::replace(doubleTxt.begin(), doubleTxt.end(), '.', ',');
        file << doubleTxt << "; ";
    }

    file << "\n";

    file.close();
}

string FileReader::askForFilename() {   //funkcja wczytująca ścierzkę do pliku
    cout << "Please enter the file name: \n";
    string fileName;
    cin >> fileName;
    return fileName;
}