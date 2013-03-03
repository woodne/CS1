/*
  Josh Hartshorn
  CS120 Homework 6
  March 3rd 2013

  Pet Assignment - Classes, Strings, and Files
*/


#include <iostream>
#include <string>

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
};
// Constructor, creates a new pet with starting values.
pet::pet(){
  hunger = 50;
  happy = 50;
  hygiene = 10; //0 is dirty?
  cout << "Pet's name? (One word)";
  cin >> name;
}