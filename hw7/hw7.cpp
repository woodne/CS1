/*  Josh Hartshorn
    CS 120, Homework 7
    March 13th, 2013

    Generic Board Game Assignment
*/

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
// Class Prototype
class square{
  private:
    int move;
    string message;
    char symbol;
  public:
    square();
    void print();
    int action();
    void set(int,char,string);
};
// Function Prototypes
void print_board(square[], int ,int);
void read_board(square[]);
void check_position(int &); //pass by reference
// Global variables
const int board_length = 20;


int main(){
  int current_player = 1, roll;
  int player1_position = 0, player2_position = 0;
  square the_board[board_length];
  srand(time(NULL));
  read_board(the_board);
  print_board(the_board,player1_position,1);
  print_board(the_board,player2_position,2);
//The start of the game loop
  do{
    cout << "\n\n\n\n\nPlayer " << current_player << " type enter to roll.\n";
    cin.ignore();
    roll = 1 + (rand() % 5);
    cout << "Player " << current_player << " rolled a " << roll << ".\n";
    if(current_player == 1){
      player1_position += roll;
      check_position(player1_position);
      player1_position += the_board[player1_position].action();
      check_position(player1_position);
    }
    else{
      player2_position += roll;
        check_position(player2_position);
        player2_position += the_board[player2_position].action();
        check_position(player2_position);
    }
    print_board(the_board,player1_position,1);
    print_board(the_board,player2_position,2);
    current_player = (current_player % 2) + 1;
  }while((player1_position < board_length - 1) && (player2_position < board_length-1));
//The game loop has ended
  current_player = (current_player % 2) + 1;
  cout << "\nPlayer " << current_player << " Wins!!!\n";
  cin.ignore();
  return 0;
 }
/*This function opens the file and reads the data within and organizes it
  in this way. 7(square number) -2(square move) ?(square symbal). 7 -2 ?
  The information is then passed to our square accessor method "set" - which
  allows the data from the file to be used elsewhere in the program.
*/
void read_board(square b[]){
  fstream infile;
  infile.open("game.txt");
  int square_number, square_move;
  string square_message;
  char square_symbol;
  while(!infile.eof()){
    infile >> square_number >> square_move >> square_symbol;
    getline(infile,square_message);
    if(square_number < board_length)
      b[square_number].set(square_move,square_symbol,square_message);
    }
}
/*This function collects information about the game world and prints
  it to the screen. This function does not change data outside its
  scope.*/
void print_board(square b[], int player_position, int player_number){
  for(int i = 0; i < board_length; i++){
    if(i != player_position)
      b[i].print();
    else
      cout << player_number;
    }
    cout << "Goal\n";
  for(int i = 0; i < board_length; i++)
    cout << "-";
    cout << "\n";
}
/*function checks position of player and insures the player position
  does not go into the negatives or exits the end of the board. 
  It uses a reference so changes made in this function persist outside.*/
void check_position(int &p){
  if(p < 0)
    p = 0;
  if(p >= board_length)
    p = board_length-1;
}
// Functions of the class square
square::square(){
  symbol = ' ';
  move = 0;
  message = "";
}
int square::action(){
  cout << message << endl;
  return move;
}
void square::print(){
  cout << symbol;
}
//allows us to change values inside our square class
void square::set(int m, char s, string a_message){
  move = m;
  symbol = s;
  message = a_message;
}