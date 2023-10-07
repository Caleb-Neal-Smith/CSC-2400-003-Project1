// File: ConsecutiveIntCheckGCD.cpp
// Author: Caleb Smith
// Date: September 08, 2023
// Modification Date: October 07, 2023
/* Description: This program implements 
   the consecutive integer checking
   algorithm for computing the greatest
   common divisor of two integers. */

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;


// Function: getInt
/* This function prompts the user for input for two integers that 
    will be passed into the consecutiveIntGCD function.
    
    Args: 
    
    Returns: 
     This function has no return value, but it does update
     the arguments that were passed by reference into the
     function. */
void getInt(int &intOne, int &intTwo) {
    cout << "Enter an integer: ";
    cin >> intOne;
    cout << "Enter another integer: ";
    cin >> intTwo;
}

// Function: consecutiveIntCheckGCD
/* Calculates the greatest common divisor of two integers using the
   consecutive integer checking method. 
  
   Args: 
    The arguments for this function are m and n, which
    the integers for which the algorithm will compute
    the greates common divisor. 
        
   Returns:
    int t, the greates common divisor of m an n (t is used
    for the calculation, so it makes sense to return it as
    the result instead of declaring another variable). */
int consecutiveIntGCD(int m, int n) {
    /* GCD is undefined (or infinity?) for two integers that
       are both zero. A return value of zero from this function
       will prompt the main function to output "gcd(m, n) = undefined." */
    if (m == 0 and n == 0) {
        return 0;
    }

    /* If either input is negative, take the absolute value
      of that input. */
    if (m < 0) {
        m = abs(m);
    }
    if (n < 0) {
        n = abs(n);
    } 

    /* These are special conditionals for if one (but not both)
      of the inputs is zero. Greatest common divisor is defined
      when one (but not both) of the inputs is zero, but this
      algorithm cannot compute it that way without special
      conditionals. */
    if (m == 0) {
        return n;
    };
    if (n == 0) {
        return m;
    }

    /* This variable is used to calculate the greatest common
       divisor of m and n. t is initially stored with the 
       minimum value of m and n. If it is divisible by both m and n,
       it will be returned as the GCD. Otherwise, it will be decremented
       by one until an intger divisible by both m and n is found. It will
       then be returned as the GCD. */
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

// Function: min
/* This function finds the minimum of two integers.
  
   Args: 
    m and n, integers
    
   Returns: 
    This function returns whichever integer
    is the smallest (or the first integer if
    they are equal). */
int min(int m, int n) {
    if (m < n) {
        return m;
    } else if (n < m) {
        return n;
    } else {
        return m;
    }
}

// Function: main
/* Main body of code for this program. 
   
   Args: 
    None
   
   Returns:
    0 */
int main() {
    //Is it necessary to assign values to intOne and intTwo before passing them to the getInt function?
    /* This is the first integer that will be passed to
       the consecutiveIntGCD function. */
    int m = 0; 

    /* This is the second integer that will be passed to
       the consecutiveIntGCD function. */ 
    int n = 0;

    /* This variable is to store and output the value 
       returned by the consecutiveIntGCD function. */
    int answer;

    /* This function call is to get input from the user
       for integers m and n. */
    getInt(m, n);
    // Call function and store result in answer variable.
    answer = consecutiveIntGCD(m, n);
    // Condition for inputs with an undefined greatest common divisor
    if (answer == 0) {
        /* This is the condition for inputs with an undefined greatest common divisor. */
        cout << endl << "gcd(" << m << ", " << n << ") = " << "undefined." << "\n";
    } else {
        cout << endl << "gcd(" << m << ", " << n << ") = " << answer << ".\n";
    }
    return 0;
}