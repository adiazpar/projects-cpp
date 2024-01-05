/* -------------------------------------------------------------------------------------------- +
 |                                                                                              |
 |  Name: Alejandro Diaz                                                                        |
 |  Date: 10/30/23                                                                              |
 |  Assignment: 16.7                                                                            |
 |                                                                                              |
 |  TestScores Class                                                                            |
 |  Write aclass named TestScores. The class constructor should accept an array of              |
 |  test scores as its argument. The class should have a member function that returns           |
 |  the average of the test scores.                                                             |
 |                                                                                              |
 |  If any test score in the array is negative or greater than 100,                             |
 |  the class should throw an exception. Demonstrate the class in a program.                    |
 |                                                                                              |
 + -------------------------------------------------------------------------------------------- */

#include <iostream>
#include <iomanip>
using namespace std;

#define SIZE 5
#define MIN 0
#define MAX 100

// -------------------------------------------------------------------------------------------- |
// TestScores Class:
class TestScores {
public:
    double scoreArray[SIZE];
    double average;
    
    bool isValid;
    int validIndices;
    int invalidIndex;
    
public:
    // Constructor:
    TestScores(double *inputArray)
    {
        invalidIndex = -1;
        isValid = true;
        
        fillScores(inputArray);
    }
    
    // Mutator for Arrays (Try-Catch):
    void fillScores(double *inArr)
    {
        int i = 0;
        
        while(isValid && i < SIZE)
        {
            try {
                scoreArray[i] = inArr[i];           // Execute this every loop, but loop will stop when found an invalid grade...
                validIndices = i+1;
                
                if(inArr[i] < 0 || inArr[i] > 100)
                {
                    isValid = false;
                    invalidIndex = i;
                    throw out_of_range("OH NO!");
                }
            }
            catch(out_of_range) {
                cout << "ERROR: A grade in your input is below " << MIN << " or above " << MAX << endl;
                cout << "CATCH: Element [" << i << "] in the array is " << scoreArray[i] << endl;
            }
            
            i++;
        }
    }
    
    // Compute the average of the scoreArray:
    double findAverage()
    {
        average = 0;
        
        if (isValid)
        {
            for(int i = 0; i < SIZE; i++)
            {
                average += scoreArray[i];
            }
            average /= SIZE;
        }
        
        return average;
    }
    
    // Print Function:
    void printScores()
    {
        for(int i = 0; i < validIndices; i++)
        {
            if(i != invalidIndex)
                cout << "Test " << i + 1 << ":\t\t" << scoreArray[i] << endl;
            else
                cout << "Test " << i + 1 << ":\t\t..." << endl;
        }
        cout << endl;
    }
};

// -------------------------------------------------------------------------------------------- |
// Main program:
int main()
{
    // Example of good data:
    double data[SIZE] = {50, 13.5, 80, 56.4, 100};
    TestScores scores(data);
    
    scores.printScores();
    cout << "Average:\t" << scores.findAverage() << endl << endl;
    
    
    // Example of bad data:
    double data2[SIZE] = {70, 89, -3, 0, 40.32};
    TestScores scores2(data2);
    
    scores2.printScores();
    
    return 0;
}
