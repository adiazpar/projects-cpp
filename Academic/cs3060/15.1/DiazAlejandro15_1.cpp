/*
 Name: Alejandro Diaz
 Date: 10/18/23
 Assignment: 15.1
 
 Employee Shift Stuff
 */

#include <iostream>
#include <iomanip>
#include "ProductionWorker.h"
using namespace std;

// Function Prototype:
void displayInfo(ProductionWorker);

int main()
{
    ProductionWorker pw("John Jones", "123", "10/12/2010", 2, 18.00);
    displayInfo(pw);
    
    return 0;
}

void displayInfo(ProductionWorker e)
{
    cout << setprecision(2) << fixed << showpoint;
    cout << "Name: \t\t\t\t" << e.getName() << endl;
    cout << "Employee Number: \t" << e.getNumber() << endl;
    cout << "Hire Date: \t\t\t" << e.getHireDate() << endl;
    cout << "Shift: \t\t\t\t" << e.getShiftName() << endl;
    cout << "Shift number: \t\t" << e.getShiftNumber() << endl;
    cout << "Pay rate: \t\t\t" << e.getPayRate() << endl;
}
