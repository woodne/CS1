#include "linkedlist.h"

linkedlist::linkedlist(){
  head = NULL;
  count = 0;
}
void linkedlist::insert(robot *rp){
  node *n;
  n = new node;
  n->set_data(rp);
  n->set_next(head);
  head = n;
  count++;
}
void linkedlist::remove(int n){
  if(head == NULL)
    return;
  if((head->get_data())->getID()==n){
    node *temp;
    temp = head;
    head = head->get_next();
    temp -> remove_data();
    delete temp;
    count--;
  }
  else{
    if(head->remove(n) == 1)
      count--;
  }
}
void linkedlist::print(){
    std::cout << "There are " << count;
    std::cout << " robots in the list: \n";
  if(head !=NULL)
    head->turnLeft();
}

void linkedlist::turnLeft() {
    // You were missing this
}
