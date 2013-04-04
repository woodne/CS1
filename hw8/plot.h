/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project
*/
#include square.h

class Plot {
  private:
    //define plot things
    Square grid[10][10];
    int passableEW();
    int passableNS();
    void transpose();
  public:
    //assignment defines things that need to be accessible from userspace - so look there!
    void save(string name);
    void load(string name);
    void print_terrain();
    void print_square();
    void edit_square();
    void loadplot(string);

};