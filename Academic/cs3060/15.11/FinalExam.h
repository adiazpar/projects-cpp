// Specification file for FinalExam class:
#ifndef FinalExam_h
#define FinalExam_h

#include "GradedActivity.h"

class FinalExam : public GradedActivity {
private:
    double minPassingScore;
    
public:
    // Default Constructor:
    FinalExam() : GradedActivity() {
        minPassingScore = 0;
    }
    
    // Parameterized Constructor:
    FinalExam(double fscore, double mps) : GradedActivity(fscore) {
        minPassingScore = mps;
    }
    
    // Mutator Functions:
    void setMinPassingScore(double mps) {   minPassingScore = mps;  }
    
    // Accessor Functions:
    double getMinPassingScore() {   return minPassingScore;     }
    
    // Virtual Functions:
    virtual char getLetterGrade() const;
    
};

#endif /* FinalExam_h */
