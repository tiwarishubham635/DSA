
158.
	#include <bits/stdc++.h>
using namespace std;

string erase_and_extend(string s, int k)
{
    while (s.size() < k)
    {
        s = s + s;
    }
    while (s.size() > k)
    {
        s.pop_back();
    }
    return s;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string pref = "";
    pref += s[0];

    string ans = erase_and_extend(pref, k);
    int i = 1;
    while (i < s.size())
    {
        if (s[i] > s[0])
            break;
        pref += s[i];
        ans = min(ans, erase_and_extend(pref, k));
        i++;
    }
    cout << ans << endl;
    return 0;
}
// with small constraints, naive approach can be to keep adding characters from the beginning and making them ready as per requirement. This is O(nk).

159.
	#include <bits/stdc++.h>
using namespace std;

string erase_and_extend(string s, int k)
{
    while (s.size() < k)
    {
        s = s + s;
    }
    if (s.size() > k)
    {
        s = s.substr(0, k);
    }
    return s;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int i = 1;
    for (; i < n; i++)
    {
        if (s[i] > s[0])
            break;

        else if (s[i] == s[0])
        {
            int j = 1, k = i + 1;
            while (j < i && k < n)
            {
                if (s[k] == s[j])
                    k++, j++;
                else
                    break;
            }

            if (k == n)
            {
                break;
            }

            else
            {
                if (s[k] > s[j])
                {
                    break;
                }
                else
                    i = k;
            }
        }
    }

    if (i < n)
        s = s.substr(0, i);

    int sz = s.size();
    if (sz > 2 && s[0] == s[sz - 1] && s[sz - 2] < s[sz - 1])
        s.pop_back();

    cout << erase_and_extend(s, k) << endl;
    return 0;
}
// in large constraints, we can traverse the string and check if there is a character greater than first character, if yes then remove the string part after that character, including that character,
// else if same character is found, then check if any character greater than second character exists in string ahead of that character and so on.
// if all other characters are less than first character, no change to be done.
// After removing the extra part, apply the erase and extend conditions and return the array (just check for the condition that last character == first character and second last character < first character, in that case remove the last character too before erase and extend function)
