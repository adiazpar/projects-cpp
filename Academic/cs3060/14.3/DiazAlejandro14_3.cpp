/*
 Name: Alejandro Diaz
 Date: 10/18/23
 Assignment: 14.3
 
 Carpet Calculator Problem
 */

#include <iostream>
#include <iomanip>
#include "FeetInches.h"
#include "RoomDimension.h"
#include "RoomCarpet.h"

using namespace std;

// Defining constants:

// Function Prototypes:

int main()
{
    // Variables for room length:
    int lengthFeet, lengthInches;
    
    //Variables for room width:
    int widthFeet, widthInches;
    
    // Carpet cost per square foot:
    double costPerFoot;
    
    // Get the room's length:
    cout << "Room Length Feet: ";
    cin >> lengthFeet;
    
    cout << "Room Length Inches: ";
    cin >> lengthInches;
    
    // Create a FeetInches object for the length:
    FeetInches length(lengthFeet, lengthInches);
    
    // Get the room's width:
    cout << "Room Width Feet: ";
    cin >> widthFeet;
    
    cout << "Room Width Inches: ";
    cin >> widthInches;
    
    // Create a FeetInches object for the width:
    FeetInches width(widthFeet, widthInches);
    
    // Create a RoomDimension object for the room:
    RoomDimension dimension(length, width);
    
    // Get the carpet's cost per square foot:
    cout << "Cost per square foot of carpet: $";
    cin >> costPerFoot;
    
    // Create a RoomCarpet object:
    RoomCarpet carpet(dimension, costPerFoot);
    
    // Display the cost:
    cout << setprecision(2) << fixed << showpoint;
    cout << "Total Cost: $" << carpet.getTotalCost() << endl << endl;
    
    return 0;
}
