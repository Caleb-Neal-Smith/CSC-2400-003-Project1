/* File: Euclid's_Extended.cpp*/

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
returned as the greatest common divisor. 
    
    Args: 
        integers m and n

    Returns:
        This function returns the greatest common divisor of m and n 
    */
int algorithm_Euclid(int m, int n) {
    //GCD is undefined (or infinity?) for two integers that are both zero.
    if (m == 0 && n ==0) {
        return 0;
    }
    int r;
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
    //Variable declarations for intOne, intTwo, and answer.
    int intOne; 
    int intTwo;
    int answer;
    cout << "Enter an integer: ";
    cin >> intOne;
    cout << "Enter another integer: ";
    cin >> intTwo;
    //algorithm_Euclid function call
    answer = algorithm_Euclid(intOne, intTwo);
    if (answer == 0) {
        cout << "\ngcd(" << intOne << ", " << intTwo << ") = " << "undefined." << "\n";
    } else {
        cout << "\ngcd(" << intOne << ", " << intTwo << ") = " << answer << ".\n";
    }

    
    return 0;
}