/*  Josh Hartshorn
    CS 120, Homework 7
    March 13th, 2013

    Generic Board Game Assignment
    Game instructions completed. Changed board length and range of rolls
*/

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
// Class Prototype -- this will probably need to be moved to a header
class square{
  private:
    int move;
    string message;
    char symbol;
  public:
    square();
    void print();
    int action();
    void set(int,char,string);
};