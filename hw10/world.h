#ifndef ROBOT_H
#include "robot.h"
#endif
const int HEIGHT = 20;
const int WIDTH = 80;

class world{
   private:
     int terrain[WIDTH][HEIGHT];
     robot *bots[WIDTH][HEIGHT];
   public:
     void set_up();
     void draw();
     void update();
};

