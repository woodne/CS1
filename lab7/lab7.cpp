/* Josh Hartshorn
   Lab 7 March 1st 2013
   CS120

   This program works with text files looking for certain text phrases among various other things.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm> //std::search

using namespace std;

int main(){
  string line;
  ifstream dataFile;
  int line_number = 0;
  string word = "int ";
  dataFile.open("datafile.txt");
  if(dataFile.is_open()){
    while(dataFile.good()){
      getline (dataFile,line);
      cout << "\nLine# " << line_number << " :: ";
      cout << "Line Length: " << line.length() << " :: ";
      unsigned found = line.find(word); // if no matches it returns npos (-1)
      if(found!=string::npos){ //checks for npos, if none it found a match
        cout << "\"" << word << "\"" <<" found on line: " << line_number << endl;
      }
      line_number++; //increment line number
    }
    dataFile.close();
  }
  return 0;
}