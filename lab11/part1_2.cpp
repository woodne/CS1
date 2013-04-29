/* Josh Hartshorn
   Lab 11
   Using Pointers
   Part 1 & 2
*/

#include <iostream>

using namespace std;

void divmod(int num, int denom, int *quotient, int *remainder){

*quotient = num/denom;
*remainder = num%denom;

}

int main(){
  int quotient = 0;
  int remainder = 0;
  divmod(1540,7,&quotient,&remainder);
  cout << "Quotient = " << quotient << endl << "Remainder = " << remainder
       << endl;

  return 0;
}