#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 100

int selection_sort(int* arr);

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

    selection_sort(array);
    
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

            return 1;
        }
    }

    printf("Passed.");
    
    return 0;
}

int selection_sort(int* arr)
{
    for (int i = 0; i < SIZE-1; i++)
    {
        int min_indx = i;
        for (int j = i+1; j < SIZE; j++)
        {
            if (arr[j] < arr[min_indx])
            {
                min_indx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_indx];
        arr[min_indx] = temp;
    }
    
    return 0;
}
