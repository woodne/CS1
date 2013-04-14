#ifndef SOI_H
#define SOI_H

class SetOfIntegers {
public:
  SetOfIntegers(); // constructor
  int size();      // number of members in the set
  int insert(int); // return 1 if successful, 0 if already in it, or if full
  int remove(int); // return 1 if successful, 0 if not in it
  int is_member(int);
  void print();
private:
  int members[10];
  int num;
};

#endif
