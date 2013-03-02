#include <iostream>

using namespace std;

//function to take value and force user to repeat it if input invalid
int input(){
	int choice = 0;
	bool valid;
    do{
        cin >> choice;
        if(choice < 1 || choice > 4){
    	    valid = false;
    	    cout << "Invalid Input" << endl;
        }else{
    	    valid = true;
        }
    }while(!valid);

	return choice;
}

//function to take values entered by user and return a fortune based on input
int fortune(){

    //perhaps add values together and have a series of if-statements to determine
      //the fortune

}

int main(){
	cout <<"Enter a number between 1-4. What is your fav" <<
        "orite supply to construct a spawning pool?" << endl;
    cout << "-Excluding your initial 5 workers" << endl;
	int choice = input();
    cout <<"Enter a number between 1-4. "
}