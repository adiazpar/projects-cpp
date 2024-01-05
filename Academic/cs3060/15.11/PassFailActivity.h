// Specification file for PassFailActivity class:
#ifndef PassFailActivity_h
#define PassFailActivity_h

#include "GradedActivity.h"

class PassFailActivity : public GradedActivity {
protected:
    double minPassingScore;
    
public:
    // Default Constructor:
    PassFailActivity() : GradedActivity()
    {   minPassingScore = 0.0;  }
    
    // Constructor:
    PassFailActivity(double mps) : GradedActivity()
    {   minPassingScore = mps;  }
    
    // Mutator Functions:
    void setMinPassingScore(double mps)
    {   minPassingScore = mps;  }
    
    // Accessor Functions:
    double getMinPassingScore() const
    {   return minPassingScore; }
    
    virtual char getLetterGrade() const;
};


#endif /* PassFailActivity_h */
