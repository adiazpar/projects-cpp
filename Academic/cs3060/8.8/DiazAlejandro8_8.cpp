/*
Name: Alejandro Diaz
Date: 09/01/23
Assignment: 8.8
 
 Write a program that has an array of at least 20 integers. It should call a function that
 uses the linear search algorithm to locate one of the values. The function should keep
 a count of the number of comparisons it makes until it finds the value.
 
 The program then should call a function that uses the binary search algorithm to locate the same value.
 It should also keep count of the number of comparisons it makes. Display these values on the screen.
*/

#include <iostream>
#define SIZE 20

// Function Prototypes:
void linearSearch(int, int *, size_t);
void binarySearch(int, int *, size_t);
void randomizeArray(int *, size_t);
void sortArray(int *, size_t);
void printArray(int *, size_t);

int main()
{
    int numbers[SIZE];
    int response = 0;
    
    randomizeArray(numbers, SIZE);
    //printArray(numbers, SIZE);
    
    // Linear search algorithm, will print every value:
    std::cout << "An array has been created. Please enter a value from 1 to " << SIZE << ": ";
    std::cin >> response;
    
    linearSearch(response, numbers, SIZE);
    binarySearch(response, numbers, SIZE);
    
    std::cout << "\n";
    return 0;
}

void linearSearch(int key, int *arr, size_t size)
{
    std::cout << "\nLinear search: \n";
    
    // Loop to search for the given value
    bool foundValue = false;
    size_t i = 0;
    int numComparisons = 0;
    
    while(!foundValue && i < size)
    {
        if(arr[i] == key)
        {
            foundValue = true;
            std::cout << "[" << arr[i] << "]";
        }
        else
        {
            std::cout << arr[i] << " ";
        }
        
        i++;
        numComparisons++;
    }
    
    // Conditions if value is found or not:
    if(!foundValue) {   std::cout << "[-] \nValue not found!";   }
    std::cout << "\nNumber of Comparisons: " << numComparisons << "\n";
}

void binarySearch(int key, int *arr, size_t size)
{
    std::cout << "\nBinary Search: \n";
    
    // Sorting the array for binary search to work:
    sortArray(arr, size);
    
    // Performing iterative binary search algorithm:
    bool foundValue = false;
    int numComparisons = 0;
    
    int low = 0;
    int high = int(size);
    
    while (low <= high && !foundValue)
    {
        int mid = low + (high - low) / 2;
        
        // Check if key is present at the middle:
        if(arr[mid] == key)
        {
            foundValue = true;
            std::cout << "[" << arr[mid] << "]";
        }
        else if(arr[mid] != key && mid < size)
        {
            std::cout << arr[mid] << " ";
        }
        
        // If key is greater, ignore left half:
        if(arr[mid] < key)
            low = mid + 1;
        
        // If key is less, ignore the right half:
        else
            high = mid - 1;
        
        numComparisons++;
    }
    
    // Conditions if value is found or not:
    if(!foundValue) {   std::cout << "[-] \nValue not found!";   }
    std::cout << "\nNumber of Comparisons: " << numComparisons << "\n";
}

void randomizeArray(int *arr, size_t size)
{
    // Seed to randomize numbers using the time at the start of the program.
    // casted as unsigned to avoid data loss from a time_t
    srand((unsigned)time(0));
    
    // Creating an array with unique values:
    int new_random;
    bool unique;
    
    for(size_t i = 0; i < size; i++)
    {
        do
        {
            // Randomize a number between 1 and the value of 'size':
            new_random = rand() % size + 1;
            unique = true;
            
            // Iterating through all previous values of the array to compare unique value:
            for(int j = 0; j < i; j++)
            {
                // If value is previously found, it isn't unique...
                if(arr[j] == new_random)    {   unique = false; }
            }
            
        } while(!unique);   // Loop will continue until a unique value is found...
        
        arr[i] = new_random;
    }
}

void sortArray(int *arr, size_t size)
{
    int temp = 0;
    
    // Sorting arr passed into function by using temp variable:
    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < size; j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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
