/*
 Name: Alejandro Diaz
 Date: 09/11/23
 Assignment: 9.8

 In statistics, the mode of a set of values is the value that occurs most often or with the greatest frequency.
 Write a function that accepts as arguments the following:
 
    A) An array of integers
    B) An integer that indicates the number of elements in the array
 
 The function should determine the mode of the array. That is, it should determine which value in the array occurs most often.
 The mode is the value the function should return. If the array has no mode (none of the values occur more than once),
 the function should return -1. (Assume the array will always contain nonnegative values.)
 
 Demonstrate your pointer prowess by using pointer notation instead of array notation in this function.
*/

#include <iostream>

#define SIZE 10

// Function Prototypes:
void randomizeArray(int *arr, size_t size);
void printArray(int *arr, size_t size);
int findMode(int *arr, size_t size);

int main()
{
    int numbers[SIZE];
    
    // Fill array:
    randomizeArray(numbers, SIZE);
    printArray(numbers, SIZE);
    
    // Find mode of array:
    int mode =  findMode(numbers, SIZE);
    
    if(mode == -1)
        std::cout << "There is not a mode in this array!" << std::endl << std::endl;
    else
        std::cout << "Mode: " << mode << std::endl << std::endl;
    
    return 0;
}

void randomizeArray(int *arr, size_t size)
{
    // Seed to randomize numbers using the time at the start of the program.
    // casted as unsigned to avoid data loss from a time_t
    srand((unsigned)time(0));
    for(size_t i = 0; i < size; i++)
    {
        // Randomize numbers between 0 and the value of 'size':
        arr[i] = rand() % size + 1;
    }
    
}

void printArray(int *arr, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;
}

int findMode(int *arr, size_t size)
{
    int recurringElements[size];
    
    // Assigning highest value to recurring elements array:
    // Each index will incriment by 1 each time a similar value is found within their respective index in the numbers arr.
    for(size_t i = 0; i < size; i++)
    {
        recurringElements[i] = 0;
        
        for(size_t j = 0; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                recurringElements[i]++;
            }
        }
    }
    
    // Print the recurringElements array for debugging so you know what I mean:
    //printArray(recurringElements, size);
    
    // Finding the highest value in the recurringElements array, which effectively finds the index of the mode:
    short mode = 0;
    unsigned short modeIndex = 0;
    
    for(size_t i = 0; i < size; i++)
    {
        if(recurringElements[i] > mode)
        {
            // Temporarily assign the value stored at the i'th index of recurringElements to the variable mode:
            mode = recurringElements[i];
            modeIndex = i;
        }
    }
    
    // Assigning the index of the mode from the recurringElements array to the value of the mode from the numbers arr:
    if(mode > 1)    {   mode = arr[modeIndex];  }
    else            {   mode = -1;              }
    
    return mode;
}
