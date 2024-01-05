/*
 Name: Alejandro Diaz
 Date: 09/16/23
 Assignment: 11.8
 
 PART 1:
 Write a program that uses a structure to store the following data about a customer account:
        
        Name
        Address
        City, State, and ZIP Telephone Number Account Balance
        Date of Last Payment
 
 The program should use an array of at least 10 structures. It should let the user enter data into the array,
 change the contents of any element, and display all the data stored in the array.
 The program should have a menu-driven user interface.
 
 Input Validation: When the data for a new account is entered, be sure the user enters data for all the fields.
 No negative account balances should be entered.
 
 
 PART 2:
 Add a function to Programming Challenge 7 (Customer Accounts) that allows the user to search
 the structure array for a particular customer's account. It should accept part of the
 customer's name as an argument, then search for an account with a name that matches it.
 All accounts that match should be displayed. If no account matches, a message saying so should be displayed.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Constant for the number of accounts:
#define NUM_ACCOUNTS 10

// Customer Structure:
struct Customer
{
    string name;        // Name
    string address;     // Address
    string city;        // City
    string state;       // State
    string zip;         // ZIP Code
    string phone;       // Phone Number
    double balance;     // Account Balance
    string lastPay;     // Date of last payment
};


// Function Prototype:
void getInfo(Customer&);
void showInfo(Customer);
void showSearch(Customer[], string, int);


int main(void)
{
    // Array of Customer structures:
    Customer account[NUM_ACCOUNTS];
    
    // Always initialize variables...
    // Variables:
    int maxCust = 0;    // Subscript of next account to enter user's choice from a menu
    int choice  = 0;
    int cust    = 0;
    int count   = 0;
    string search = " ";
    
    do
    {
        // Display menu:
        
        // Get the user choice:
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Validate the choice:
        while (choice < 1 || choice > 5)
        {
            cout << "Please enter 1, 2, 3, 4 or 5.\n";
            cout << "Enter your choice: ";
            cin >> choice;
        }
        
        // Perform the selected operation
        switch(choice)
        {
            // Enter new account information:
            case 1:
                cin.get();
                getInfo(account[maxCust]);
                cout << "You have entered information for customer number ";
                cout << maxCust << endl;
                maxCust++;
            break;
            
            // Change an existing account:
            case 2:
                // Get the cusomter number:
                cout << "Customer number: ";
                cin >> cust;
                
                // Validate the customer number:
                while(cust < 0 || cust >= maxCust)
                {
                    cout << "ERROR: Invalid Customer Number!\n";
                    cout << "Enter a valid customer number: ";
                    cin >> cust;
                }
                
                // Show the selected account:
                showInfo(account[cust]);
                
                // Get the new account information:
                cin.get();
                getInfo(account[cust]);
            break;
                
            // Display all account information:
            case 3:
                cin.get();
                for (count = 0; count < maxCust; count++)
                {
                    showInfo(account[count]);
                    cout << "Press enter to continue...";
                    cin.get();
                }
            break;
                
            // Search for a customer:
            case 4:
                cin.get();
                cout << "Enter part of the customer name: ";
                getline(cin, search);
                showSearch(account, search, maxCust);
            break;
        }
        
    } while (choice != 5);
    
    return 0;
}

// Function to get information:
void getInfo(Customer& c)
{
    // Get the customer name:
    cout << "\nCustomer name: ";
    getline(cin, c.name);
    while(c.name.empty())
    {
        cout << "You must enter a name.\n";
        getline(cin, c.name);
    }
    
    // Get the customer address:
    cout << "Customer address: ";
    getline(cin, c.address);
    while(c.address.empty())
    {
        cout << "You must enter an address.\n";
        getline(cin, c.address);
    }
    
    // Get the customer city:
    cout << "City: ";
    getline(cin, c.city);
    while(c.city.empty())
    {
        cout << "You must enter a city.\n";
        getline(cin, c.city);
    }
    
    // Get the customer state:
    cout << "State: ";
    getline(cin, c.state);
    while(c.state.empty())
    {
        cout << "You must enter a state.\n";
        getline(cin, c.state);
    }
    
    // Get the customer ZIP code:
    cout << "ZIP code: ";
    getline(cin, c.zip);
    while(c.zip.empty())
    {
        cout << "You must enter a ZIP code.\n";
        getline(cin, c.zip);
    }
    
    // Get the customer phone number:
    cout << "Telephone: ";
    getline(cin, c.phone);
    while(c.phone.empty())
    {
        cout << "You must enter a telephone number.\n";
        getline(cin, c.phone);
    }
    
    // Get the customer balance:
    cout << "Account Balance: ";
    cin >> c.balance;
    while(c.balance < 0)
    {
        cout << "Please enter 0 or greater for account balance.\n";
        cin >> c.balance;
    }
    
    // Get the date of the last payment:
    cin.get();
    cout << "Date of last payment: ";
    getline(cin, c.lastPay);
    while(c.lastPay.empty())
    {
        cout << "You must enter the date of the last payment.\n";
        getline(cin, c.lastPay);
    }
}

// Function to show information:
void showInfo(Customer c)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "Customer name: " << c.name << endl;
    cout << "Customer address: " << c.address << endl;
    cout << "City: : " << c.city << endl;
    cout << "State: " << c.state << endl;
    cout << "Zip: " << c.zip << endl;
    cout << "Telephone: " << c.phone << endl;
    cout << "Account Balance: $" << c.balance << endl;
    cout << "Date of last payment: " << c.lastPay << endl << endl;
}

// Function to show search:
void showSearch(Customer c[], string s, int max)
{
    bool found = false;
    
    for(int count = 0; count < max; count++)
    {
        if(c[count].name.find(s) != -1)
        {
            found = true;
            showInfo(c[count]);
        }
    }
    
    if (!found)
    {
        cout << "Record not found\n";
        cout << "Press enter to continue...";
        cin.get();
    }
}
