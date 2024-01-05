// Specification file for the ProductionWorker Class:
#ifndef ProductionWorker_h
#define ProductionWorker_h

#include "Employee.h"
#include <string>
using namespace std;

class ProductionWorker : public Employee {      // Inherit from parent class employee
private:
    int shift;          // The worker's shift
    double payRate;     // The worker's hourly pay rate (0 LOL)
    
public:
    // Default Constructor:
    ProductionWorker() : Employee()
    {
        shift = 0;
        payRate = 0.0;
    }
    
    // Constructor:
    ProductionWorker(string aName, string aNumber, string aDate, int aShift, double aPayRate)
    : Employee(aName, aNumber, aDate)
    {
        shift = aShift;
        payRate = aPayRate;
    }
    
    // Mutators:
    void setShift(int s)        {   shift = s;      }
    void setPayRate(double r)   {   payRate = r;    }
    
    // Accessors:
    int getShiftNumber() const  {   return shift;   }
    double getPayRate() const   {   return payRate; }
    
    string getShiftName() const
    {
        string shiftName = "";
        
        if(shift == 1)
            shiftName = "Day";
        else if(shift == 2)
            shiftName = "Night";
        else
            shiftName = "Invalid";
        
        return shiftName;
    }
};


#endif /* ProductionWorker_h */
