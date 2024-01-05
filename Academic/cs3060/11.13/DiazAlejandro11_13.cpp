/*
 Name: Alejandro Diaz
 Date: 09/20/23
 Assignment: 11.13
 
 Write a program that simulates a soft drink machine. The program should use a structure that stores the following data:
     - Drink Name
     - Drink Cost
     - Number of Drinks in Machine
 
 The program should create an array of five structures. The elements should be initialized with the following data:
 
        ---------------------------------------------
        Drink Name      Cost        Number in Machine
        ---------------------------------------------
        Cola            .75         20
        Root Beer       .75         20
        Lemon-Lime      .75         20
        Grape Soda      .80         20
        Cream Soda      .80         20
        ---------------------------------------------
 
 Each time the program runs, it should enter a loop that performs the following steps:
  - A list of drinks is displayed on the screen. The user should be allowed to either quit the program or pick a drink.
  - If the user selects a drink, he or she will next enter the amount of money that is to be inserted into the drink machine.
  - The program should display the amount of change that would be returned, and subtract one from the number of that drink left in the machine.
  - If the user selects a drink that has sold out, a message should be displayed.
  - The loop then repeats. When the user chooses to quit the program, it should display the total amount of money the machine earned.
 
 Input Validation: When the user enters an amount of money, do not accept negative values or values greater than $1.00.
 */

// THIS PROGRAM HAS BEEN COMPLETED IN CLASS:
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

// Constants for array:
#define NUM_DRINKS 5

// Declaring the drink structure:
struct Drink
{
    string name;        // Drink Name
    double price;       // Price of the drink
    int num;            // Number of cans in the machine
};

// Function prototypes:
int getChoice(Drink []);
void transaction(Drink [], int, double &);      // Drink, choice #, earnings


// Main function for main program loop:
int main()
{
    // Menu choice:
    int choice;
    
    // Drink machine earnings:
    double earnings = 0;
    
    // Array of drinks in the machine:
    Drink machine[NUM_DRINKS] = {
        {"Cola\t\t", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };
    
    // Set the floating-point output formatting:
    cout << fixed << showpoint << setprecision(2);
    
    // Display the menu and process the user's choice:
    choice = getChoice(machine);
    while(choice != 5)
    {
        // Process the transaction:
        transaction(machine, choice, earnings);
        
        // Get the next choice:
        choice  = getChoice(machine);
    }
    
    // Display the machine's total earnings:
    cout << "Total earnings: $" << earnings << endl;
    return 0;
}

// Function to get the user choice from main:
int getChoice(Drink m[])
{
    // The user's choice
    int choice;
    cout << endl;
    
    // Display a list of drinks preceded by a number
    // This will be the mennu:
    for(int x = 0; x < NUM_DRINKS; x++)
    {
        cout << (x+1) << ") " << m[x].name << "\t\t";
        cout << m[x].price << endl;
    }
    
    // Display the last menu item, which is to leave the drink machine:
    cout << (NUM_DRINKS + 1) << ") Leave the drink machine \n\n";
    
    // Get the user's choice:
    cout << "Choose one: ";
    cin >> choice;
    
    // Validate the choice:
    while(choice < 1 || choice > 6)
    {
        cout << "Bad choice. Choose one: ";
        cin >> choice;
    }
    
    // Return the choice, as a subscript into the array of drinks:
    return choice - 1;
    
    return 0;
}

// Function to process the transaction:
void transaction(Drink m[], int choice, double &earnings)
{
    // The amount of money tendered:
    double money;
    
    // If the selected drink is sold out, display a message and get out of this function:
    if(m[choice].num == 0)
    {
        cout << "Sorry, that selection is sold out.\n";
        return;
    }
    
    // Get some money from the customer:
    cout << "Enter an amount of money: ";
    cin >> money;
    
    // Make sure the customer entered at least enough for the selected drink, and no more than $1.00:
    while(money < m[choice].price || money > 1.0)
    {
        cout << "Enter at least " << m[choice].price;
        cout << " and not more than 1 dollar. \n";
        cin >> money;
    }
    
    // Process the selection and give back any change that is due:
    if (money >= m[choice].price)
    {
        // Dispense the drink:
        cout << "\nThump, thump, thump, splat!\n" << "Enjoy your beverage!\n\n";
        
        // Calculate any change that is due:
        cout << "Change calculated: " << (money - m[choice].price) << endl;
        
        // If change is due, give it to the customer:
        if((money - m[choice].price) > 0)
        {
            cout << "Your change, " << (money - m[choice].price) << " has just dropped into the Change Dispenser.\n\n";
        }
        
        // Update our earnings:
        earnings += m[choice].price;
        
        // Decrease the number of cans of the selected drink currently in the machine:
        m[choice].num--;
        
        // Display the number of cans of this drink currently in the machine:
        cout << "There are " << m[choice].num << " drinks of that type left.\n";
    }
    
}


/*
 PASS BY REFERENCE / POINTER (ADDRESS):
  - If you declare a formal parameter of a function as a pointer type, you are passing that parameter by its address
  - The pointer is copied, but not the data it points to
  - So, pass by address allows us to change the original argument of a functions - we don't pass in the argument itself -- just pass its address
 */
