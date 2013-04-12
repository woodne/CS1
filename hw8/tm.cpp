/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project
*/

//save and load files
#include <iostream>
#include "plot.h"

using namespace std;

int main() {
  //create plot object
  Plot p;
  string s = "turnip.dat";
  p.loadplot(s);
  cout << "\nTerrain:\n";
  p.print_terrain_map();
  cout << "\nElevation:\n";
  p.print_elevation_map();
  cout << "\n Minimum! \n";
  p.minimum();
  cout << "\n Maximum! \n";
  p.maximum();
  cout << endl;
  int f = p.passable();
  cout << endl << f << endl;
  int a, b;



  //cout << "Do you want to view a squares attributes? Enter the coordinates!\n";
  //cin >> a >> b;
  //p.print_square(a,b);

  //cout << "Do you want to change a squares attributes? Enter the coordinates!\n";
  //cin >> a >> b;
  //p.edit_square(a,b);

  //user must print individual square elevation (like grid 2-2)
  //user needs to print 10x10 grid of elevations
  //user needs to print 10x10 grid of terrain (GBT)
  //user needs to request the minimum and maximum elevation
  //identify file that needs loading and then read it

  return 0;
}
