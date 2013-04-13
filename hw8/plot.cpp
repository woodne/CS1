/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project
*/

#include <iostream>
#include <fstream>
#include "plot.h"
#include "string"
#include <algorithm>
#include <iomanip>

using namespace std;

int Plot::steepest(int b, int a){

  if (a >= 0 && a < 10 && b >= 0 && b < 10){
    double minimum = grid[a-1][b-1].get_elevation();
    double maximum = grid[a-1][b-1].get_elevation();
    for (int i=0;i<3;i++) {
      for (int j=0; j<3; j++) {
        cout << "line: " << a-1+i << "column" << b-1+j << endl;
        if (grid[(a-1)+i][(b-1)+j].get_elevation() < minimum){
          minimum = grid[(a-1)+i][(b-1)+j].get_elevation();
        }
        if (grid[(a-1)+i][(b-1)+j].get_elevation() > maximum){
          maximum = grid[(a-1)+i][(b-1)+j].get_elevation();
        }
      }
    }
    return maximum - minimum;
  }
}


void Plot::minimum(){
  double minimum = grid[0][0].get_elevation();
  for (int i=0;i<10;i++) {
    for (int j=0; j<10; j++) {
      if (grid[i][j].get_elevation() < minimum){
        minimum = grid[i][j].get_elevation();
      }
    }
  }
  cout << minimum << endl;
}
void Plot::maximum(){
  double maximum = grid[0][0].get_elevation();
  for (int i=0;i<10;i++) {
    for (int j=0; j<10; j++) {
      if (grid[i][j].get_elevation() > maximum){
        maximum = grid[i][j].get_elevation();
      }
    }
  }
  cout << maximum << endl;
}
void Plot::load(string filename){
  ifstream datafile;
  datafile.open(filename.c_str());
  char data [101];
  datafile.getline(data, 100);

  for(int i =0; i<10;i++){
    for (int j = 0; j < 10; j++){ 
      double d; char c1, c2, gc;
      datafile >> d; //elevation
      datafile >> c1;
      datafile >> gc; //groundcover
      datafile >> c2;
      grid[i][j].set(d, gc);
    }
  }

}
//creates a temp square object in order to reverse order
void Plot::transpose()
{
   for (int i=1;i<10;i++) {
     for (int j=0; j<i; j++) {
       Square temp;
       temp = grid[i][j];
       grid[i][j] = grid[j][i];
       grid[j][i] = temp;
     }
   }
}

int Plot::passable(){
  return passableEW() && passableNS();
}
int Plot::passableEW()
{
//only grass is passable, so only need to check for 'G'
int depth = 0; //reached end
int line = 0; //line number
int found = 0;
int depth_check = 0;
int line_check = 0;
//check for passable terrain on edge
for(line=0;line<10;line++){
  line_check++;
  cout << "Line: " << line << endl;
  if (grid[line][0].get_groundcover() == 'G'){
    found=0;
    depth_check=0;
    for(depth = 0; depth < 10; depth++){
      if (grid[line][depth].get_groundcover()== 'G'){
        found++;
	depth_check++;
        cout << " Line: " << line << " Depth: " << depth_check << " Found Grass: " << found << endl;
      }
      else{
	cout << "\nSomething blocks our path!!" << endl;
        break;
      }
    }
    if (found >= 10){
      cout << "\n We have a row!!" << endl;
      return true;
    }
    if (depth_check >= 9){
      cout << "\n We do not have a row!" << endl;
      return false;
    }
  }
}
  if (line_check >= 9){
    return false;
  }
}

int Plot::passableNS(){
//top to bottom
  transpose();
  int reverse = passableEW();
  transpose();
  return reverse;
}
void Plot::save(string name){
  int counter=0;
  ofstream datafile;
  datafile.open(name.c_str());
  datafile << name << endl;
  for(int i =0; i<10;i++){
     for (int j = 0; j < 10; j++){
       datafile << setprecision(2) << setiosflags(ios::showpoint) << grid[i][j].get_elevation();
       datafile << ",";
       datafile << setprecision(2) << setiosflags(ios::showpoint) << grid[i][j].get_groundcover();
       datafile << ",";
       counter++;
       if (counter == 10){
         datafile << endl;
         counter = 0;
       }
     }
  }
  
}
void Plot::print_terrain_map(){
  int track = 0;
  for (int i=0;i<10;i++) {
    for (int j=0; j<10; j++) {
      track++;
      cout << grid[i][j].get_groundcover();
      cout << " ";
      if (track==10){
        cout << endl;
        track = 0;
      }
    }
  }
}
void Plot::print_elevation_map(){
  int track = 0;
  for (int i=0;i<10;i++) {
    for (int j=0; j<10; j++) {
      track++;
      cout << setprecision(2) << setw(2) << grid[i][j].get_elevation();
      cout << " ";
      if (track==10){
        cout << endl;
        track = 0;
      }
    }
  }
}
void Plot::print_square(int a, int b){
  cout << "\nRow:" << a << " Column: " << b << " Elevation\n";
  cout << grid[a][b].get_elevation() << endl;
  cout << "\nRow:" << a << " Column: " << b << " Ground Cover\n";
  cout << grid[a][b].get_groundcover() << endl;  
}
void Plot::edit_square(int a, int b){
  cout << "\nRow:" << a << " Column: " << b << " Elevation\n";
  cout << "\nCurrent values - Elevation: " << grid[a][b].get_elevation()
    << " Ground Cover: " << grid[a][b].get_groundcover() << endl;
  string choice;
  bool sentinal = false;
  cout << "Do you really want to edit this square? (Type \"yes\"" << endl;
  cin >> choice;
  if (choice == "yes"){
    cout << "\nChange the elevation now:";
    double e; char gc;
    cin >> e;
    cout << "\nNow change the groundcover:";
    cin >> gc;
    grid[a][b].set(e, gc);
    cout << "Elevation: " << grid[a][b].get_elevation() << endl;
    cout << "Ground Cover: " << grid[a][b].get_groundcover() << endl;
  }
  else{
  }
}
