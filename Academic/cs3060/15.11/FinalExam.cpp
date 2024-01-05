// Implementation file for the FinalExam class:
#include "FinalExam.h"

/* ---------------------------------------------------- +
 |  Member function FinalExam::getLetterGrade           |
 |  This function returns 'P' if the score is passing.  |
 |  Otherwise, it returns 'F'.                          |
 + ---------------------------------------------------- */

char FinalExam::getLetterGrade() const
{
    char letterGrade;
    
    if (score >= minPassingScore)
        letterGrade = 'P';
    else
        letterGrade = 'F';
        
    return letterGrade;
}
