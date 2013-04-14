#include <iostream>
using namespace std;
#include "soi.h"

SetOfIntegers::SetOfIntegers()
{
   num = 0; // initialize to the empty set
}

int SetOfIntegers::size()
{
   return num;
}

int SetOfIntegers::insert(int x)
{
   int i;
   for (i = 0; i < num; i++) {
      if (x == members[i]) return 0;
      }
   if (i == 10) {
      return 0;
      }
   members[num++] = x;
   return 1;
}

int SetOfIntegers::remove(int x)
{
   for (int i = 0; i < num; i++) {
      if (x == members[i]) {
         for (int j = i; j < num-1; j++)
	    members[j] = members[j+1];
	 num--;
         return 1;
         }
      }
   return 0;
}

int SetOfIntegers::is_member(int x)
{
   for (int i = 0; i < num; i++) {
      if (x == members[i]) return 1;
      }
   return 0;
}

void SetOfIntegers::print() {
   cout << '{';
   for (int i = 0; i < num; i++) {
      cout << members[i];
      if (i < num-1) cout << ",";
      }
   cout << '}';
}
