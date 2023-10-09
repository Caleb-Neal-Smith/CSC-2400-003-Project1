// File: Euclid's_Algorithm.cpp
// Author: Caleb Smith
// Date: September 08, 2023
// Modification Date: October 08, 2023
// Description: Implements the basic Euclid's Algorithm
// for computing Greatest Common divisor.
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
        This function returns the greatest common divisor of m and n.*/
int algorithm_Euclid(int m, int n) {
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
    //the algorithm_Euclid function. 
    int m; 

    //This is the second integer that will be passed to
    //the algorithm_Euclid function. 
    int n;

    //This variable is used to store and output the result
    //of calling the algorithm_Euclid function.
    int answer;
    cout << "Enter an integer: ";
    cin >> m;
    cout << "Enter another integer: ";
    cin >> n;
    //algorithm_Euclid function call
    answer = algorithm_Euclid(m, n);
    // Condition for inputs with an undefined greatest common divisor
    if (answer == 0) {
        /* This is the condition for inputs with an undefined greatest common divisor. */
        cout << "\ngcd(" << m << ", " << n << ") = " << "undefined." << "\n";
    } else {
        cout << "\ngcd(" << m << ", " << n << ") = " << answer << ".\n";
    }

    
    return 0;
}