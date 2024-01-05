 /*
 Name: Alejandro Diaz
 Date: 09/01/23
 Assignment: 7.12
 
  A teacher has five students who have taken four tests. The teacher uses the following
 grading scale to assign a letter grade to a student, based on the average of his or her four test scores:
 
     Test Score        Letter Grade
     90-100                A
     80-89                 B
     70-79                 C
     60-69                 D
     0-59                  F
 
  Write a program that uses an array of string objects to hold the five student names, an array of five characters to hold the five
 students' letter grades, and five arrays of four doubles to hold each student's set of test scores.
 The program should allow the user to enter each student's name and his or her four test scores. It should then calculate and display
 each student's average test score, and a letter grade based on the average.
 
 Input Validation: Do not accept test scores less than 0 or greater than 100.
 */

#include <iostream>
#include <string>
#include <iomanip>

#define NUM_STUDENTS 5
#define NUM_TESTS 4

using namespace std;

void populateNamesAndScores(string[NUM_STUDENTS], double[][NUM_TESTS]);
void calculateAverageLetterGrades(double[][NUM_TESTS], char[NUM_STUDENTS]);
char assignLetter(double);

void displayInformation(string[NUM_STUDENTS], char[NUM_STUDENTS], double[][NUM_TESTS]);
void clearBuffer();

int main()
{
    // Array to hold the number of student's names:
    string names[NUM_STUDENTS];
    
    // Array to hold letter grades for each student:
    char letterGrades[NUM_STUDENTS];
    
    // Array to hold test scores for each test for each student:
    double testScores[NUM_STUDENTS][NUM_TESTS];
    
    populateNamesAndScores(names, testScores);
    calculateAverageLetterGrades(testScores, letterGrades);
    displayInformation(names, letterGrades, testScores);
}

// This method will first prompt the user to enter ALL of the student names:
void populateNamesAndScores(string names[NUM_STUDENTS], double scores[][NUM_TESTS])
{
    for(int student = 0; student < NUM_STUDENTS; student++)
    {
        cout << "Enter student " << student + 1 << " name: ";
        getline(cin, names[student]);
        
        for(int test = 0; test < NUM_TESTS; test++)
        {
            cout << " - Test score " << test + 1 << ": ";
            cin >> scores[student][test];
            
            // Error checking to see if user entered a valid test score:
            while( (scores[student][test] < 0 || scores[student][test] > 100) )
            {
                cout << " - INVALID Test score " << test + 1 << "! Try again:  ";
                cin >> scores[student][test];
            }
        }
        
        cout << "\n";
        
        // Clear the buffer
        clearBuffer();
    }
}

void calculateAverageLetterGrades(double scores[][NUM_TESTS], char grades[NUM_STUDENTS])
{
    for(int student = 0; student < NUM_STUDENTS; student++)
    {
        double total = 0.0;
        double average = 0.0;
        
        for(int test = 0; test < NUM_TESTS; test++)
        {
            total += scores[student][test];
        }
        
        average = total / NUM_TESTS;
        
        // Assign letter grade:
        grades[student] = assignLetter(average);
        
    }
}



char assignLetter(double average)
{
    char grade = '\0';
    
    if(average >= 90 && average <= 100)         {   grade = 'A';    }
    else if(average >= 80 && average <= 89)     {   grade = 'B';    }
    else if(average >= 70 && average <= 79)     {   grade = 'C';    }
    else if(average >= 60 && average <= 69)     {   grade = 'D';    }
    else                                        {   grade = 'F';    }
    
    
    return grade;
}

void displayInformation(string names[NUM_STUDENTS], char grades[NUM_STUDENTS], double scores[][NUM_TESTS])
{
    cout << left << setw(20) << "Student Name" << right << setw(20) << "Average" << right << setw(20) << "Letter Grade" << endl;
    cout << "-------------------------------------------------------------" << endl;
    
    // Calculating the average:
    for(int i = 0; i < NUM_STUDENTS; i++)
    {
        double total = 0.0;
        double average = 0.0;
        
        for(int j = 0; j < NUM_TESTS; j++)
        {
            total += scores[i][j];
        }
        
        average = total / NUM_TESTS;
        
        cout << left << setw(20) << names[i] << right << setw(20) << setprecision(4) << average << right <<setw(20) << grades[i] << endl;
    }
    
    cout << endl;
}

void clearBuffer()
{
    cin.clear();
    fflush(stdin);
}
