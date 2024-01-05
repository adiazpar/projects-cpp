/*
 Name: Alejandro Diaz
 Date: 09/20/23
 Assignment: 11.14
 
 Write a program that simulates inventory bins in a warehouse. Each bin holds a number of the same type of parts.
 The program should use a structure that keeps the following data:
 
    - Description of the part kept in the bin
    - Number of parts in the bin
 
 The program should have an array of 10 bins, initialized with the following data:
 
        ----------------------------------------------------------
        Part Description                Number of Parts in the Bin
        ----------------------------------------------------------
        Valve                           10
        Bearing                         5
        Bushing                         15
        Coupling                        21
        Flange                          7
        Gear                            5
        Gear Housing                    5
        Vacuum Gripper                  25
        Cable                           18
        Rod                             12
        ----------------------------------------------------------
 
 The program should have the following functions:
 
    - AddParts      : increases a specific bin's part count by a specified number           [v]
    - Removeparts   : decreases a specific bin's part count by a specified number           [x]
 
 When the program runs, it should repeat a loop that performs the folowing steps:
  - The user should see a list of what each bin holds and how many parts are in each bin.   [v]
  - The user can choose to either quit the program or select a bin.                         [v]
  - When a bin is selected, the user can either add parts to it or remove parts from it.    [v]
  - The loop then repeats, showing the updated bin data on the screen.                      [v]
 
 Input Validation: No bin can hold more than 30 parts, so don't let the user add more than a bin can hold.  [x]
 Also, don't accept negative values for the number of parts being added or removed.                         [x]
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Define Constants:
#define NUM_BINS 10
#define MAX_ITEMS 30
const string INIT_PARTS[] =  {"Valve", "Bearing", "Bushing", "Coupling", "Flange", "Gear", "Gear Hosuing", "Vacuum Gripper", "Cable", "Rod"};
const int INIT_AMNTS[] = {10, 5, 15, 21, 7, 5, 5, 25, 18, 12};

// Define Structure:
struct Bin
{
    string part;
    int amount;
};

// Function Prototypes:
void addParts(int *);       // Receives a pointer to amount of parts of the struct for comparisons
void removeParts(int *);    // Receives a pointer to amount of parts of the struct for comparisons
void setParts(int *);       // Receives a pointer to amount of parts of the struct for comparisons

void initBins(Bin *, size_t);
void printBins(Bin *, size_t);
void editSelectedBin(Bin&, const short);    // Passes a bin to edit

int main()
{
    // Initialize Main Program Variables:
    bool quit = false;
    int response = 0;
    
    // Array of Bins:
    Bin bins[NUM_BINS];
    initBins(bins, NUM_BINS);   // Initialize the bins array
    
    // Main program loop:
    do
    {
        // Display all bins with part descriptions and amounts:
        cout << "Welcome, here is a list of your current supplies: " << endl << endl;
        printBins(bins, NUM_BINS);
        
        cout << "Select a bin number to edit, or enter -1 to quit...\n" << "Your response: ";
        cin >> response;
        
        // I'm going to choose not to implement error checking for strings for now... fgets
        while(response != -1 && (response < 0 || response > NUM_BINS))
        {
            fflush(stdin);
            cout << "\nERROR: Please enter a valid option...\n" << "Your response: ";
            cin >> response;
        }
        
        if(response == -1)  {   quit = true;                                    }
        else                {   editSelectedBin(bins[response - 1], response);  }
    }
    while(!quit);
    
    cout << "\nYou have chosen to quit. Goodbye!" << endl;
    return 0;
}

// Function to initialize all bins with the data outlined in the problem:
void initBins(Bin *arrBins, size_t size)
{
    for(int bin = 0; bin < size; bin++)
    {
        arrBins[bin].part = INIT_PARTS[bin];
        arrBins[bin].amount = INIT_AMNTS[bin];
    }
}

// Function to print all bins in the warehouse:
void printBins(Bin *arrBins, size_t size)
{
    // Display the heading:
    cout << "\t----------------------------------------------" << endl;
    cout << "\t" << setw(15) << left << "Bin Number" << setw(25) << left << "Part Description" << setw(20) << left << "Amount" << endl;
    cout << "\t----------------------------------------------" << endl;
    
    for(int i = 0; i < size; i++)
    {
        cout << "\t" << setw(15) << left << i + 1 << setw(25) << left << arrBins[i].part << setw(20) << left << arrBins[i].amount << endl;
    }
    
    cout << "\t----------------------------------------------" << endl << endl;
}

// Function to edit selected bin:
void editSelectedBin(Bin &b, const short number)
{
    // Initialize local variables:
    int res = 0;
    int maxMenuOptions = 4;
    
    // Print the selected bin:
    cout << "\n\t...\n\t----------------------------------------------" << endl;
    cout << "\t" << setw(15) << left << "Bin Number" << setw(25) << left << "Part Description" << setw(20) << left << "Amount" << endl;
    cout << "\t----------------------------------------------" << endl;
    cout << "\t" << setw(15) << left << number << setw(25) << left << b.part << setw(20) << left << b.amount << endl << endl;
    
    // Print the menu options for bin alteration:
    cout << "\tYou have chosen to edit bin " << number << " containing " << b.amount << " " << b.part << "(s)." << endl;
    cout << "\tThe following options are: " << endl << endl;
    cout << "\t\t(1) Add " << b.part << "(s) to bin" << endl;
    cout << "\t\t(2) Remove " << b.part << "(s) from bin" << endl;
    cout << "\t\t(3) Set amount of " << b.part << "(s) in bin" << endl;
    cout << "\t\t(4) Go back to main menu" << endl << endl;
    
    // Get user input:
    cout << "\tPlease enter one of the following options...\n" << "\tYour response: ";
    cin >> res;
    
    // Validate user input: Worry about string inputs later, maybe use fgets
    while(res < 1 || res > maxMenuOptions)
    {
        fflush(stdin);
        cout << "\n\tERROR: Please enter a valid option...\n" << "\tYour response: ";
        cin >> res;
    }
    
    // Channel user input to menu:
    switch(res)
    {
        case 1:
            addParts(&b.amount);
            break;
            
        case 2:
            removeParts(&b.amount);
            break;
            
        case 3:
            setParts(&b.amount);
            break;
            
        case 4:
            cout << "\n\tReturning to main menu...\n";
            break;
    }
    
    cout << "\t...\n\n\n";
}

// Function to add desired amount of parts in bin:
void addParts(int *amnt)
{
    int additions = 0;
    
    // Prompt user to enter amount of parts to add:
    cout << "\n\t\t- This bin can hold " << MAX_ITEMS - *amnt << " more items." << endl;
    cout << "\t\t- Add: +";
    cin >> additions;
    
    // Validating user input:
    while(additions < 0 || additions > MAX_ITEMS - *amnt)
    {
        cout << "\n\t\t- ERROR: Please enter a valid amount..." << endl;
        cout << "\t\t- Add: +";
        cin >> additions;
    }
    
    *amnt += additions;
}

// Function to remove desired amount of parts in bin:
void removeParts(int *amnt)
{
    int subtractions = 0;
    
    // Prompt user to enter amount of parts to remove:
    cout << "\n\t\t- This bin currently has " << *amnt << " items." << endl;
    cout << "\t\t- Remove: -";
    cin >> subtractions;
    
    // Validating user input:
    while(subtractions < 0 || subtractions > *amnt)
    {
        cout << "\n\t\t- ERROR: Please enter a valid amount..." << endl;
        cout << "\t\t- Remove: -";
        cin >> subtractions;
    }
    
    *amnt -= subtractions;
}

// Function to set desired amount of parts in bin:
void setParts(int *amnt)
{
    int setTo = 0;
    
    // Prompt user to enter amount of parts to set to:
    cout << "\n\t\t- This bin currently has " << *amnt << " items." << endl;
    cout << "\t\t- Set: ";
    cin >> setTo;
    
    // Validating user input:
    while(setTo < 0 || setTo > MAX_ITEMS)
    {
        cout << "\n\t\t- ERROR: Please enter a valid amount..." << endl;
        cout << "\t\t- Set: ";
        cin >> setTo;
    }
    
    *amnt = setTo;
}
