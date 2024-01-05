/*
 Name: Alejandro Diaz
 Date: 10/18/23
 Assignment: 15.7
 
 PersonData and CustomerData Classes
 */

#include <iostream>
#include "PersonData.h"
#include "CustomerData.h"
using namespace std;

// Function Prototypes:
void displayCustomer(CustomerData);

int main()
{
    // Create a CustomerData object and pass arguments:
    CustomerData customer1("Smith", "Joan", "123 Main Street", "Smithville", "NC", "99999", 12345, true);
    
    // Display the object's data:
    cout << "Customer #1\n" << "-----------\n";
    displayCustomer(customer1);
    
    // Create another CustomerData object using the default constructor and mutator functions:
    CustomerData customer2;
    customer2.setLastName("Jones");
    customer2.setFirstName("Jenny");
    customer2.setAddress("555 East Street");
    customer2.setCity("Jonesville");
    customer2.setState("VA");
    customer2.setZip("88888");
    customer2.setCustomerNumber(77777);
    customer2.setMailingList(false);
    
    // Display the object's data:
    displayCustomer(customer2);
    
    return 0;
}

// This function accepts a CustomerData object as its argument and displays the object's data:
void displayCustomer(CustomerData c)
{
    // Display all the data but mailing list:
    cout << "Troll" << endl;
    
    // Display Yes or No for mailing list:
}
