/* Josh Hartshorn
   CS120 Homework 8
   Terrain Manager Project
*/

/* 
 * square.h - recommended Square class for Assignment8
 * you may modify as needed, but stay "compatible" if possible
 * Modified by: _____josh hartshorn________ (insert your name)
 */
using namespace std;

#ifndef SQUARE_H
#define SQUARE_H

class Square {
public:
    Square();
    void set(double e, char g);
    double get_elevation();
    char get_groundcover();
private:
    double elevation;
    char groundcover; // 'G', 'B', or 'T'
};
#endif  /* SQUARE_H */
