#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

using namespace std;

class FileReader {
public:
  static string askForFilename();

  template<typename T>
  static void readFile(T*& unsortedList, int& arraySize);
};

#include "FileReader.tpp"
#endif //FILEREADER_H
