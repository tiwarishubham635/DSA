#include <bits/stdc++.h>
using namespace std;

int office(int *people, int *keys, int n, int k, int p)
{
    /*if (k == 0)
        return INT_MAX;

    if (n == 0)
        return INT_MIN;

    int step1 = office(people, keys, n, k - 1, p);
    int step2 = abs(keys[k - 1] - people[n - 1]) + abs(p - keys[k - 1]);
    step2 = max(step2, office(people, keys, n - 1, k - 1, p));
    return min(step1, step2);*/
    sort(people, people + n);
    sort(keys, keys + k);
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int[k + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = INT_MAX;

    for (int i = 0; i <= k; i++)
        dp[0][i] = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int step1 = dp[i][j - 1];
            int step2 = abs(keys[j - 1] - people[i - 1]) + abs(p - keys[j - 1]);
            step2 = max(step2, dp[i - 1][j - 1]);
            dp[i][j] = min(step1, step2);
        }
    }
    return dp[n][k];
}

int main()
{
    int n, p, k;
    cin >> n >> k >> p;
    int *people = new int[n];
    for (int i = 0; i < n; i++)
        cin >> people[i];

    int *keys = new int[k];
    for (int i = 0; i < k; i++)
        cin >> keys[i];

    cout << office(people, keys, n, k, p) << endl;
    return 0;
}
