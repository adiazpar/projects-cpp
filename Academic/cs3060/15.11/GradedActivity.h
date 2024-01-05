// Specification file for GradedActivity class:
#ifndef GradedActivity_h
#define GradedActivity_h

class GradedActivity {
protected:
    double score;               // To hold the numeric score
    
public:
    // Default Constructor:
    GradedActivity()
    {   score = 0.0;    }
    
    // Parameterized Constructor:
    GradedActivity(double s)
    {   score = s;      }
    
    // Mutator Functions:
    void setScore(double s)
    {   score = s;      }
    
    // Accessor Functions:
    double getScore() const
    {   return score;   }
    
    // I don't fully understand this yet but study it more:
    virtual char getLetterGrade() const;
};

#endif /* GradedActivity_h */
