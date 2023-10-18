#include <iostream>
using namespace std;

// Note: if we don't want to use this line of code, we can use the things in this namesepace like this:
// std::cout, std::endl

// Constant for the wall area that one gallon of paint will cover:
const int WALL_AREA_PER_GALLON = 100;

// Constant for the hourly rate for labor:
const double HOURLY_RATE = 25.0;

// Function prototype(s):
int getNumRooms();
double getPaintPrice();
double getWallSquareFeet();
int numberOfGallons(double);
double laborHours(double);
void displayCost(int, double, double);

int main()
{
    // Variables
    int numRooms;           // Number of rooms to paint
    double paintPrice;      // Price of the paint per gallon
    double totalWallArea;   // Accumulator for total wall area
    int gallons;            // Gallons of paint needed
    double hours;           // Hours of labor needed

    // Get the number of rooms:
    numRooms = getNumRooms();

    // Get the price of the paint per gallon:
    paintPrice = getPaintPrice();

    // Get the total wall area of the rooms:
    for(int i = 1; i < numRooms; i++)
    {
        int wallArea;
        cout << "Room " << i << ": ";
        wallArea = getWallSquareFeet();
        totalWallArea += wallArea;
    }

    // Get the number of gallons of paint needed:
    gallons = numberOfGallons(totalWallArea);

    // Get the number of labor hours needed:
    hours = laborHours(totalWallArea);

    // Display the total charges:
    displayCost(gallons, paintPrice, hours);

    return 0;
}

int getNumRooms()
{
    int rooms;

    // Get the number of rooms:
    cout << "Enter the number of rooms to be painted: ";
    cin >> rooms;

    // Validate the input:
    while(rooms < 1)
    {
        cout << "ERROR: Enter 1 or greater.\n";
        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;
    }

    return rooms;
}

double getPaintPrice()
{
    double price;

    // Get the price per gallon:
    cout << "Enter the price of the paint, per gallon: ";
    cin >> price;

    // Validate the input:
    while(price < 10.0)
    {
        cout << "ERROR: Paint price must be 10.00 or greater.\n";
        cout << "Enter the price of the paint, per gallon: ";
        cin >> price;
    }

    return price;
}

double getWallSquareFeet()
{
    double wallArea;

    // Get the wall space area:
    cout << "Enter the area of wall space in square feet: ";
    cin >> wallArea;

    // Validate the input:
    while(wallArea < 0)
    {
        cout << "ERROR: Wall area must be a non-negative number.\n";
        cout << "Enter the area of wall space in square feet: ";
        cin >> wallArea;
    }

    return wallArea;
}

int numberOfGallons(double wallArea)
{
    double doubleGallons;
    double remainder;
    int intGallons;

    // Calculate the gallons as a double:
    doubleGallons = wallArea / WALL_AREA_PER_GALLON;

    // Get the truncated number of gallons:
    intGallons = static_cast<int>(doubleGallons);

    // Get the fractional part of a gallomn needed:
    remainder = doubleGallons - static_cast<int>(doubleGallons);

    // Determine if a fractional part of a gallon is needed:
    if(remainder > 0)
        intGallons += 1;    // if so, add 1 gallon

    return intGallons;
}

double laborHours(double wallArea)
{
    double hours = wallArea / WALL_AREA_PER_GALLON;

    return hours;
}

void displayCost(int gallons, double paintPrice, double hours)
{
    double totalPaintCost;
    double totalLabor;
    double totalCharges;

    // Calculate the total cost of the paint:
    totalPaintCost = gallons * paintPrice;

    // Calculate the total labor charges:
    totalLabor = hours * HOURLY_RATE;

    // Calculate the total cost of the job:
    totalCharges = totalPaintCost + totalLabor;

    // Display the charges for the job:
    
}
