  #ifndef ROBOT_H
#include "robot.h"
#endif
const int HEIGHT = 10;
const int WIDTH = 10;
class world{
   private:
     int terrain[WIDTH][HEIGHT];
     robot *bots[WIDTH][HEIGHT];
   public:
     void set_up();
     void draw();
     void update();
};

