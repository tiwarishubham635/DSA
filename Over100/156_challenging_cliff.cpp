#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; 
    while (t--)
    {
        int n;
        cin >> n;
        int *h = new int[n];
        for (int i = 0; i < n; i++)
            cin >> h[i];
        sort(h, h + n);
        if (n == 2)
            cout << h[0] << " " << h[1] << endl;
        else
        {
            int idx = 1, val = h[1] - h[0];
            for (int i = 1; i < n - 1; i++)
                if (h[i + 1] - h[i] < val)
                    idx = i + 1, val = h[i + 1] - h[i];
            for (int i = idx; i < n; i++)
                cout << h[i] << " ";
            for (int i = 0; i < idx; i++)
                cout << h[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
	// Sort the array : h1, h2, … , hk, hk+1, … hn
	// find hk and hk+1 which has minimum difference in sorted array
	// required order is hk+1, hk+2, hk+3, … hn, h1, h2, …, hk
	// the maximum difficulty = n-2 for n>2 and n-1 for n=2
