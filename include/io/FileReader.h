#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

using namespace std;

class FileReader {
public:
  static string askForFilename();
  static void readFile(std::vector <int>& unsortedList);
};

#endif //FILEREADER_H
