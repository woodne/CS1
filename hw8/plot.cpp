/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project
*/

#include <iostream>
#include <fstream>
#include "plot.h"
#include <iomanip>

using namespace std;

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
void Plot::print_square(){

}
void Plot::edit_square(){

}