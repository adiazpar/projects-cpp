/*
 Name: Alejandro Diaz
 Date: 10/04/23
 Assignment: 12.15
 
 READING FROM A FILE EXAMPLE
 */

#include <iostream>
#include <fstream>
using namespace std;

// Function prototype:
int countSentences(string);
int countWords(string);

int main()
{
    int sentences;
    int words;
    double average;
    
    sentences = countSentences("text.txt");
    words = countWords("text.txt");
    
    // Calculate the average words per sentence:
    average = static_cast<double>(words) / sentences;
    
    // Display the result:
    cout << "The file contains " << words << " words, and " << sentences << " sentences." << endl;
    cout << "There is an average of " << setprecision(1) << fixed << average << " words per sentence." << endl;
    
    return 0;
}

int countSentences(string filename)
{
    const int SIZE = 500;
    char input[SIZE];
    fstream inputFile;
    int numSentences = 0;
    
    // Open, read, and close the file:
    inputFile.open(filename, ios::in);
    if(!inputFile)
    {
        cout << "ERROR: Cannot open file.\n";
        exit(0);
    }
    
    inputFile.getline(input, SIZE);
    while(!inputFile.eof())
    {
        for(int index = 0; input[index] != '\0'; index++)
        {
            if(input[index] == '.')
                numSentences++;
        }
        inputFile.getline(input, SIZE);
    }
    
    // Close the file:
    inputFile.close();
    
    return numSentences;
}

int countWords(string filename)
{
    const int SIZE = 500;
    char input[SIZE];
    fstream inputFile;
    int numWords = 0;
    
    // Open the file in input mode:
    inputFile.open(filename, ios::in);
    
    if(!inputFile)
    {
        cout << "ERROR: Cannot open file.\n";
        exit(0);
    }
    
    // Read the file contents:
    inputFile.getline(input, SIZE);
    while(!inputFile.eof())
    {
        // Step through the string, counting words:
        int index = 0;
        while(input[index] != '\0')
        {
            // Skip over any whitespace characters:
            while (isspace(input[index]) && input[index] != '\0')
            {
                index++;
            }
            
            // if we aren't at the end of the string, then count this as a word and then skip over it:
            if(input[index] != '\0')
            {
                // This is the beginning of a word so increment the word counter:
                numWords++;
                
                // Skip over this word:
                while(!isspace(input[index]) && input[index] != '\0')
                {
                    index++;
                }
            }
        }
        
        // Read the next line from the file:
        inputFile.getline(input, SIZE);
    }
    
    // Close the file:
    inputFile.close();
    
    return numWords;
}

