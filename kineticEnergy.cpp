#include <iostream>
using namespace std;

// Function prototype
double getKineticEnergy(double, double);

int main()
{
    // Variables
    double mass;        // To hold the object's mass
    double velocity;    // To hold the object's velocity

    // Get the object's mass
    cout << "Please enter the object's mass: ";
    cin >> mass;

    // Get the object's velocity
    cout << "Please enter the object's velocity (m/s): ";
    cin >> velocity;

    // Display the objects kinetic energy
    cout << "The object's kinetic energy is "
    << getKineticEnergy(mass, velocity)
    << "joules.\n";

    return 0;
}

double getKineticEnergy(double mass, double vel)
{
    return 0.5 * mass * vel * vel;
}