/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project

 * plot.h - recommended plot class for Assignment8
 * you may modify as needed, but stay "compatible" if possible
 * Modified by: _____Josh________ (insert your name)
*/
#include "square.h"
#include <string>

class Plot {
  private:
    //define plot things
    Square grid[10][10]; //this will contain objects which contain elevation and ground details
    int passableEW();
    int passableNS();
    void transpose();
  public:
    //assignment defines things that need to be accessible from userspace - so look there!
    void save(string name);
    void load(string name);
    void print_terrain_map();
    void print_elevation_map();
    void print_square(int a, int b);
    void edit_square(int a, int b);
    void loadplot(string);
    void minimum(); // lowest elevation in plot of land
    void maximum(); // highest elevation in plot of land
    void steepest(); // largest dfiferent in elevation for adjacent square meters
    int passable(); // not sure

};
