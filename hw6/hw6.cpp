/*
  Josh Hartshorn
  CS120 Homework 6
  March 3rd 2013

  Pet Assignment - Saving Data to Files - loading data from files.
*/

#include "epet.h"

// Constructor, creates a new pet with starting values.
pet::pet(){
  int choice;
  cout << "Would you like to create(1) a new pet or load(2) an old one?" << endl;
  cin >> choice;
  if (choice == 1){
    hunger = 50;
    happy = 50;
    hygiene = 10; //0 is dirty?
    cout << "Pet's name? (One word)";
    cin >> name;
  }
  else if(choice == 2){
    cout << "Enter the filename" << endl;
    string filename;
    cin >> filename;
    ifstream load;
    load.open (filename.c_str());
    int line = 0;
    while(line < 5) {
      line++;
      cout << line << endl;
      if (line == 1){
        load >> name;
      }
      if (line == 2){
        load >> hunger;
      }
      if (line == 3){
        load >> happy;
      }
      if (line == 4){
        load >> hygiene;
      }
    }
  }
  else{ 
    cout << "invalid input" << endl;
  }
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
      hygiene += -2;
      cout << "\nYour pet caught the ball! Yay!\n";
      break;
    case(2):
      happy += 5;
      hunger += 1;
      hygiene += -2;
      cout << "\nYour pet rolls over.\n";
      break;
    case(3):
      happy += 5;
      hunger += 2;
      hygiene += -2;
      cout << "\nYour pet begins to dance!!! Amazing!\n";
      break;
    case(4):
      happy += 2;
      hunger += 1;
      hygiene += -2;
      cout << "\nRARGGLGLLRBARKRKKCLUCKCLUCK\n";
      break;
    case(5):
      happy += -25;
      hunger += 30;
      hygiene += -10;
      cout << "\nBARKBARKWOOFMEOWSCRATCHCLAW! Your pet attacked another creature!\n";
      break;
    default:
      cout << "Not a valid choice." << endl;
  }
}
//member function for feeding
void pet::feed(){
  int choice = 0;
  cout << "What should we eat?\n";
  cout << " Biscuits (1) \n Rat (2) \n Raccoon (3) \n Chipotle (4) \n";
  cin >> choice;
  switch(choice){
    case(1):
      happy += 5;
      hunger += -5;
      hygiene += -2;
      cout << "\nYour creature eats the biscuit.\n";
      break;
    case(2):
      happy += 5;
      hunger += -10;
      hygiene += -5;
      cout << "\nYour creature ate a rat! Gross!!\n";
      break;
    case (3):
      happy += 10;
      hunger += -20;
      hygiene += -3;
      cout << "\nYour creature ate a Raccoon! Poor furry creature. :(\n";
      break;
    case (4):
      happy += 50;
      hunger += -25;
      hygiene += -10;
      cout << "\nYour creature ate Chipotle! You both will regret it later.\n";
      break;
    default:
      cout << "Not a valid choice. " << endl;
  }
  cout << "\nMMMM, Yummy!\n";
  hunger -=5;
}
void pet::print(){
  cout << "\nYour pet " << name << " is " << endl;
  cout << "Happy: " << happy << endl;
  cout << "Hungry: " << hunger << endl;
  cout << "Hygiene: " << hygiene << endl << endl;;
}
//member function check health
int pet::check_health(){
  if(hunger >= 100){
    cout << "\nYour pet has starved.\n";
    return 1;
  }
  if(happy <= 0){
    cout << "\nYour pet has died of a broken heart.\n";
    return 1;
  }
  if(hygiene <= 0){
    cout << "\nYour pet died from disease.\n";
    return 1;
  }
  return 0;
}
void pet::clean(){
  cout << "Your pet enjoys the water! All clean!" << endl;
  happy += 10;
  hunger += -5;
  hygiene = 100;
}
void pet::save_game(){
  cout << "Please enter a filename" << endl;
  string filename;
  cin >> filename;
  ofstream save;
  save.open (filename.c_str());
  save << name << endl;
  save << happy << endl;
  save << hunger << endl;
  save << hygiene << endl;
  save.close();
}

int main(){
  pet pet1;
  int choice;
  int health_check;
  do{
    pet1.print();
    cout << "What would you like to do with your pet?\n";
    cout << " Play (1) \n Feed (2) \n Clean (3) \n Exit (0) \n";
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
      case 3:
        pet1.clean();
        break;
      default:
        cout << "Not a valid choice." << endl;
  }
  health_check = pet1.check_health();
  }while(choice != 0 && health_check != 1);
  pet1.save_game();
  cin.ignore();
  cout << "Press enter to exit." << endl;
  cin.ignore();
  return 0;
}