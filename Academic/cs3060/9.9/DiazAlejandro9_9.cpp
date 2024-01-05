/*
 Name: Alejandro Diaz
 Date: 09/11/23
 Assignment: 9.9

 In statistics, when a set of values is sorted in ascending or descending order, its median is the middle value.
 If the set contains an even number of values, the median is the mean, or average, of the two middle values.
 Write a function that accepts as arguments the following:
 
    A) An array of integers
    B) An integer that indicates the number of elements in the array
 
 The function should determine the median of the array. This value should be returned as a double.
 (Assume the values in the array are already sorted.)
 
 Demonstrate your pointer prowess by using pointer notation instead of array notation in this function.
*/

#include <iostream>

#define SIZE 10

// Function Prototype:
void fillArray(int *arr, size_t size);
void sortArray(int *arr, size_t size);
double findMedian(int *arr, size_t size);
void printArray(int *arr, size_t size);

int main()
{
    int numbers[SIZE];
    
    // Fill Array:
    fillArray(numbers, SIZE);
    printArray(numbers, SIZE);
    
    // Find Median of Array:
    double median = findMedian(numbers, SIZE);
    
    std::cout << "Median: " << median << std::endl;
    
    return 0;
}

void fillArray(int *arr, size_t size)
{
    // Seed to randomize numbers using the time at the start of the program.
    // casted as unsigned to avoid data loss from a time_t
    srand((unsigned)time(0));
    for(size_t i = 0; i < size; i++)
    {
        // Randomize numbers between 0 and the value of 'size':
        arr[i] = rand() % size + 1;
    }
    
    // Sort Array in ascending order:
    sortArray(arr, size);
}

void sortArray(int *arr, size_t size)
{
    int temp = 0;
    
    // Sorting arr passed into function by using temp variable:
    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

double findMedian(int *arr, size_t size)
{
    int middleElement = (int)(size - 1) / 2;
    double median = 0;
    
    // Check to see if the array size is even, so that the average of the two medians can be calculated:
    if(size % 2 == 0)
    {
        int middleElement2 = middleElement + 1;
        median = (double)(arr[middleElement] + arr[middleElement2]) / 2;
        
    }
    else
    {
        median = arr[middleElement];
    }
    
    
    return median;
}

void printArray(int *arr, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;
}
