#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#include"world.h"


int main(){
  world a_world;
  srand(time(NULL));
  a_world.set_up();
  do{
     a_world.update();
     a_world.draw();
     cin.ignore();
  }while(1);
  return 0;
}
