// Specification file for the Employee class:
#ifndef Employee_h
#define Employee_h

#include <string>
using namespace std;

// Design a class named Employee:
class Employee {
private:
    string name;        // Employee Name
    string number;      // Employee Number
    string hireDate;    // Employee Hire Date
    
public:
    // Default Constructor:
    Employee()
    {
        name = ""; 
        number = "";
        hireDate = "";
    }
    
    // Constructor:
    Employee(string aName, string aNumber, string aDate)
    {
        name = aName;
        number = aNumber;
        hireDate = aDate;
    }
    
    // Mutators:
    void setName(string n)          {   name = n;           }
    void setNumber(string num)      {   number = num;       }
    void setHireDate(string date)   {   hireDate = date;    }
    
    // Accessors:
    string getName() const      {   return name;        }
    string getNumber() const    {   return number;      }
    string getHireDate() const  {   return hireDate;    }
    
};
#endif
