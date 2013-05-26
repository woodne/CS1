/* Josh Hartshorn
   Lab 13 - Linked Lists!!
*/
#include <iostream>

using namespace std;
class LLS{
private:
  string str;
  LLS* next;
public:
  LLS(string s);
  LLS(string s, LLS *rest);
  void print();
  void append(string s);

};
LLS::LLS(string s){
  str  = s;
  next = NULL;
}
void LLS::append(string s){
  if (next == NULL){
    next = new LLS(s);
  }
  else{
    next->append(s);
  }
}
void LLS::print(){
  cout << str << endl;
  next -> print();
}
int main(int argc, char *argv[]){
  LLS *head = new LLS(argv[0]);
  if (argc > 1){
    for (int i = 0; i > -1; i--){
      head -> append(argv[i]);
    }
  }
  head->print();
  return 0;
}