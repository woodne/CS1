/*
  Josh Hartshorn
  CS120 Homework 5
  March 1st 2013

  Pet Assignment - Classes, Strings, and Files
  Change 1, 2,  complete
*/

#include <iostream>
#include <string>
#include "epet.h"

using namespace std;
// Constructor, creates a new pet with starting values.
pet::pet(){
  hunger = 50;
  happy = 50;
  cout << "Pet's name? (One word)";
  cin >> name;
}
//member function for playing with pet
void pet::play(){
  int choice = 0;
  cout << "What should we play?\n";
  cout << " Fetch (1) \n Roll over (2) \n Dance (3) \n Sing (4) \n Attack (5) \n";
  cin >> choice;
  switch(choice){
    case(1):
      happy += 10;
      hunger += 1;
      cout << "\nYour pet caught the ball! Yay!\n"
      break;
    case(2):
      happy += 5;
      hunger += 1;
      cout << "\nYour pet rolls over.\n";
      break;
    case(3):
      happy += 5;
      hunger += 2;
      cout << "\nYour pet begins to dance!!! Amazing!\n";
      break;
    case(4):
      happy += 2;
      hunger += 1;
      cout << "\nRARGGLGLLRBARKRKKCLUCKCLUCK\n";
      break;
    default:
      cout << "Not a valid choice." << endl;
  }
}
//member function for feeding
void pet::feed(){
  cout << "\nMMMM, Yummy!\n";
  hunger -=5;
}
void pet::print(){
  cout << "\nYour pet " << name << " is " << endl;
  cout << "Happy: " << happy << endl;
  cout << "Hungry: " << hunger << endl;
}
//member function check health
int pet::check_health(){
  if(hunger >= 100){
    cout << "\nYour pet has starved.\n";
    return 1;
  }
  if(happy <= 0){
    cout << "\nYour pet has died of a broken hearth.\n";
    return 1;
  }
  return 0;
}

int main(){
  pet pet1;
  int choice;
  int health_check;
  do{
    pet1.print();
    cout << "What would you like to do with your pet?\n";
    cout << " Play (1) \n Feed (2) \n Exit (0) \n";
    cin >> choice;

    switch(choice){
      case 0:
        break;
      case 1:
        pet1.play();
        break;
      case 2:
        pet1.feed();
        break;
      default:
        cout << "Not a valid choice." << endl;
  }
  health_check = pet1.check_health();
  }while(choice != 0 && health_check != 1);
  cin.ignore();
  cout << "Press enter to exit." << endl;
  cin.ignore();
  return 0;
}