/* -------------------------------------------------------------------------------------------- +
 |                                                                                              |
 |  Name: Alejandro Diaz                                                                        |
 |  Date: 10/25/23                                                                              |
 |  Assignment: 16.3                                                                            |
 |                                                                                              |
 |  Minimum/Maximum Templates                                                                   |
 |  Write templates for the two functions minimum and maximum.                                  |
 |                                                                                              |
 |  The minimum function should accept two arguments and return the value of the argument       |
 |  that is the lesser of the two.                                                              |
 |                                                                                              |
 |  The maximum function should accept two arguments and return the value of the argument       |
 |  that is the greater of the two.                                                             |
 |                                                                                              |
 |  Design a simple driver program that demonstrates the templates with various data types.     |
 |                                                                                              |
 + -------------------------------------------------------------------------------------------- */

#include <iostream>
#include <iomanip>
using namespace std;

// Including Template Functions:
template <class T1>
T1 minimum(T1 num1, T1 num2)
{
    T1 min = 0;
    
    if(num1 < num2)
        min = num1;
    else if(num1 > num2)
        min = num2;
    else
        min = num1;
    
    return min;
}

template <class T2>
T2 maximum(T2 num1, T2 num2)
{
    T2 max = 0;
    
    if(num1 > num2)
        max = num1;
    else if(num1 < num2)
        max = num2;
    else
        max = num1;
    
    return max;
}


// -------------------------------------------------------------------------------------------- |
// Function Prototypes:

// Main function for the main program loop:
int main()
{
    int     x = 20      ,   y = 3;
    double  z = 2.45    ,   w = 3.31;
    
    int theMin = minimum<int>(x, y);
    double theMax = maximum<double>(z, w);
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Minimum between " << x << " and " << y << " is: " << theMin << endl;
    cout << "Maximum between " << z << " and " << w << " is: " << theMax << endl;
    
    return 0;
}
// End Main
// -------------------------------------------------------------------------------------------- |

/*
 Notes from Chapter 16:
 
 A function template is a "generic" function that can work with any data type. The programmer
 write the specifications of the function, but substitutes the parameters for data types.
 
 When the compiler encounters a call to the function, it generates code to handle the
 specific data type(s) used in the call.
 
 */
