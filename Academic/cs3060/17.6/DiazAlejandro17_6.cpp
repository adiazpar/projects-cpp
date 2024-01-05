/* -------------------------------------------------------------------------------------------- +
 |                                                                                              |
 |  Name: Alejandro Diaz                                                                        |
 |  Date: 10/30/23                                                                              |
 |  Assignment: 17.6                                                                            |
 |                                                                                              |
 |  Word Frequency                                                                              |
 |  Write a program that reads the contents of a text file.                                     |
 |  The program should create a map in which the keys are the individual words found            |
 |  in the file and the values are the number of times each word appears.                       |
 |                                                                                              |
 |  For example, if the word "the" appears 128 times, the map would contain an element          |
 |  with "the" as the key and 128 sa the value.                                                 |
 |                                                                                              |
 |  The program should either display the frequency of each word or create a second file        |
 |  containing a list of each word and its frequency.                                           |
 |                                                                                              |
 |  Hint: See Chapter 10 for a discussion of string tokenizing.                                 |
 |                                                                                              |
 + -------------------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

// -------------------------------------------------------------------------------------------- |
// Main Function:
int main()
{
    // Variables:
    string filename;        // To hold the filename
    string input;           // To hold an item read from the file
    
    // File object:
    ifstream file;          // ???
    
    // Map to hold the words and their frequencies:
    map<string, int> words;                 // ???
    
    // Get the name of the file:
    cout << "Enter a filename: ";
    getline(cin, filename);
    
    // Open the file:
    file.open(filename);
    
    // While not at the end of the file:
    while(file >> input)                    // ???
    {
        if(words.count(input))
        {
            words[input]++;                 // ???
        }
        else
        {
            words.emplace(make_pair(input, 1));     // ???
        }
    }
    
    // Close the file:
    file.close();
    
    // Display the word frequency:
    cout << "\n Word Frequency:" << endl;
    cout << "---------------" << endl;
    for (auto element : words)      // ???
    {
        cout << element.first << ": " << element.second << endl;
    }
    
    return 0;
}
