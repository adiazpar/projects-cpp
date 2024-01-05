// Implementation file for the PassFailActivity class:
#include "Essay.h"

/* ---------------------------------------------------- +
 |  set function:                                       |
 |  The parameters are the number of questions and the  |
 |  number of questions missed                          |
 + ---------------------------------------------------- */
void Essay::set(double setGram, double setSpel, double setLeng, double setCont)
{
    const short MAX_GRAMMAR = 30;
    const short MAX_SPELLING = 20;
    const short MAX_LENGTH = 20;
    const short MAX_CONTENT = 30;
    double numScore = 0;
    
    // Set all the member variables:
    
    if(setGram > MAX_GRAMMAR)   {   grammar = MAX_GRAMMAR;  }
    else                        {   grammar = setGram;      }
    
    if(setSpel > MAX_SPELLING)  {   spelling = MAX_SPELLING;    }
    else                        {   spelling = setSpel;         }
    
    if(setLeng > MAX_LENGTH)    {   length = MAX_LENGTH;    }
    else                        {   length = setLeng;       }
    
    if(setCont > MAX_CONTENT)   {   content = MAX_CONTENT;  }
    else                        {   content = setCont;      }
    
    // Calculate the score for this essay:
    numScore = grammar + spelling + length + content;
    
    // Call the inherited setScore function to set the numeric score:
    setScore(numScore);
}
