//declaration of the pet class
class pet{
  private:
    int hunger;
    int happy;
    string name;
  public:
    pet(); // constructor
    void play();
    void feed();
    void print();
    int check_health();
};