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
int fortune(int a, int b){
    //values can range from 2 to 8
    int c = a + b;

    if (c <= 4){
        cout << "Your cheese will likely fail." << endl;
    }
    else if (c > 4 && c <= 6){
        cout << "You have a moderate chance at success." << endl;
    }
    else if (c > 6 && c <= 8){
        cout << "You will be rich and successful today." << endl;
    }

    //perhaps add values together and have a series of if-statements to determine
      //the fortune

}

int main(){
    bool done false;

    while(!done){
        cout <<"Enter a number between 1-4. What is your fav" <<
            "orite supply to construct a spawning pool?" << endl;
        cout << "-Excluding your initial 5 workers" << endl;
        int choice = input();
        cout <<"Enter a number between 1-4. Each value represents a minute."
        << " At what point in time do you send your zerglings out?" << endl;
        int choice_two = input();

        cout << "You have selected " << choice << " and " << choice_two << endl;
        cout << "Your fortune is: " << fortune(choice, choice_two);
    }
}