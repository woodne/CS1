#include<iostream>
#include<cstdlib>
using namespace std;

#include"robot.h"

const int HEIGHT = 10;
const int WIDTH = 10;

void robot::turnLeft(){
    energy--;
    direction = (direction + 3) % 4; // a left is 3 rights
}

void robot::turnRight(){
    energy--;
    direction = (direction + 1) % 4;
}

void robot::forward(int &x,int &y){
    energy -= 2;
    if(direction == 0)
      if(y > 0)y--;
    if(direction == 2)
      if (y < HEIGHT) y++;
    if(direction == 1)
      if (x < WIDTH) x++;
    if(direction == 3)
      if (x > 0) x--;
    }

robot::robot(int id){
    energy = 50;
    ID = id;
    moved = 0;
    direction = 0;
    player = 0;
}
void robot::energy_drain(){
  cout << "Robot #" << ID << " lost 10 Energy." << endl;
  energy-=10;
}
void robot::energy_boost(){
  cout << "Robot #" << ID <<" found an energy boost!" << endl;
  energy+=10;
}
void robot::player_controlled(){
  player = 1;
}

void robot::draw(){
    if(player==1){
      if (direction == 0){
        cout << "Λ";
      }
      if (direction == 2){
        cout << "V";
      }
      if (direction == 1){
        cout << ">";
      }
      if (direction == 3){
        cout << "<";
      }
    }
    else{
      cout << "#";
    }
}

void robot::print(){
    cout<<"Robot "<<ID<<": Energy = "<<energy<< " Direction = "<<direction
          << " Player: " << player << endl;
}

void robot::move(int &x,int &y){
  if (energy > 0){
    if(player == 1 && moved == 0){
      //if player is 1 then ask player if he wants to move in whichever direction. then do.
      cout << "It is your move. Press 0 to turn right, 1 to turn left, and 2 to move forward." <<endl;
      int choice;
      cin >> choice;
      switch(choice){
        case 0:
          forward(x,y);
          break;
        case 1:
          turnLeft();
          break;
        case 2:
          turnRight();
          break;
      }
    }
  else{
    if(player!=1 && moved == 0){
    switch(rand()%4){
      case 0:
         turnLeft();
         break;
      case 1:
         turnRight();
         break;
      case 2:
      case 3:
         forward(x,y);
         break;
      default:
         cout << "Error in robot move." << endl;
     }
  }
 }
  }else{
    energy = 0;
    cout << "Robot #" << ID << " is out of energy!!" << endl;
  }
  moved = 1;
}


