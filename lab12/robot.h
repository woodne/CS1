class robot{
  private:
    int direction;
        int ID;
    int moved;
    int player;
    void turnLeft(); // a private function
    void turnRight(); // a private function
    void forward(int &, int &); // a private function
  public:
    robot(int);
    int energy;
    int get_player(){return player;};
    void player_controlled();
    void refresh() {moved = 0;} // an in-line function
    void draw();
    void print();
    void movetoward(int &, int &, int, int); // pass-by-reference arguments
    void move(int &, int &);
    void energy_drain();
    void energy_boost();
};
