Approach - 1 :
void findCounts(int *arr, int n)
{
    // Traverse all array elements
    int i = 0;
    while (i<n)
    {
        // If this element is already processed,
        // then nothing to do
        if (arr[i] <= 0)
        {
            i++;
            continue;
        }

        // Find index corresponding to this element
        // For example, index for 5 is 4
        int elementIndex = arr[i]-1;

        // If the elementIndex has an element that is not
        // processed yet, then first store that element
        // to arr[i] so that we don't lose anything.
        if (arr[elementIndex] > 0)
        {
            arr[i] = arr[elementIndex];

            // After storing arr[elementIndex], change it
            // to store initial count of 'arr[i]'
            arr[elementIndex] = -1;
        }
        else
        {
            // If this is NOT first occurrence of arr[i],
            // then decrement its count.
            arr[elementIndex]--;

            // And initialize arr[i] as 0 means the element
            // 'i+1' is not seen so far
            arr[i] = 0;
            i++;
        }
    }

    printf("\nBelow are counts of all elements\n");
    for (int i=0; i<n; i++)
        printf("%d -> %d\n", i+1, abs(arr[i]));
}
	Approach 2:
void printfrequency(int arr[],int n)
{
    // Subtract 1 from every element so that the elements
    // become in range from 0 to n-1
    for (int j =0; j<n; j++)
        arr[j] = arr[j]-1;

    // Use every element arr[i] as index and add 'n' to
    // element present at arr[i]%n to keep track of count of
    // occurrences of arr[i]
    for (int i=0; i<n; i++)
        arr[arr[i]%n] = arr[arr[i]%n] + n;

    // To print counts, simply print the number of times n
    // was added at index corresponding to every element
    for (int i =0; i<n; i++)
        cout << i + 1 << " ->  " << arr[i]/n << endl;
}
