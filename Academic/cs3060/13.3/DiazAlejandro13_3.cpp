/*
 Name: Alejandro Diaz
 Date: 10/04/23
 Assignment: 13.3
 
 Write a class named Car that has the following member variables:
 
    yearModel   :   an int that holds the car's year model
    make        :   a string that holds the make of the car
    speed       :   an int that holds the car's current speed
 
 */

#include <iostream>
#include <string>
using namespace std;

// Car class declaration:
class Car
{
private:
    int yearModel;
    string make;
    int speed;
    
public:
    // Constructor:
    Car(int y, string m)
    {
        yearModel = y;
        make = m;
        speed = 0;
    }
    
    // Accelerate Function:
    void accelerate()
    {
        speed += 5;
    }
    
    // Brake Function:
    void brake()
    {
        speed -= 5;
    }
    
    // Accessor Functions:
    int getYearModel()  {   return yearModel;   }
    string getMake()    {   return make;        }
    int getSpeed()      {   return speed;       }
};

int main()
{
    // Create a car object:
    Car porsche(2006, "Porsche");
    
    // Display the current speed:
    cout << "Current speed: " << porsche.getSpeed() << endl;
    
    // Accelerate five times:
    for (int i = 0; i < 5; i++)
    {
        // Accelerate and display the speed:
        cout << "Accelerating...\n";
        porsche.accelerate();
        cout << "Current speed: " << porsche.getSpeed() << endl;
    }
    
    // Breake five times:
    for (int i = 0; i < 5; i++)
    {
        // Brake and display the speed:
        cout << "Braking...\n";
        porsche.brake();
        cout << "Current speed: " << porsche.getSpeed() << endl;
    }
    
    
    return 0;
}

