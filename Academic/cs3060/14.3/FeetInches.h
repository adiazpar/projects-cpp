// Specification file for the FeetInches class:
#ifndef FeetInches_h
#define FeetInches_h

#include <iostream>
using namespace std;

class FeetInches;   // Forward Declaration

// Function prototypes for overloaded Stream operators:
ostream& operator << (ostream&, const FeetInches&);         // I don't understand this
istream& operator << (istream&, FeetInches&);

// The FeetInches class holds distances or measurements expressed in feet and inches
class FeetInches {
private:
    int feet;           // To hold a number of feet
    int inches;         // To hold a number of inches
    void simplify();    // Defined in FeetInches.cpp
    
public:
    // Constructor:
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }
    
    // Copy Constructor:
    FeetInches(FeetInches& right)
    {
        feet = right.feet;
        inches = right.inches;
    }
    
    // Mutator Functions:
    void setFeet(int f)     {   feet = f;               }
    void setInches(int i)   {   inches = i; simplify(); }
    
    // Accessor Functions:
    int getFeet() const     {   return feet;    }
    int getInches() const   {   return inches;  }
    
    // A function I made to bypass private stuff:
    void doSimplify()
    {
        simplify();
    }
    
    
    // Multiply Function:
    FeetInches multiply(FeetInches obj)
    {
        FeetInches temp;
        temp.feet = feet * obj.feet;
        temp.inches = inches * obj.inches;
        temp.simplify();
        return temp;
    }
    
    // Overloaded Operator Functions:
    FeetInches operator + (const FeetInches&);      // I don't understand any of these section either
    FeetInches operator - (const FeetInches&);
    FeetInches operator ++ ();      // Prefix ++
    FeetInches operator ++ (int);   // Postfix ++
    bool operator > (const FeetInches&);
    bool operator < (const FeetInches&);
    bool operator == (const FeetInches&);
    
    // New operators:
    bool operator >= (const FeetInches&);
    bool operator <= (const FeetInches&);
    bool operator != (const FeetInches&);
    
    // Conversion Functions:
    operator double();
    operator int();
    
    // Friends:
    friend ostream& operator << (ostream&, const FeetInches&);      // WTF??
    friend istream& operator << (istream&, const FeetInches&);
};

#endif

/*
 After researching what the above functions do, write notes here:
 
 */


