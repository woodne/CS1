#include<iostream>
#include<cstdlib>
using namespace std;
#include"robot.h"

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
        y--;
    if(direction == 2)
        y++;
    if(direction == 1)
        x++;
    if(direction == 3)
        x--;
    }

robot::robot(int id){
    energy = 50;
    ID = id;
    moved = 0;
    direction = 0;
}
void robot::energy_drain(){
  cout << "Difficult Terrain. Robot #" << ID << " lost 10 Energy." << endl;
  energy-=10;
}
void robot::energy_boost(){
  cout << "Robot #" << ID <<" found an energy boost!" << endl;
  energy+=10;
}

void robot::draw(){
    cout << "#";
}

void robot::print(){
    cout<<"Robot "<<ID<<": Energy = "<<energy<< " Direction = "<<direction;
}

void robot::move(int &x,int &y){
  if (energy > 0){
    if(moved == 1)
        return;
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
  else{
    energy = 0;
    cout << "Robot #" << ID << " is out of energy!!" << endl;
  }
  moved = 1;
}
