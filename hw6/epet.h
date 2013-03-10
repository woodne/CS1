/*
  Josh Hartshorn
  CS120 Homework 6
  March 3rd 2013

  Pet Assignment - Classes, Strings, and Files
*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//declaration of the pet class
class pet{
  private:
    int hunger;
    int happy;
    int hygiene;
    string name;
  public:
    pet(); // constructor
    void play();
    void feed();
    void print();
    void clean();
    int check_health();
    void save_game();
};