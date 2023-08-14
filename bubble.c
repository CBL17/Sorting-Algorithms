#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 100 

int bubble_sort(int* arr);

int main()
{
    int array[SIZE];
    int counts[SIZE] = {};
    int newcounts[SIZE] = {};

    srand(time(NULL));
    
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 100;
    }
    for (int i = 0; i < SIZE; i++)
    {
        counts[array[i]]++;
    }

    bubble_sort(array);

    for (int i = 0; i < SIZE-1; i++)
    {
        if (array[i] > array[i+1])
        {
            printf("Failed.");

            return 1;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        newcounts[array[i]]++;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (newcounts[i] != counts[i])
        {
            printf("Failed.");

            return 2;
        }
    }

    printf("Passed.");
    
    return 0;
}

int bubble_sort(int* arr)
{
    int temp;

    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    return 0;
}