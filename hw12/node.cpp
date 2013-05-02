#include "node.h"
#include <iostream>
#include "robot.h"
using namespace std;

node::node(){ // constructor
  next = NULL; 
  data = NULL;
} 
void node::print(){
  data->print(); 
  cout << endl; 
  if(next != NULL)
    next -> print();
} 
void node::turnLeft(){
  data -> turnLeft(); 
  if(next != NULL)
    next -> turnLeft(); 
  data -> print();
  cout << endl;
} 
int node::remove(int n){
  if((next -> data) -> getID() == n){ //found the right id
    node *temp;
    temp = next;
    next = next->next;
    temp->remove_data();
    delete temp;
    return(1);
  }
  else{
    return(next->remove(n)); //try the next node
  }
  return 0; //given robot was never found
}