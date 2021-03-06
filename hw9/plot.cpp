/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project

   I essentially used the passable function provided. I initially thought I only had
   to look at a straight line across the grid. But then when I read the
   assignment before turning it in I saw you wanted diagonals also. This
   Introduced a problem.

   Consider:
   O G G 0 0
   G O O O G
   O G G G O

   The first path will fail, and the second path will be a success. But I
   couldn't think of a good way to keep track of failed paths. This 
   assignment is already several weeks late. So I opted to use your set of 
   integers class and I made a point of learning why it works. Very clever 
   solution by the way!

   I hope I have the chance to take an algorithms class. Interesting stuff. dfs

*/

#include <iostream>
#include <fstream>
#include "plot.h"
#include "string"
#include <algorithm>
#include <iomanip>
#include "soi.h"

using namespace std;
double Plot::mean(){
  double total;
  for (int i=0;i<10;i++) {
    for (int j=0; j<10; j++) {
       total += grid[i][j].get_elevation();
       cout << total<< endl;
    }
  }
  total = total/100;

  return total;
}
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
  // clever solution. thanks for showing it!

  // let s[0] be the set of passable (grass) squares in column 0,
  //      obtained by simply checking each to see if it is 'G'
  SetOfIntegers s[10];
  double prev_height = 0;
  double new_height = 0;
  for(int i=0;i<10;i++)
    if (grid[i][0].get_groundcover() == 'G'){
      prev_height = grid[i][0].get_elevation();
      s[0].insert(i);
    }
  // for each column i in 1 to 9 do, construct s[i] as follows:
  for(int i=1; i<10; i++) {

  //      for each member of s<sub>i-1</sub>
    for(int j=0; j<10; j++) {
      if (s[i-1].is_member(j)) {

  //           check diagonally up and down, and straight across:
	for(int k = j-1; k<=j+1; k++) {
  //		  if 'G' then	  
          if (grid[i][k].get_groundcover() == 'G') {
            //gets the elevation of current square
            new_height = grid[i][k].get_elevation();
  //                 insert into s<sub>i</sub>
	    if (new_height - prev_height <= 2 && new_height - prev_height >= -2){
              s[i].insert(k);
              cout << "Height is within passable range!" << i << " " << k << endl;
              cout << "     prev_height = " << prev_height << " New height was " << new_height << endl;
              //replaces previous height with the current one
              prev_height = new_height;
            }
	  }
	}
      }
    }
  }
  return s[9].size() != 0;

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
       datafile << setprecision(2) << setiosflags(ios::showpoint) 
                << grid[i][j].get_elevation();
       datafile << ",";
       datafile << setprecision(2) << setiosflags(ios::showpoint) 
                << grid[i][j].get_groundcover();
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
