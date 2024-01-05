/*
 Name: Alejandro Diaz
 Date: 08/30/23
 Assignment: 7.5
 
 Monkey Business
 A local zoo wants to keep track of how many pounds of food each of its three monkeys eats each day
 during a typical week. Write a program that stores this information in a two-dimensional 3 x 5
 array, where each row represents a different monkey, and each column represents a different day of
 the week. The program should first have the user input the data for each monkey. Then, it
 should create a report that includes the following information:
 
    • Average amount of food eaten per day by the whole family of monkeys.
    • The least amount of food eaten during the week by any one monkey.
    • The greatest amount of food eaten during the week by any one monkey.

 Input Validation: Do not accept negative numbers for pounds of food eaten.
 */

#include<iostream>
#include<iomanip>
using namespace std;

// Constants:
const int MONKEYS = 3;
const int DAYS = 5;

// Function Prototypes:
void getFoodEaten(double[][DAYS]);
void displayAverageDaily(double[][DAYS]);
void displayLeastEaten(double[][DAYS]);
void displayMostEaten(double[][DAYS]);

int main()
{
    // Array to hold the monkey data:
    double food[MONKEYS][DAYS];
    
    // Get the amount eaten:
    getFoodEaten(food);
    
    // Display the average amount eaten daily by each monkey:
    displayAverageDaily(food);
    
    // Display the least amount eaten in a day by any one monkey:
    displayLeastEaten(food);
    
    // Display the most eaten in a day by any one monkey:
    displayMostEaten(food);
    
    return 0;
}

void getFoodEaten(double food[][DAYS])
{
    for(int monkey = 0; monkey < MONKEYS; monkey++)
    {
        for(int day = 0; day < DAYS; day++)
        {
            // Get the amount eaten by this mokey on this day:
            cout << "Enter the pounds eaten by monkey " << "number " << (monkey + 1)
            << "\non day " << (day + 1) << ":";
            cin >> food[monkey][day];
            
            // Validate the input:
            while(food[monkey][day] < 0)
            {
                cout << "Enter a non-negative amount: ";
                cin >> food[monkey][day];
            }
        }
    }
}

void displayAverageDaily(double food[][DAYS])
{
    double total;       // Accumulator
    double average;     // Average eaten
    
    for(int day = 0; day < DAYS; day++)
    {
        // Inititalize the accumulator:
        total = 0.0;
        
        // Get the total eaten by the monkey in this day:
        for(int monkey = 0; monkey < MONKEYS; monkey++)
        {
            total += food[monkey][day];
        }
        
        // Calculate the average eaten:
        average = total / MONKEYS;
        
        // Display the average:
        cout << "The average amount eaten on day " << (day + 1) << " is" << average << "pounds.\n";
        
    }
}

void displayLeastEaten(double food[][DAYS])
{
    double leastFood;       // To hold the least amount
    int leastMonkey;        // The monkey eating the least
    int leastDay;           // The day with the least
    
    // Assume the least amount was eaten on the first day by the first monkey:
    leastMonkey = 0;
    leastDay = 0;
    leastFood = food[leastMonkey][leastDay];
    
    // Step through the array comparing the values:
    for(int monkey = 0; monkey < MONKEYS; monkey++)
    {
        for(int day = 0; day < DAYS; day++)
        {
            if(food[monkey][day] < leastFood)
            {
                leastFood = food[monkey][day];
                leastDay = day;
                leastMonkey = monkey;
            }
        }
        
        // Display the results:
        cout << "Monkey number " << (leastMonkey + 1) << " ate the least:\n"
        << "They ate " << leastFood << "pounds, on day " << (leastDay + 1) << endl;
    }
}

void displayMostEaten(double food[][DAYS])
{
    double mostFood;       // To hold the most amount
    int mostMonkey;        // The monkey eating the most
    int mostDay;           // The day with the most
    
    // Assume the least amount was eaten on the first day by the first monkey:
    mostMonkey = 0;
    mostDay = 0;
    mostFood = food[mostMonkey][mostDay];
    
    // Step through the array comparing the values:
    for(int monkey = 0; monkey < MONKEYS; monkey++)
    {
        for(int day = 0; day < DAYS; day++)
        {
            if(food[monkey][day] > mostFood)
            {
                mostFood = food[monkey][day];
                mostDay = day;
                mostMonkey = monkey;
            }
        }
        
        // Display the results:
        cout << "Monkey number " << (mostMonkey + 1) << " ate the most:\n"
        << "They ate " << mostFood << "pounds, on day " << (mostDay + 1) << endl;
    }
}
