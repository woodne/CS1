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
    return (b,a%b);
  }
  
  return 0;
}

int main(){
  //main should take two command line arguments (the two integers)
  int a = 10;
  int b = 20;
  cout << gcd(a,b) << endl;

  return 0;
}