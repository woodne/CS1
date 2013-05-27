/* Josh Hartshorn
   CS120 Lab 14

   Greatest Common Divisor Lab
*/

#include <iostream>
using namespace std;

int gcd(int a, int b){
  //this function will calculate the greatest common divisor of two positive integers using recursion
  if (b == 0){
    return a;
  }
  else{ 
    return gcd(b,a%b);
  }
}

int main(int argc, int argv[]){
  //main should take two command line arguments (the two integers)
  cout << gcd(argv[2],argv[3]) << endl;

  return 0;
}