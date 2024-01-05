/*
 Name: Alejandro Diaz
 Date: 09/16/23
 Assignment: 11.11
 
 A student has established the following monthly budget:
 
    Housing                 $500.00
    Utilities               $150.00
    Household Expenses      $65.00
    Transportation          $50.00
    Food                    $250.00
    Medical                 $30.00
    Insurance               $100.00
    Entertainment           $150.00
    Clothing                $75.00
    Miscellaneous           $50.00
 
 Write a program that has a MonthlyBudget structure designed to hold each of these expense categories.
 The program should pass the structure to a function that asks the user to enter the amounts spent
 in each budget category during a month.
 
 The program should then pass the structure to a function that displays a report indicating
 the amount over or under in each category, as well as the amount over or under for the entire monthly budget.
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Constants:
#define HOUSING 500.0
#define UTIL 150.0
#define HOUSEHOLD 65.0
#define TRANSPORT 50.0
#define MEDICAL 30.0
#define INSURANCE 100.0
#define ENTERTAINMENT 150.0
#define CLOTHING 75.0
#define MISC 50.0

// Structure:
struct MonthlyBudget
{
    double houseing;
    double util;
    double household;
    double transport;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double misc;
};

// Function Prototype:
void getMonthlyBudget(MonthlyBudget&);
void displayMonthlyReport(const MonthlyBudget&);

int main(void)
{
    // Create a monthlybudget variable:
    MonthlyBudget budget;
    
    // Populate the bariable with data:
    getMonthlyBudget(budget);
    
    // Display a budget report:
    displayMonthlyReport(budget);
    
    return 0;
}

void getMonthlyBudget(MonthlyBudget& mb)
{
    // Get the amount spent for housing:
    cout << "Enter the amount spent for housing: ";
    cin >> mb.houseing;
    
    // Get the amount spent for utilities:
    cout << "Enter the amount spent for utilities: ";
    cin >> mb.util;
    
    // Get the amount spent for household expenses:
    cout << "Enter the amount spent for household expenses: ";
    cin >> mb.household;
    
    // Get the amount spent for transportation:
    cout << "Enter the amount spent for transportation: ";
    cin >> mb.transport;
    
    // Get the medical expenses:
    cout << "Enter the medical expenses: ";
    cin >> mb.medical;
    
    // Get the amount spent for insurance:
    cout << "Enter the amount spent for insurance: ";
    cin >> mb.insurance;
    
    // Get the amount spent for entertainment:
    cout << "Enter the amount spent for entertainment: ";
    cin >> mb.entertainment;
    
    // Get the amount spent for clothing:
    cout << "Enter the amount spent for clothing: ";
    cin >> mb.clothing;
    
    // Get the misc. expenses:
    cout << "Enter the miscellaneous expenses: ";
    cin >> mb.misc;
}

void displayMonthlyReport(const MonthlyBudget& mb)
{
    // The overUnder variable holds the amount that the student is
    // over or under budget:
    double overUnder = 0.0;
    
    // Set up the floating-point formatting:
    cout << setprecision(2) << fixed << showpoint;
    
    // Display the report headings:
    cout << setw(18) << left << "\nCategory"
    << setw(10) << right << "Budgeted"
    << setw(10) << right << "Spent"
    << setw(16) << right << "Over(-)/Under" << endl;
    cout << "-----------------------------------"
    << "------------------\n";
    
    // Get the budget amounts for housing: ----------------------
    cout << setw(18) << left << "Housing"
    << setw(10) << right << HOUSING
    << setw(10) << right << mb.houseing
    << setw(16) << right << (HOUSING - mb.houseing) << endl;
    
    // Update the over/under amount:
    overUnder += (HOUSING - mb.houseing);
    
    
    // Get the budget amounts for utilities: --------------------
    cout << setw(18) << left << "Utilities"
    << setw(10) << right << UTIL
    << setw(10) << right << mb.util
    << setw(16) << right << (UTIL - mb.util) << endl;
    
    // Update the over/under amount:
    overUnder += (UTIL - mb.util);
    
    
    // Get the budget amounts for household expenses: -----------
    cout << setw(18) << left << "Housing"
    << setw(10) << right << HOUSING
    << setw(10) << right << mb.houseing
    << setw(16) << right << (HOUSING - mb.houseing) << endl;
    
    // Update the over/under amount:
    overUnder += (HOUSING - mb.houseing);
    
    
    // Get the budget amounts for transportation: ---------------
    cout << setw(18) << left << "Transportation"
    << setw(10) << right << TRANSPORT
    << setw(10) << right << mb.transport
    << setw(16) << right << (TRANSPORT - mb.transport) << endl;
    
    // Update the over/under amount:
    overUnder += (TRANSPORT - mb.transport);
    
    
    // Get the budget amounts for medical: ----------------------
    cout << setw(18) << left << "Medical"
    << setw(10) << right << MEDICAL
    << setw(10) << right << mb.medical
    << setw(16) << right << (MEDICAL - mb.medical) << endl;
    
    // Update the over/under amount:
    overUnder += (MEDICAL - mb.medical);
    
    
    // Get the budget amounts for insurance: --------------------
    cout << setw(18) << left << "Insurance"
    << setw(10) << right << INSURANCE
    << setw(10) << right << mb.insurance
    << setw(16) << right << (INSURANCE - mb.insurance) << endl;
    
    // Update the over/under amount:
    overUnder += (INSURANCE - mb.insurance);
    
    
    // Get the budget amounts for entertainment: ----------------
    cout << setw(18) << left << "Entertainment"
    << setw(10) << right << ENTERTAINMENT
    << setw(10) << right << mb.entertainment
    << setw(16) << right << (ENTERTAINMENT - mb.entertainment) << endl;
    
    // Update the over/under amount:
    overUnder += (ENTERTAINMENT - mb.entertainment);
    
    
    // Get the budget amounts for clothing: ---------------------
    cout << setw(18) << left << "Clothing"
    << setw(10) << right << CLOTHING
    << setw(10) << right << mb.clothing
    << setw(16) << right << (CLOTHING - mb.clothing) << endl;
    
    // Update the over/under amount:
    overUnder += (CLOTHING - mb.clothing);
    
    
    // Get the budget amounts for misc: -------------------------
    cout << setw(18) << left << "Miscellaneous"
    << setw(10) << right << MISC
    << setw(10) << right << mb.misc
    << setw(16) << right << (MISC - mb.misc) << endl;
    
    // Update the over/under amount:
    overUnder += (MISC - mb.misc);
    
    
    // Display the amount over/under budget for the entire month:
    if(overUnder >= 0)
    {
        cout << "For the month you are under budget by $" << overUnder << endl;
    }
    else
    {
        cout << "For the month you are over budget by $" << overUnder << endl;
    }
}
