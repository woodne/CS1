/*
  Josh Hartshorn
  CS120 Homework 5
  March 1st 2013

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
  string name;
public:
  pet(); // constructor
  void play();
  void feed();
  void print();
  int check_health();
};
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
  cout << " Fetch (1) \n Roll over (2) \n";
  cin >> choice;
  switch(choice){
    case(1):
      happy += 10;
      hunger += 1;
      break;
    case(2):
      happy += 5;
      hunger += 1;
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
  case 1:
    pet1.play();
    break;
  case 2:
    pet1.feed();
    break;
  }
  health_check = pet1.check_health();
  }while(choice != 0 && health_check != 1);
  cin.ignore();
  cout << "Press enter to exit." << endl;
  cin.ignore();
  return 0;
}