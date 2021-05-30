void productPuzzle(int a[], int n)
{
    // to hold sum of all values
    long double sum = 0;
    for (int i = 0; i < n; i++)
        sum += (long double)log10(a[i]);

    // output product for each index
    // antilog to find original product value
    for (int i = 0; i < n; i++)
        cout << (int)(EPS + pow((long double)10.00,
                                sum - log10(a[i])))
             << " ";
}
