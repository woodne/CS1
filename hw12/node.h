class node{ 
  private:
    node *next;
    robot *data; 
  public:
    node(); 
    void set_next(node *n) {next = n;} 
    void set_data(robot *d) {data = d;} 
    node *get_next() {return next;} 
    robot *get_data() {return data;} 
    void print(); 
    void turnLeft(); 
    int remove(int); 
    void remove_data() {delete data;}
};