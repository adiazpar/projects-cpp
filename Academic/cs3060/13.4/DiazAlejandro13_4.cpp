/*
 Name: Alejandro Diaz
 Date: 10/04/23
 Assignment: 13.4
 
 |  PART 1:
 |  Write a class named Patient that has member variables for the following data:
 |
 |      • First name, middle name, last name
 |      • Address, city, state, and ZIP code
 |      • Phone number
 |      • Name and phone number of emergency contact
 |
 |  The Patient class should have a constructor that accepts an argument for each member variable.
 |  The Patient class should also have accessor and mutator functions for each member variable.
 [V]
 
 |  PART 2:
 |  Next, write a class named Procedure that represents a medical procedure that has been performed on a patient.
 |  The Procedure class should have member variables for the following data:
 |
 |      • Name of the procedure
 |      • Date of the procedure
 |      • Name of the practitioner who performed the procedure
 |      • Charges for the procedure
 |
 |
 |  The Procedure class should have a constructor that accepts an argument for each member variable.
 |  The Procedure class should also have accessor and mutator functions for each member variable.
 [V]
 
 |  PART 3:
 |  Next, write a program that creates an instance of the Patient class, initialized with sample data.
 |  Then, create three instances of the Procedure class, initialized with the following data:
 |
 |      Procedure #1:                       Procedure #2:                       Procedure #3:
 |      Procedure name: Physical Exam       Procedure name: X-ray               Procedure name: Blood test
 |      Date: Today's date                  Date: Today's date                  Date: Today's date
 |      Practitioner: Dr. Irvine            Practitioner: Dr. Jamison           Practitioner: Dr. Smith
 |      Charge: 250.00                      Charge: 500.00                      Charge: 200.00
 |
 |  The program should display the patient's information, information about all three
 |  of the procedures, and the total charges of the three procedures.
 [X]
 
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Patient Class:
class Patient {
private:
    string fullname;
    string address, city, state, zip;
    string phone;
    string emergencyName;
    string emergencyPhone;
    
public:
    // Constructor for Patient objects:
    Patient(string fn, string ad, string ct, string st, string zp, string ph, string en, string ep)
    {
        fullname = fn;
        address  = ad;
        city  = ct;
        state = st;
        zip   = zp;
        phone = ph;
        emergencyName  = en;
        emergencyPhone = ph;
    }
    
    // Accessors (GETTERS):
    string getFullName()    {   return fullname;    }
    
    string getAddress()     {   return address; }
    string getCity()        {   return city;    }
    string getState()       {   return state;   }
    string getZip()         {   return zip;     }
    string getPhone()       {   return phone;   }
    
    string getEmergencyName()   {   return emergencyName;   }
    string getEmergencyPhone()  {   return emergencyPhone;  }
    
    // Mutators (SETTERS):
    void setFullName(string in)     {   fullname = in;  }
    
    void setAddress(string in)      {   address = in;   }
    void setCity(string in)         {   city    = in;   }
    void setState(string in)        {   state   = in;   }
    void setZip(string in)          {   zip     = in;   }
    void setPhone(string in)        {   phone   = in;   }
    
    void setEmergencyName(string in)    {   emergencyName = in;     }
    void setEmergencyPhone(string in)   {   emergencyPhone = in;    }
};

// Procedure class, which represents a medical procedure that has been performed on a patient:
class Procedure {
private:
    string procedureName;
    string procedureDate;
    string doctor;
    double charges;
    
public:
    // Constructor for Precedure objects:
    Procedure(string pN, string pD, string doc, double ch)
    {
        procedureName = pN;
        procedureDate = pD;
        doctor = doc;
        charges = ch;
    }
    
    // Accessors (GETTERS):
    string getProcedureName()   {   return procedureName;   }
    string getProcedureDate()   {   return procedureDate;   }
    string getDoctor()          {   return doctor;          }
    double getCharges()         {   return charges;         }
    
    // Mutators (SETTERS):
    void setProcedureName(string in)    {   procedureName = in;     }
    void setProcedureDate(string in)    {   procedureDate = in;     }
    void setDoctor(string in)           {   doctor = in;            }
    void setCharges(double in)          {   charges = in;           }
};


/*
 |  PART 3:
 |  Next, write a program that creates an instance of the Patient class, initialized with sample data.
 |  Then, create three instances of the Procedure class, initialized with the following data:
 |
 |      Procedure #1:                       Procedure #2:                       Procedure #3:
 |      Procedure name: Physical Exam       Procedure name: X-ray               Procedure name: Blood test
 |      Date: Today's date                  Date: Today's date                  Date: Today's date
 |      Practitioner: Dr. Irvine            Practitioner: Dr. Jamison           Practitioner: Dr. Smith
 |      Charge: 250.00                      Charge: 500.00                      Charge: 200.00
 
 The program should display the patient's information, information about all three
 of the procedures, and the total charges of the three procedures.
 */

// Function Prototypes:
void displayPatientInformation(Patient);
void displayAllProcedures(Procedure, Procedure, Procedure);

// Main function for the main program loop:
int main()
{
    Patient patient1("Bill Buttlicker", "1725 Slough Ave", "Scranton", "PA", "18505-7427", "212-555-2098", "Michael Scott", "212-555-2102");
    Procedure procedure1("Physical Exam", "October 5th, 2023", "Dr. Irvine", 250.00);
    Procedure procedure2("X-ray", "October 5th, 2023", "Dr. Jamison", 500.00);
    Procedure procedure3("Blood test", "October 5th, 2023", "Dr. Smith", 200.00);
    
    displayPatientInformation(patient1);
    displayAllProcedures(procedure1, procedure2, procedure3);
    
    return 0;
}

void displayPatientInformation(Patient p)
{
    cout << "PATIENT INFORMATION: " << endl;
    cout << "Name:\t\t" << p.getFullName() << endl;
    cout << "Address:\t" << p.getAddress() << ", " << p.getCity() << " " << p.getState() << ", " << p.getZip() <<  endl;
    cout << "Phone:\t\t" << p.getPhone() << endl << endl;
    cout << "Emergency Contact:\t" << p.getEmergencyName() << ", " << p.getEmergencyPhone() << endl << endl;
}

void displayAllProcedures(Procedure p1, Procedure p2, Procedure p3)
{
    // Set the floating-point output formatting:
    cout << fixed << showpoint << setprecision(2);
    
    cout << "------------------------------------------------------------------" << endl;
    cout << "PROCEDURE(S) INSIGHTS:" << endl << endl;
    cout << setw(25) << left << "Procedure #1" << setw(25) << left << "Procedure #2" << setw(25) << left << "Procedure #3" << endl;
    cout << setw(25) << left << p1.getProcedureName() << setw(25) << left << p2.getProcedureName() << setw(25) << left << p3.getProcedureName() << endl;
    cout << setw(25) << left << p1.getProcedureDate() << setw(25) << left << p2.getProcedureDate() << setw(25) << left << p3.getProcedureDate() << endl;
    cout << setw(25) << left << p1.getDoctor() << setw(25) << left << p2.getDoctor() << setw(25) << left << p3.getDoctor() << endl;
    cout << setw(25) << left << p1.getCharges() << setw(25) << left << p2.getCharges() << setw(25) << left << p3.getCharges() << endl;
    cout << "------------------------------------------------------------------" << endl << endl;
}
