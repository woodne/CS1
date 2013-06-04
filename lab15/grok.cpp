#include <iostream>
using namespace std;
int binary_search(string *A[], int key, int imin, int imax);
int main()
{
    string sarray[] = {
       "Execution Monitoring",
	"Debugging",
	"Social Networking",
	"Programming Environments",
	"Artificial Intelligence",
	"Operating Systems",
	"Programming Languages",
	"Programming Languages",
	"Programming Languages",
	"Programming Languages",
	"Programming Languages",
	"Programming Languages",
	"Artificial Intelligence",
	"Object-Orientation",
	"Ada",
	"Ada",
	"Algol",
	"Algol",
	"Algol",
	"Alphard",
	"Alice",
	"Assembler",
	"Assembler",
	"BASIC",
	"BASIC",
	"BASIC",
	"BASIC",
	"C++",
	"C++",
	"C++",
	"C++"
       };
    string *sparray[31] = {
	sarray+14, sarray+15,
	sarray+16, sarray+17, sarray+18,
	sarray+19, sarray+20,
	sarray+4, sarray+12,
	sarray+21, sarray+22,
	sarray+23, sarray+24,
	sarray+25, sarray+26,
	sarray+27, sarray+28,
	sarray+29, sarray+30,
	sarray+1,  sarray+0,
	sarray+13, sarray+5,
	sarray+3,
	sarray+6,  sarray+7,
	sarray+8,  sarray+9,
	sarray+10,  sarray+11,
	sarray+2
       };
   cout << "Ensure they are actually sorted:" << endl;
   for(int i=0; i<31; i++) {
      cout << *(sparray[i]) << endl;
      }
   // now, uncomment to binary search for "BASIC"
   // int idx = binary_search(sparray, "BASIC", 0, 31);
   // cout << "First index of BASIC is :" << idx << endl;
   return 0;
}
