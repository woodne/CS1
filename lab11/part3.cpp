#include <iostream>
using namespace std;

void swap(double *x, double *y)
{
   double tmp;
   tmp = *x;
   *x = *y;
   *y = tmp;
}
int main()
{
   double ee=3.14159;
   double pi=2.7182;
   swap(&ee,&pi);
   cout << "e is " << ee << ", and pi is " << pi << endl;
}