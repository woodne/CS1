#include<iostream>
#include<cstdlib>
#include <fstream>
#include <string>
using namespace std;

#include"world.h"

void world::set_up(){
  string input;
  cout << "Do you want to load a world? Type \"yes\" or no" << endl;
  cin >> input;
  if (input == "yes"){
    string filename;
    cout << "Enter the world files name"<< endl;
    cin >> filename;
    //load data
    ifstream datafile;
    datafile.open(filename.c_str());
    if (!datafile){
      cout << "Error loading file." << endl;
    }
    for(int y = 0; y < HEIGHT; y++){
      for(int x = 0; x < WIDTH; x++){
        char gc;
        datafile >> gc;
        cout << "Data: " << gc << endl;
        bots[x][y] = NULL;
        terrain[x][y] = gc-48; // subtract 48 because the value is a char
      }
    }


  }
  else{
    cout << "Randomizing WorldMap" << endl;
   for(int y = 0; y < HEIGHT; y++){
      for(int x = 0; x < WIDTH; x++){
         bots[x][y] = NULL;
         terrain[x][y] = rand()%6;
      }
    }
  }
   bots[2][2] = new robot(1);
   bots[2][2] -> player_controlled();
   bots[7][7] = new robot(2);
   bots[5][5] = new robot(6);
}

void world::draw(){
   for(int y = 0; y < HEIGHT; y++){
      for(int x = 0; x < WIDTH; x++){
         if(bots[x][y] == NULL)
          switch(terrain[x][y]){
            case 1:
              cout << "T";
              break;
            case 2:
              cout << "G";
              break;
            case 3:
              cout << "M";
              break;
            case 4:
              cout << "W";
              break;
            case 5:
              cout << "T";
              break;
            case 0:
              cout << "B";
              break;
            case 6:
              cout << "R";
              break;
            default:
              cout << terrain[x][y] << " :: ";

          }
         else
            bots[x][y] -> draw();
     }
     cout << endl;
  }
  for(int y = 0; y < HEIGHT; y++)
     for(int x = 0; x < WIDTH; x++)
        if(bots[x][y] != NULL){
           bots[x][y]->print();
           bots[x][y]->refresh();
           cout << "\n";
        }
}

void world::update(){
   int tempx,tempy;
   robot *temp;
   for(int y = 0; y < HEIGHT; y++){
      for(int x = 0; x < WIDTH; x++){
         if(bots[x][y] != NULL){
            tempx = x;
            tempy = y;
            bots[x][y] -> move(tempx,tempy);
            if (bots[tempx][tempy] != NULL){
              bots[x][y] -> energy_boost();
              bots[tempx][tempy] -> energy_drain();
              }
            if(tempx < 0 || tempx >= WIDTH)
              tempx = x;
            if(tempy < 0 || tempy >= HEIGHT)
              tempy = y;
            if(terrain[x][y] == 3 || terrain[x][y] == 5){
              bots[x][y] -> energy_drain();
            }
            if(terrain[x][y] == 4){
              bots[x][y] -> energy_boost();
            }
            if(bots[tempx][tempy] == NULL){
               temp = bots[x][y];
               bots[x][y] = NULL;
               bots[tempx][tempy] = temp;
            }
         }
      }
   }
}
