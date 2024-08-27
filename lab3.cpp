#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ofstream inputFile("empty.txt");
  string W1,W2;
  cout<<"Enter Wrd 1:";
  cin>>W1;
  cout<<endl;
  cout<<"Enter Wrd 2:";
  cin>>W2;
  cout<<endl;
  inputFile << W1 << ", ";
  inputFile << W2 << endl;
  inputFile.close();
  return 0;
}
