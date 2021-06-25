
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
