// A C++ program to sort an array according to the order defined
// by another array
#include <stdio.h>
#include <stdlib.h>

// A2 is made global here so that it can be accessed by compareByA2()
// The syntax of qsort() allows only two parameters to compareByA2()
int A2[5];

// size of A2[]
int size = 5;

int search(int key)
{
    int i = 0, idx = 0;
    for (i = 0; i < size; i++)
        if (A2[i] == key)
            return i;
    return -1;
}

// A custom compare method to compare elements of A1[] according
// to the order defined by A2[].
int compareByA2(const void* a, const void* b)
{
    int idx1 = search(*(int*)a);
    int idx2 = search(*(int*)b);
    if (idx1 != -1 && idx2 != -1)
        return idx1 - idx2;
    else if (idx1 != -1)
        return -1;
    else if (idx2 != -1)
        return 1;
    else
        return (*(int*)a - *(int*)b);
}

// This method mainly uses qsort to sort A1[] according to A2[]
void sortA1ByA2(int A1[], int size1)
{
    qsort(A1, size1, sizeof(int), compareByA2);
}

// Driver program to test above function
int main(int argc, char* argv[])
{
    int A1[] = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8, 7, 5, 6, 9, 7, 5 };

    // A2[] = {2, 1, 8, 3, 4};
    A2[0] = 2;
    A2[1] = 1;
    A2[2] = 8;
    A2[3] = 3;
    A2[4] = 4;
    int size1 = sizeof(A1) / sizeof(A1[0]);

    sortA1ByA2(A1, size1);

    printf("Sorted Array is ");
    int i;
    for (i = 0; i < size1; i++)
        printf("%d ", A1[i]);
    return 0;
}
