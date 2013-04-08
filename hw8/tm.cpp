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

  //user must print individual square height (like grid 2-2)
  //user needs to print 10x10 grid of elevations
  //user needs to print 10x10 grid of terrain (GBT)
  //user needs to request the minimum and maximum elevation
  //identify file that needs loading and then read it

  return 0;
}