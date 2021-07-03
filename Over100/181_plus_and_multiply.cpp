#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        // n has to be of the form => n = (a^x) + y*b;
        // To check n by subtracting be consecutively, can give us TLE => O(n2)
        // But if we a^k, 0<=k<=x, then we can check easily if it is divisible by b
        // In case of a=1, we have to check sepeartely as a^k = 1 for all k, this can be infinite loop

        ll st = 1; // keep long as we will multiply consecutively by a, might be overflow
        int good = 0;

        if (a == 1)
            good = ((n - 1) % b == 0 ? 1 : 0);
        else
        {
            while (st <= n)
            {
                if ((n - st) % b == 0)
                {
                    good = 1;
                    break;
                }
                st *= a;
            }
        }

        if (good)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
