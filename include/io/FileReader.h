#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

using namespace std;

class FileReader {
public:   //struktura klasy wczytującej plik
  static string askForFilename();

  template<typename T>
  static void readFile(T*& unsortedList, int& arraySize);
  static void saveToCSV(std::vector<double> result, string filename);
};

#include "FileReader.tpp"
#endif //FILEREADER_H
