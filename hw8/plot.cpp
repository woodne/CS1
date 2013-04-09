/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project
*/

#include <iostream>
#include <fstream>
#include "plot.h"
#include "string"
#include <algorithm>

using namespace std;

//global
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
void Plot::loadplot(string filename){
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
//only grass is passible - since its hard to walk through trees and bushes
int Plot::passableEW()
{

}
int Plot::passableNS(){

}
void Plot::save(string name){
//save to file
}
void Plot::load(string name){
//load from file
}
void Plot::print_terrain_map(){
  int track = 0;
  for (int i=0;i<10;i++) {
    for (int j=0; j<10; j++) {
      track++;
      cout << grid[i][j].get_groundcover();
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
      cout << grid[i][j].get_elevation();
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