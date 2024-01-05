// Specification file for PassFailExam class:
#ifndef PassFailExam_h
#define PassFailExam_h

#include "PassFailActivity.h"

class PassFailExam : public PassFailActivity {
private:
    int numQuestions;       // Number of questions
    double pointsEach;      // Points for each question
    int numMissed;          // Number of questions missed
    
public:
    // Default Constructor:
    PassFailExam() : PassFailActivity()
    {
        numQuestions = 0;
        pointsEach = 0.0;
        numMissed = 0;
    }
    
    // Constructor:
    PassFailExam(int questions, int missed, double mps) : PassFailActivity(mps)
    {
        set(questions, missed);
    }
    
    // Mutator Functions:
    void set(int, int);     // This is defined in the cpp file
    
    // Accessor Functions:
    int getNumQuestions() const     {   return numQuestions;    }
    double getPointsEach() const    {   return pointsEach;      }
    int getNumMissed() const        {   return numMissed;       }
    
};

#endif /* PassFailExam_h */
