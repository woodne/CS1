#ifndef NODE_H
#include "node.h"
#endif
#include <cstdio>
#include <iostream>
class linkedlist{ private:
  int count;
  node *head; 
  public:
    linkedlist(); 
    void insert(robot *); 
    void print(); 
    void turnLeft(); 
    void remove(int);
};