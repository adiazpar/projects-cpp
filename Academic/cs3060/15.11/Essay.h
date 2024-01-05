// Specification file for Essay class:
#ifndef Essay_h
#define Essay_h

#include "PassFailActivity.h"

class Essay : public PassFailActivity {
private:
    double grammar;
    double spelling;
    double length;
    double content;
    
public:
    // Default Constructor:
    Essay() : PassFailActivity()
    {
        grammar     = 0;
        spelling    = 0;
        length      = 0;
        content     = 0;
    }
    
    // Parameterized Constructor:
    Essay(double gram, double spel, double leng, double cont, double mps) : PassFailActivity(mps)
    {
        set(gram, spel, leng, cont);
    }
    
    // Mutator Functions:
    void set(double, double, double, double);   // Defined in the cpp file
    
    // Accessor Functions:
    double getGrammar() const   {   return grammar;     }
    double getSpelling() const  {   return spelling;    }
    double getLength() const    {   return length;      }
    double getContent() const   {   return content;     }
    
    // Virtual Function to get letter grade:
    virtual char getLetterGrade() const;
    
};

#endif /* Essay_h */






















// Class notes 10/23/23
// A copy constructor initializes members of a newly created object
// It copies the members of an already existing object, it takes a reference
// of an object to the same class

// When the compiler sees the single colon (:), we are telling the compiler that
// the class on the left side of the colon is inheriting from the class
// on the right side of the colon

// What is a parameterized constructor?
// If a constructor has a set amount of arguments, we can say that it is
// paramaterized.

// This is a VS to a default constructor...
// IT ALL MAKES SENSE NOW AHHHHHHHHHHHHHH


// EXPLICIT CONSTRUCTOR:
// Gallons g = Gallons(20);

// IMPLICIT CONSTRUCTOR:
// Gallons g(20);

// When coding objective C for iPhones, you must always use destructors
// There is no memory management in objective C, you must do it yourself

// Do not go to Stack Overflow ans ask about this stuff, you will enter an
// endless rabbit hole

/*
 VIRTUAL FUNCTIONS:
 
 Virtual functions are declared by placing the key word virtual before the return type
 in the base class's function declaration, such as
 
    virtual char getLetterGrade() const;
 
 This declaration tells the compiler
 */
