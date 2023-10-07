/*Caleb Smith, CSC 2400-003*/

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;


// Function: getInt()
/*This function prompts the user for input for two integers that will be passed into the consecutiveIntGCD function.*/
void getInt(int &intOne, int &intTwo) {
    cout << "Enter an integer: ";
    cin >> intOne;
    cout << "Enter another integer: ";
    cin >> intTwo;
}

//Function: consecutiveIntGCD
//In order to calculate greatest common divisor, this function takes the smaller of the two arguments and checks if it is 
//divisible by both arguments with no remainder. If it is, that value is returned as the greatest common divisor. If not, the function checks
//each smaller integer until an integer that is divisible (with no remainder) by both arguments is found, and that value
//is returned as the greates common divisor.
int consecutiveIntGCD(int m, int n) {
    if (m == 0 and n == 0) {
        return 0;
    }
    if (m < 0) {
        m = abs(m);
    }
    if (n < 0) {
        n = abs(n);
    } 
    int t = min(m, n);
    while (t > 1) {
        if ((m % t) == 0 && (n % t) == 0) {
            return t;
        } else {
            t = t - 1;
        }
    }
    return t;
}

//Function: min
//This function finds the smaller of two arguments.
int min(int a, int b) {
    if (a < b) {
        return a;
    } else if (b < a) {
        return b;
    } else {
        return a;
    }
}

//Function: main
// Main body of code for this program.
int main() {
    //Is it necessary to assign values to intOne and intTwo before passing them to the getInt function?
    int intOne = 0; 
    int intTwo = 0;
    int answer;
    getInt(intOne, intTwo);
    //This is to distinguish between inputs of two zeroes (whose greatest common divisor is undefined 
    //(or infinity?)) //and inputs of one zero and one nonzero (whose GCD is defined, but not for this 
    //algorithm.)
    while(!(intOne == 0 && intTwo == 0) && (intOne == 0 or intTwo == 0)) {
        getInt(intOne, intTwo);
    }
    answer = consecutiveIntGCD(intOne, intTwo);
    if (answer == 0) {
        cout << endl << "gcd(" << intOne << ", " << intTwo << ") = " << "undefined." << "\n";
    } else {
        cout << endl << "gcd(" << intOne << ", " << intTwo << ") = " << answer << ".\n";
    }
    return 0;
}