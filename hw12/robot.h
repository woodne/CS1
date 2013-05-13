#ifndef ROBOT_H
#define ROBOT_H

class robot{
  private:
    int direction;
    int energy;
    int ID;
    int moved;
    int player;
    void turnRight(); // a private function
    void forward(int &, int &); // a private function
  public:
    robot(int);
    void turnLeft();
    void player_controlled();
    void refresh() {moved = 0;} // an in-line function
    void draw();
    void print();
    void move(int &, int &); // pass-by-reference arguments
    void energy_drain();
    void energy_boost();
    int getID() {return ID;}
};

#endif
