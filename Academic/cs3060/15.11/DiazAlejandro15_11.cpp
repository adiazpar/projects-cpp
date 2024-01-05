/* -------------------------------------------------------------------------------------------- +
 |                                                                                              |
 |  Name: Alejandro Diaz                                                                        |
 |  Date: 10/22/23                                                                              |
 |  Assignment: 15.11                                                                           |
 |                                                                                              |
 |  Course Grades                                                                               |
 |  In a course, a teacher gives the following tests and assignments:                           |
 |                                                                                              |
 |      - A lab activity that is observed by the teacher and assigned a numeric score.          |
 |      - A pass/fail exam that has ten questions. The minimum passing score is 70.             |
 |      - An essay that is assigned a numeric score.                                            |
 |      - A final exam that has 50 questions.                                                   |
 |                                                                                              |
 |  Write a class named CourseGrades. The class should have a member named grades that is an    |
 |  array of GradedActivity pointers. The grades array should have four elements, one for       |
 |  each of the assignments previously described.                                               |
 |                                                                                              |
 |  The class should have the following member functions:                                       |
 |                                                                                              |
 |  setLab:                This function should accept the address of a GradedActivity object   |
 |                         as its argument. This object should already hold the student's       |
 |                         score for the lab activity. Element 0 of the grades array should     |
 |                         reference this object.                                               |
 |                                                                                              |
 |  setPassFailExam:       This function should accept the address of a PassFailExam object     |
 |                         as its argument. This object should already hold the student's       |
 |                         score for the pass/fail exam. Element 1 of the grades array          |
 |                         should reference this object.                                        |
 |                                                                                              |
 |  setEssay:              This function should accept the address of an Essay object as its    |
 |                         argument. (See Programming Challenge 6 for the Essay class.          |
 |                         If you have not completed Programming Challenge 6, use a             |
 |                         GradedActivity object instead.) This object should already hold      |
 |                         the student's score for the essay. Element 2 of the grades           |
 |                         array should reference this object.                                  |
 |                                                                                              |
 |  setPassFailExam:       This function should accept the address of a FinalExam object        |
 |                         as its argument. This object should already hold the student's       |
 |                         score for the final exam. Element 3 of the grades array              |
 |                         should reference this object.                                        |
 |                                                                                              |
 |  print:                 This function should display the numeric scores and grades for       |
 |                         each element in the grades array.                                    |
 |                                                                                              |
 |  Demonstrate the class in a program.                                                         |
 |                                                                                              |
 + -------------------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;

// Including Header Files:
#include "PassFailExam.h"
#include "Essay.h"
#include "FinalExam.h"

// -------------------------------------------------------------------------------------------- |

class CourseGrades {
public:
    GradedActivity *grades[4];
    
public:
    // Default Constructor:
    CourseGrades()
    {
        grades[0] = 0;
        grades[1] = 0;
        grades[2] = 0;
        grades[3] = 0;
    }
    
    // Accessor Functions:
    GradedActivity getLab()     {   return *grades[0];   }
    GradedActivity getExam()    {   return *grades[1];   }
    GradedActivity getEssay()   {   return *grades[2];   }
    GradedActivity getFinal()   {   return *grades[3];   }
    
    // Mutator Functions:
    /* -------------------------------------------------------------------- +
     |  This function should accept the address of a GradedActivity object  |
     |  as its argument. This object should already hold the student's      |
     |  score for the lab activity. Element 0 of the grades array should    |
     |  reference this object.                                              |
     + -------------------------------------------------------------------- */
    void setLab(GradedActivity *lab)
    {
        grades[0] = lab;
    }
    
    /* -------------------------------------------------------------------- +
     |  This function should accept the address of a PassFailExam object    |
     |  as its argument. This object should already hold the student's      |
     |  score for the pass/fail exam. Element 1 of the grades array         |
     |  should reference this object.                                       |
     + -------------------------------------------------------------------- */
    void setPassFailExam(PassFailExam *exam)
    {
        grades[1] = exam;
    }
    
    /* -------------------------------------------------------------------- +
     |  This function should accept the address of an Essay object as its   |
     |  argument. (See Programming Challenge 6 for the Essay class.         |
     |  If you have not completed Programming Challenge 6, use a            |
     |  GradedActivity object instead.) This object should already hold     |
     |  the student's score for the essay. Element 2 of the grades          |
     |  array should reference this object.                                 |
     + -------------------------------------------------------------------- */
    void setEssay(Essay *essay)
    {
        grades[2] = essay;
    }
    
    // IDK
    void setFinalExam(FinalExam *finale)
    {
        grades[3] = finale;
    }
    
    /* -------------------------------------------------------------------- +
     |  This function should display the numeric scores and grades for      |
     |  each element in the grades array.                                   |
     + -------------------------------------------------------------------- */
    void print()
    {
        for(int i = 0; i < 4; i++)
        {
            cout << "COURSE GRADES ELEMENT ["<< i << "]" << endl;
            cout << "SCORE: " <<grades[i]->getScore() << endl;
            cout << "GRADE: " <<grades[i]->getLetterGrade() << endl;
        }
    }
};

// -------------------------------------------------------------------------------------------- |
// Function Prototypes:

// Main function for the main program loop:
int main()
{
    GradedActivity lab1(80);
    PassFailExam exam1(25, 6, 90);
    Essay essay1(100, 100, 100, 100, 100);
    FinalExam final1(100, 90);
    
    CourseGrades grades;
    grades.setLab(&lab1);
    grades.setPassFailExam(&exam1);
    grades.setEssay(&essay1);
    grades.setFinalExam(&final1);
    
    grades.print();
    
    return 0;
}

// Quick PSA: I don't know why in God's name this damn program won't work. I have spent long enough on it, so here is my subpar submission.
// If you have any suggestions, please let me know...
