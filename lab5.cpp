#include <iostream>

using namespace std;

//function to take value and force user to repeat it if input invalid (choices up to me)
int input(){
	int choice = 0;
	bool valid;
	do{
        cout << "Enter a number between 1-4. 1 = Red, 2 = Blue, , 3 = Orange, 4 = green." << endl;
        cin >> choice;
        if(choice < 1 || choice > 4){
    	    valid = false
    	    cout << "Invalid Input" << endl;
        }else{
    	    valid = true;
        }
    }while(!valid);


	return choice;
}

//function to take value entered by user and return a fortune based on input
int fortune(){

}

int main(){
	
	int choice = input();
}