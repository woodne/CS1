/* Josh Hartshorn
   Lab 7 March 1st 2013
   CS120

   This program works with text files looking for certain text phrases among various other things.
    -Finished all requirements
*/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  string line;
  ifstream dataFile;
  int line_number = 1;
  int substring_count = 0;
  string word = "int ";
  dataFile.open("datafile.txt");
  if(dataFile.is_open()){
    while(dataFile.good()){
      getline (dataFile,line);
      cout << "\nLine# " << line_number << " :: ";
      cout << "Line Length: " << line.length() << endl;;
      unsigned found = line.find(word); // if no matches it returns npos (-1)
      if(found!=string::npos){ //checks for npos, if none it found a match
        cout << "\t\"" << word << "\"" <<" found on line: " << line_number << endl;
        cout << "\t\tCharacter After Substring: " << line[found + 4] << endl;
        substring_count++;
      }
      line_number++; //increment line number
    }
    dataFile.close();
    cout << "\n Total lines with substring: " << substring_count << endl;
  }
  return 0;
}