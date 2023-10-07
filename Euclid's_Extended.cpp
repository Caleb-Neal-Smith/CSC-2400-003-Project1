// File: Euclid's_Extended.cpp
// Author: Caleb Smith
// Date: September 08, 2023
// Modification Date: October 07, 2023
// Description: 
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;



// FUNCTION: algorithm_Euclid
/* If both arguments are equal to zero, this function will return zero (causing the main function
to output gcd(m,n) = undefined.) If only the second integer is zero, the first integer is returned
as the greatest common divisor.  Othwerwise, this function will repeatedly replace the second integer 
with the remainder of dividing the first integer by the second integer (while replacing the first 
integer with the former second integer) until the second integer is zero. The first integer is then 
returned as the greatest common divisor. */
int euclid_Extended(int m, int n) {
    /* GCD is undefined (or infinity?) for two integers that
       are both zero. A return value of zero from this function
       will prompt the main function to output "gcd(m, n) = undefined."*/
    if (m == 0 && n ==0) {
        return 0;
    }
    
    /*This variable is used to store the remainder
      of dividing m by n during the execution of the
      function. */
    int r;

    /*If either input is negative, take the absolute value
      of that input.*/
    if (m < 0) {
        m = (m * (-1));
    }
    if (n < 0) {
        n = (n * (-1));
    } 
    
    if (n == 0) {
        return m;

    }
    while (n!=0) {
        r = (m % n);
        m = n;
        n = r;
    }
    return m;
}

//Main body of code for this program
int main() {
    
    //This is the first integer that will be passed to
    //the euclid_Extended function. 
    int intOne; 

    //This is the second integer that will be passed to
    //the euclid_Extended function. 
    int intTwo;

    //This variable is used to store and output the result
    //of calling the e
    int answer;
    cout << "Enter an integer: ";
    cin >> intOne;
    cout << "Enter another integer: ";
    cin >> intTwo;
    //algorithm_Euclid function call
    answer = euclid_Extended(intOne, intTwo);
    if (answer == 0) {
        cout << "\ngcd(" << intOne << ", " << intTwo << ") = " << "undefined." << "\n";
    } else {
        cout << "\ngcd(" << intOne << ", " << intTwo << ") = " << answer << ".\n";
    }

    
    return 0;
}