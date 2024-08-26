#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ofstream inputFile("input.txt");
  inputFile << "hello world" << endl;
  inputFile << "I am here to help" << endl;
  inputFile.close();
  string filename;
  cout << "Enter file name:";
  cin >> filename;
  ofstream outputFile(filename);
  ifstream readFile("input.txt");
  string line;

  while (getline(readFile, line))
  {
    outputFile << line << endl;
  };
  inputFile.close();
  outputFile.close();
  return 0;
}
