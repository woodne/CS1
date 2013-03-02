/* Josh Hartshorn
    CS120 Lab6
    March 1st 2013

    This lab explores using classes. The example below uses a rectangle rectangle class.
*/
#include <iostream>

using namespace std;

//rectangle class with (width and height) members - both doubles

class Rectangle{
    private:
      double width, height;
    public:
      //constructor
      Rectangle() {
          double width = 0;
          double height = 0;
      }
      //member methods
      void set_height(double);
      void set_width(double);
      double get_area(){return (width * height);}
      double get_perimeter(){return (width*2)+(height*2);}
      void get_dimensions();
};
void Rectangle::set_height(double x){
    if(x >= 0){
        height = x;
    }
    else{
        height = 0;
    }
}
void Rectangle::set_width(double x){
    if(x >= 0){
        width = x;
    }
    else{
        width = 0;
    }
}
void Rectangle::get_dimensions(){
    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;
}

int main(){
  double data;
  Rectangle rect;
  cout << "\nSet the Height: ";
  cin >> data; 
  cout << "You entered: " << data << endl;
  rect.set_height(data);
  cout << "\nSet the Width: ";
  cin >> data;
  cout << "You entered: " << data << endl;
  rect.set_width (data);
  cout << "\nArea: " << rect.get_area() << endl;
  cout << "Perimeter: " << rect.get_perimeter() << endl << endl;
  cout << "Rectangle Dimensions: \n";
  rect.get_dimensions();
  return 0;
}