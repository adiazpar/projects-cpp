/*
 Name: Alejandro Diaz
 Date: 08/30/23
 Assignment: 7.3
 
 In this program, I will do the salsa code.
 Write a program that lets a maker of chips and salsa keep track of sales for five differ- ent types
 of salsa: mild, medium, sweet, hot, and zesty. The program should use two parallel 5-element
 arrays: an array of strings that holds the five salsa names, and an array of integers that holds
 the number of jars sold during the pastmonth for each salsa type. The salsa names should be stored
 using an initialization list at the time the name array is created. The program should prompt the
 user to enter t h e number of jars sold for each type. Once this sales data has been entered, the
 program should produce a report that displays sales for each salsa type, total sales, and the names
 of the highest selling and lowest selling products.
 
 Input Validation: Do not accept negative values for number of jars sold.
 */

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

// Function Prototypes:
int getTotal(int[], int);
int posOfLargest(int[], int);
int posOfSmallest(int[], int);

int main()
{
    // Constant for number of salsa types:
    const int NUM_TYPES = 5;
    
    // Array of salsa types:
    string types[NUM_TYPES] = {"mild", "medium", "sweet", "hot", "zesty"};
    
    // Array of sales for each salsa type:
    int sales[NUM_TYPES];
    
    // Total number of jars sold:
    int totaljarsSold;
    
    // Susbscript of the salsa that sold the most:
    int hiSalesProduct;
    
    // Subscript of the salsa that sold the least:
    int loSalesProduct;
    
    // Get the number of jars sold of each type of salsa:
    for(int i = 0; i < NUM_TYPES; i++)
    {
        // Get the number of jars sold:
        cout << "Jars sold last month of " << types[i] << ": ";
        cin >> sales[i];
        
        // Validate the input:
        while(sales[i] < 0)
        {
            cout << "Jars sold must be 0 or more. " << "Please re-enter: ";
            cin >> sales[i];
        }
    }
    
    // Get total sales, highest selling, and lowest selling:
    totaljarsSold = getTotal(sales, NUM_TYPES);
    hiSalesProduct = posOfLargest(sales, NUM_TYPES);
    loSalesProduct = posOfSmallest(sales, NUM_TYPES);
    
    // Display the sales report header:
    cout << endl << endl;
    cout << "Salsa Sales Report \n\n";
    cout << "Name           Jars Sold\n";
    cout << "-------------------------------\n";
    
    // Display the name and jars sold of each type:
    for(int i = 0; i < NUM_TYPES; i++)
    {
        cout << types[i] << setw(21) << sales[i] << endl;
    }
    
    // Display the total sales, highest seller, lowest seller:
    cout << "\nTotal Sales: " << setw(15) << totaljarsSold << endl;
    cout << "Highest Seller: " << types[hiSalesProduct] << endl;
    cout << "Lowest Seller: " << types[loSalesProduct] << endl;
    
    
    return 0;
}

int getTotal(int values[], int size)
{
    int total = 0;
    
    for(int i = 0; i < size; i++)
    {
        total += values[i];
    }
    
    return total;
}

int posOfLargest(int values[], int size)
{
    int indexOfLargest = 0;
    
    for(int i = 0; i < size; i++)
    {
        if(values[i] > values[indexOfLargest])
        {
            indexOfLargest = i;
        }
    }
    
    return indexOfLargest;
}

int posOfSmallest(int values[], int size)
{
    int indexOfSmallest = 0;
    
    for(int i = 0; i < size; i++)
    {
        if(values[i] < values[indexOfSmallest])
        {
            indexOfSmallest = i;
        }
    }
    
    return indexOfSmallest;
}
