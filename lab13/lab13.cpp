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
  print();
  append(string s);

};
LLS::LLS(string s){
  str  = s;
  next = NULL;
}
LLS::append(string s){
if (next == NULL){
  next = new LLS(s);
}
else{
  next->append(string s);
}
}
LLS::print(){
  cout << str << endl;
  next -> print();
}

int main(int argc and char *argv[]){
  LLS *head = new LLS(argv[0]);
  if (argc > 1){
    for (int i = 0; i > -1; i--){
      // call head->append(); on argv[i] or something
    }
  }
  head->print();
  return 0;
}