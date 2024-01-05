/*
 Name: Alejandro Diaz
 Date: 09/27/23
 Assignment: 12.11
 
 Write a program that uses a structure to store the following data on a company division:
 
    - Division Name (such as East, West, North, or South)
    - Quarter (1, 2, 3, or 4)
    - Quarterly Sales
 
 The user should be asked for the four quarters' sales figures for the East, West, North, and South divisions.
 The data for each quarter for each division should be written to a file.
 
 Input Validation: Do not accept negative numbers for any sales figures.
 */

#include <iostream>
#include <fstream>
using namespace std;

// Defining constants:
#define SIZE 12

// Struct for company division data:
struct Division
{
    char name[SIZE];    // Division name
    int quarter;        // Quarter number
    double sales;     // Quarterly sales
};

// Function Prototypes:


// Main function for the main program loop:
int main()
{
    // Need File Stream object:
    fstream file("corp.dat", ios::out | ios::binary);       // Binary means it wont read endlines or anything like that, just print to one long string
    
    // Structures for each division:
    Division east, west, north, south;
    
    // Loop counter for each quarter:
    int i;
    
    // Assign names to the division structure variables:
    strcpy(east.name, "East");
    strcpy(west.name, "West");
    strcpy(north.name, "North");
    strcpy(south.name, "South");
    
    // Get sales data for East division:
    cout << "Enter the quarterly sales for the East Division:\n";
    for(i = 1; i <= 4; i++)
    {
        east.quarter = i;
        cout << "\tQuarter: " << i << ": ";
        cin >> east.sales;
        file.write(reinterpret_cast<char *>(&east), sizeof(east));
    }
    
    // Get sales data for West division:
    cout << "Enter the quarterly sales for the West Division:\n";
    for(i = 1; i <= 4; i++)
    {
        west.quarter = i;
        cout << "\tQuarter: " << i << ": ";
        cin >> west.sales;
        file.write(reinterpret_cast<char *>(&west), sizeof(west));
    }
    
    // Get sales data for North division:
    cout << "Enter the quarterly sales for the North Division:\n";
    for(i = 1; i <= 4; i++)
    {
        north.quarter = i;
        cout << "\tQuarter: " << i << ": ";
        cin >> north.sales;
        file.write(reinterpret_cast<char *>(&north), sizeof(north));
    }
    
    // Get sales data for South division:
    cout << "Enter the quarterly sales for the South Division:\n";
    for(i = 1; i <= 4; i++)
    {
        south.quarter = i;
        cout << "\tQuarter: " << i << ": ";
        cin >> west.sales;
        file.write(reinterpret_cast<char *>(&south), sizeof(south));
    }
    
    // Closing the file:
    file.close();
    
    return 0;
}
