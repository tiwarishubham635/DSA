#include <bits/stdc++.h>
using namespace std;

int deletionsForGivenPair(string &s, char &c1, char &c2)
{
    int ans = 0;
    int n = s.size();
    int i = 0;
    while (i < n)
    {
        int count_of_c1 = 0;
        int count_of_c2 = 0;

        while (i < n)
        {
            if (s[i] == c1)
                count_of_c1++;
            else if (s[i] == c2)
                count_of_c2++;
            else
                break;
            i++;
        }
        ans += min(count_of_c1, count_of_c2);
        i++;
    }
    return ans;
}

int minDeletions(string &s, vector<string> &pairs)
{
    int ans = 0;
    for (int i = 0; i < pairs.size(); i++)
        ans += deletionsForGivenPair(s, pairs[i][0], pairs[i][2]);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<string> pairs(k);
    for (int i = 0; i < k; i++)
        cin >> pairs[i];
    cout << minDeletions(s, pairs) << endl;
    return 0;
}
