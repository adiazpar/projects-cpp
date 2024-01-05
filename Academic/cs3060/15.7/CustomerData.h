// Specification file for the CustomerData class:
#ifndef CustomerData_h
#define CustomerData_h

#include "PersonData.h"
#include <string>
using namespace std;

// Design a class named CustomerData derived from PersonData:
class CustomerData : public PersonData {
private:
    int customerNumber;     // Customer Number
    bool mailingList;       // Include in mailing list?
    
public:
    // Constructor:
    CustomerData(string ln, string fn, string addr, string c, string s, string z, int cn, bool ml)
    : PersonData(ln, fn, addr, c, s, z)
    {
        customerNumber = cn;
        mailingList = ml;
    }
    
    // Default Constructor:
    CustomerData() : PersonData()
    {
        customerNumber = 0;
        mailingList = false;
    }
    
    // Mutators:
    void setCustomerNumber(int cn)  {   customerNumber = cn;    }
    void setMailingList(bool ml)    {   mailingList = ml;       }
    
    // Accessors:
    int getCustomerNumber() {   return customerNumber;  }
    bool getMailingList()   {   return mailingList;     }
};


#endif /* CustomerData_h */
