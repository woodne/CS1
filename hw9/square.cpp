/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project
*/

//set elevation and then groundcover
#include "square.h"
Square::Square(){
}
//sets elevation and ground cover
void Square::set(double e, char g){
  groundcover = g;
  elevation = e;
}
double Square::get_elevation(){
  return elevation;
}
char Square::get_groundcover(){
  return groundcover;
}