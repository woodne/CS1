#include <iostream>
#include <cstdlib>

using namespace std;

#include "node.h"
#include "robot.h"
#include "linkedlist.h"

int main(){
  linkedlist 11;
  const int num_robots = 3;
  robot *robot_ptr;
  for (int i = 0; i < num_robots; i++){
    robot_ptr = new robot(i);
    11.insert(robot_ptr);
  }
  11.print();
  cout <<"Turn all robots left:"<<endl;
  11.turnLeft();
  robot_ptr = new robot(99);
  11.insert(robot_ptr);
  11.remove(2);
  11.print();
  return 0;
}