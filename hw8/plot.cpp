/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project
*/

#include <iostream>
#include <fstream>


void loadplot(string){
  ifstream datafile;
  datafile.open(filename.c_str());
  char data [101];
  datafile.getline(data, 100);

  for(int i =0; i<10;i++){ //expand in such a way to fill array
    for (int j = 0; j < 10; j++){ 
      // get data from file and set up grid which I haven't made yet.
    }
  }

}
//only grass is passible - since its hard to walk through trees and bushes
int Plot::passableEW(){

}
int Plott::passableNS(){

}
void Plot::transpose(){

}
void Plot::save(string name){

}
void Plot::load(string name){

}
void Plot::print_terrain(){

}
void Plot::print_square(){

}
void Plot::edit_square(){

}