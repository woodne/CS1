/*Josh Hartshorn
  CS120 - Lab 8
  
  The 11th element is printing out the SUM, which I declared right after
  declaring the Array itself. So it is likely they are together (at least in)
  my tests.

  Attempting to print out the 10,000th causes a segfault - usually happens
  when trying to access memory that you aren't supposed to access.

*/



#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
  int Array[10];
  int sum = 0;

  cout << "Enter 10 digits to populate the array:" << endl;
  for (int i = 0; i <= 9; i++){
    cin >> Array[i];
  }

  for (int i = 0; i <= 9; i++){
    cout << Array[i] << "\n";
    sum += Array[i];
  }
  int average = sum/10;
  cout << "Sum: " << sum << endl;
  cout << "Average " << average << endl;

  cout << "The 11th element: " << Array[10] << endl;
    //The 11th element prints out the sum, which I declared right after the Array
  //cout << "The 10,000th element " << Array[10000] << endl; 
    //This causes a segfault - usually happens when trying to access memory you cannot
  return 0;
}