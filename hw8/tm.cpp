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
  int f;

  bool quit = false;
  while(!quit){
    cout << "This is a primitive Terrain Manager." << endl;
    cout << "Menu:" << endl;
    cout << "\tEnter (1) to view the Height Map" << endl;
    cout << "\tEnter (2) to view the Terrain Map" << endl; 
    cout << "\tEnter (3) for maximum plot height" << endl;
    cout << "\tEnter (4) for minimum plot height" << endl;
    cout << "\tEnter (5) to determine if terrain is passable" << endl;
    cout << "\tEnter (6) to find the steepness around coordinates "
         << "of your choice." << endl;
    cout << "\tEnter (7) to -view- a square. Format Y axis then X axis" << endl;
    cout << "\tEnter (8) to -edit- a square. Format Y axis then X axis" << endl;
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
      case 5: f = p.passable();
              cout << "\nPassable:\n \t" << f << endl; 
              break;
      case 6:{
        int a, b;
        cout << "Enter the coordinates: ";
        cin >> a >> b;
        int steepest = p.steepest(a, b);
        cout << "\n Steepest: " << steepest << endl;
        break;
      }
      case 7:{
        int a, b;
        cout << "Enter the coordinates of the square you want to view: ";
        cin >> a >> b;
        cout << endl;
        p.print_square(a,b);
        break;
      }
      case 8:{
        int a, b;
        cout << "Enter the coordinates of the square you want to edit: ";
        cin >> a >> b;
        cout << endl;
        p.edit_square(a,b);
        break;
      }
      case 10: {
        cout << "Do you want to save? Press 9 to save." << endl;
        int save;
        cin >> save;
        if (save == 9){
          cout << "Enter the filename: ";
          string file;
          cin >> file;
          p.save(file);
        }
        quit = true; 
      } 
    }
  }
  p.save("test");

  return 0;
}
