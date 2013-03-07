/* Josh Hartshorn			1/28/2013
   Section 2

   This program will take values of radius and height from the user and output volume, surface area, and ration of volume to surface area for three different primites. Sphere, right circular cone, and right circular cylinder
*/ 
#include <iostream> 
#include <cmath>
#include <iomanip> // need to make the output neat(Do not know how)

using namespace std;

const double pi = 3.14159;

void compute_ratio(double volume, double surface)
{
  double ratio = volume/surface;

  cout << "\tThe ratio of volume to surface area is: " << ratio << endl; 
  cout << endl;
}

void calc_sphere(double a, double b)
{
  double v, s;

  v = pi*pow(a,3)*4/3;
  s = 4*pi*pow(a,2);

  cout << "For a sphere: " << endl;
  cout << "\tThe volume is: " <<  v << endl;
  cout << "\tThe surface area is: " << s << endl;

  compute_ratio(v, s);
}
void calc_cone(double a, double b)
{
  double v, s;

  v = pi*pow(a,2)*b*1/3;
  s = pi*a*(a+sqrt(pow(a,2)+pow(b,2)));

  cout << "For a Right Circular Cone: " << endl;
  cout << "\tThe volume is: " << v << endl;
  cout << "\tThe surface area is: " << s << endl;

  compute_ratio(v, s);
}
void calc_cylinder(double a, double b)
{
  double v, s;

  v = pi*pow(a,2)*b;
  s = 2*pi*a*(a+b);

  cout << "For a Right Circular Cylinder: " << endl;
  cout << "\tThe volume is: " << v << endl;
  cout << "\tThe surface area is: " << s << endl;

  compute_ratio(v, s);
}
int main()
{

  double radius, height;

  cout << "Please enter values for radius and height: " << endl;
  cin >> radius >> height;

  calc_cylinder(radius, height);
  calc_cone(radius, height);
  calc_sphere(radius, height);
  
  return 0;
}
