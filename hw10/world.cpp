/*Josh Hartshorn
  CS120

  If a robot lands on a space with (M)ountains or (T)rees it loses 10 energy. 
  If it lands on (W) it will gain energy. Right now they are very difficult
  to see. I may need to change the character used to represent robots.
*/

#include<iostream>
#include<cstdlib>
using namespace std;

#include"world.h"

void world::set_up(){
   for(int y = 0; y < HEIGHT; y++){
      for(int x = 0; x < WIDTH; x++){
         bots[x][y] = NULL;
         terrain[x][y] = rand()%6;
      }
   }
   bots[2][2] = new robot(1);
   bots[7][7] = new robot(2);
   bots[20][20] = new robot(3);
   bots[10][30] = new robot(4);
   bots[10][31] = new robot(5);
   bots[5][5] = new robot(6);
   bots[15][15] = new robot(7);
   bots[10][37] = new robot(8);
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
