/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project

   Make a menu and clean up output. Also, check diagonals in passable()
*/

//save and load files
#include <iostream>
#include "plot.h"

using namespace std;

int main() {
  //create plot object
  Plot p;
  string s;
  cout << "Enter the name of datafile you want to load: ";
  cin >> s;
  p.load(s);
  int choice;

  bool quit = false;
  while(!quit){
    cout << "This is a primitive Terrain Manager." << endl;
    cout << "Menu:" << endl;
    cout << "\tEnter (1) to view the Height Map" << endl;
    cout << "\tEnter (2) to view the Terrain Map" << endl; 
    cout << "\tEnter (3) for maximum plot height" << endl;
    cout << "\tEnter (4) for minimum plot height" << endl;
    cout << "\tEnter (5) to determine if terrain is passable" << endl;
    cout << "\tEnter (10) to quit" << endl;
    cin >> choice;
    switch(choice){
      case 1: cout << "\nHeight Map:\n"; p.print_elevation_map(); 
              break;
      case 2: cout << "\nTerrain Map:\n"; p.print_terrain_map(); 
              break;
      case 3: cout << "\nMaximum:\n \t"; p.maximum(); 
              break;
      case 4: cout << "\nMinimum:\n \t"; p.minimum(); 
              break;
      case 5: int f = p.passable();
              cout << "\nPassable:\n \t" << f << endl; 
              break;
      case 10: quit = true;
      
    }
  }
  int a, b;

  int steepest = p.steepest(2,1);
  cout << "Steepest: " << steepest << endl;
  p.save("test");

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
