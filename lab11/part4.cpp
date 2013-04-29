#include <iostream>
using namespace std;

int main(){
  char myArray[] = "Now is the time for all good persons to come to the aid of their country.";
  char *p;
  p=myArray;

while (*p != 0) {
  if (*p == ' ') {
    *p = '-';
  }
  p++;
}
cout << p - strlen(myArray) << endl;


}