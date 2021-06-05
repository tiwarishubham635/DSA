#include <bits/stdc++.h>
using namespace std;

int *longest_prefix_suffix(string p)
{
    int n = p.size();
    int *lps = new int[n];
    lps[0] = 0;
    int len = 0;
    for (int i = 1; i < n;)
    {
        if (p[len] == p[i])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if (len == 0)
                lps[i] = 0, i++;

            else
                len = lps[len - 1];
        }
    }
    return lps;
}

void KMP(string s, string p)
{
    int n = s.size();
    int m = p.size();

    int *lps = longest_prefix_suffix(p);

    int j = 0;
    for (int i = 0; i < n;)
    {
        if (s[i] == p[j])
            i++, j++;

        if (j == m)
        {
            cout << "String " << p << " found in string " << s << " at index : " << i - j << endl;
            j = lps[j - 1];
        }

        else if (i < n && s[i] != p[j])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    string w = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMP(w, pat);
    return 0;
}
