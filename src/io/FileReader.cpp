#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>

void FileReader::readFile(std::vector <int>& unsortedList) {
    unsortedList.clear();
    ifstream file(askForFilename());
    if (!file) {
        cout << "File cannot be opened" << endl;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) {
        unsortedList.push_back(stoi(line));
    }

    cout << "All numbers ("<<unsortedList.size() <<") added successfully.\n \n";
}

string FileReader::askForFilename() {
    cout << "Please enter the file name: \n";
    string fileName;
    cin >> fileName;
    return fileName;
}


