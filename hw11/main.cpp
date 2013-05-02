#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#ifndef _world
#include"world.h"
#endif

int main(){
  world a_world;
  srand(time(NULL));
  a_world.set_up();
  a_world.draw();
  do{
     a_world.update();
     a_world.draw();
     cin.ignore();
  }while(1);
  return 0;
}
