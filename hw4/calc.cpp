
/* Josh Hartshorn
   CS120 Homework 4
   Section 2
   02/05/2013

   Subtraction, Multiplication, and sqrt
   Problems 1, 2, 5, and 6 

 * A simple calculator program, controlled by a menu and
 *  divided into separate functions
 */
#include<iostream>
#include<cmath>
using namespace std;

bool divide_zero = false; //divide by zero check
//-------------- Functions -------------------
//minimum function
double minimum(double value1, double value2)
{
  if (value1 < value2){
    return value1;     // returning 1 if it is the smallest
  }
  else
  {
    return value2;
  }
}
//calculates absolute value
double absolute_value(double value1)
{
  if (value1 < 0){
    value1 *= -1;
    return value1;
  }
  else{
    return value1;
  }
}

double divide(double dividend, double divisor)
{
  if (divisor == 0){
    divide_zero = true;
    return 0;     // avoids divide by zero errors
  }
  else
  {
    return (dividend / divisor);
  }
}

//----------------- get_value function ----------------
float get_value()
{
  float temp_value;
  cout << "Enter a value: ";
  cin >> temp_value;
  return temp_value;
}

//-------------------- print_menu function -------------
void print_menu()
{
  cout << endl;
  cout << "Add (1)" << endl;
  cout << "Divide (2)" << endl;
  cout << "Subtract (3)" << endl;
  cout << "Multiply (4)" << endl;
  cout << "Minimum (5)" << endl;
  cout << "Absolute Value (6)" << endl;
  cout << "Square Root (7)" << endl;
  cout << "Power (8)" << endl;
  cout << "Exit (0)" << endl;
  cout << "Enter your choice: ";
}
//-------------- Main -------------------
int main()
{
  cout << "This calculator was modified by Josh Hartshorn on 02-05-2013";
  cout << "\nPress the key which corresponds to the type of problem ";
  cout << "you need solved." << endl;
  float operand1,
        operand2,
	answer;
  int choice, valid_choice;
  do {
    print_menu();
    cin >> choice;

    // assume choice is valid
    valid_choice = 1;

    switch (choice) {
    case 0:
      break;
    case 1:
      // addition
      operand1 = get_value();
      operand2 = get_value();
      answer = operand1 + operand2;
      break;
    case 2:
      // division
      operand1 = get_value();
      operand2 = get_value();
      answer = divide(operand1, operand2);
      break;
    case 3:
      //subtraction
      operand1 = get_value();
      operand2 = get_value();
      answer = operand1 - operand2;
      break;
    case 4:
      //multiplication
      operand1 = get_value();
      operand2 = get_value();
      answer = operand1 * operand2;
      break;
    case 5:
      //minimum
      operand1 = get_value();
      operand2 = get_value();
      answer = minimum(operand1, operand2);
      break;
    case 6:
      //absolute value
      operand1 = get_value();
      answer = absolute_value(operand1);
      break;
    case 7:
      //square root
      operand1 = get_value();
      answer = sqrt(operand1);
      break;
    case 8:
      //pow
      operand1 = get_value();
      operand2 = get_value();
      answer = pow(operand1, operand2);
      break;
    default:
      valid_choice = 0;
      // choice is invalid
      cout << "Invalid Choice." << endl;
    }
    if (valid_choice && (choice != 0)) {
      // if choice is valid, print the answer
      if (divide_zero){ //divide by zero check
        cout << "\nDividing by zero is not permitted" << endl;
        divide_zero = false;
      }
      else{
      cout << endl << "Answer = " << answer << endl;
      }
    }
  } while (choice != 0);
  // if the user didn't choose 0, loop back to start
  return 0;
}
