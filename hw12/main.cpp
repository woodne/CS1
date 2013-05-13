/*Josh Hartshorn
  CS120
  Homework 12

*/

#include <iostream>
#include <cstdlib>

using namespace std;

#include "node.h"
#include "robot.h"
#include "linkedlist.h"

int main(){
  linkedlist ll;
  const int num_robots = 3;
  robot *robot_ptr;
  for (int i = 0; i < num_robots; i++){
    robot_ptr = new robot(i);
    ll.insert(robot_ptr);
  }
  ll.print();
  cout <<"Turn all robots left:"<<endl;
  ll.turnLeft();
  robot_ptr = new robot(99);
  ll.insert(robot_ptr);
  ll.remove(2);
  ll.print();
  return 0;
}
