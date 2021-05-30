void findMissing(int arr1[], int arr2[], int M, int N)
{
    if (M != N-1 && N != M-1)
    {
        cout << "Invalid Input";
        return;
    }

    // Do XOR of all element
    int res = 0;
    for (int i=0; i<M; i++)
       res = res^arr1[i];
    for (int i=0; i<N; i++)
       res = res^arr2[i];

    cout << "Missing element is " << res;
}
