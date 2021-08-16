#include <bits/stdc++.h>
using namespace std;

bool validLength(string s, int len)
{
	int l = 0, r = 0;
	int arr[4] = {0};
	while (r < len - 1)
		arr[s[r++] - '0']++;

	while (r < s.size())
	{
		arr[s[r++] - '0']++;
		if (arr[1] > 0 && arr[2] > 0 && arr[3] > 0)
			return true;
		arr[s[l++] - '0']--;
	}
	return false;
}

int min_length(string s)
{
	int ans = INT_MAX;
	int l = 3;
	int r = s.size();
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (validLength(s, mid))
			ans = min(ans, mid), r = mid - 1;
		else
			l = mid + 1;
	}
	return (ans == INT_MAX ? 0 : ans);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << min_length(s) << endl;
	}
	return 0;
}
