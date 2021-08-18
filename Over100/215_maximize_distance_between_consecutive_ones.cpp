// C++ program to Maximize distance between
// any two consecutive 1's after flipping M 0's

#include <bits/stdc++.h>
using namespace std;

// Function to return the count
bool check(int arr[], int n, int m, int d)
{
	// Flipping zeros at distance "d"
	int i = 0;
	while (i < n && m > 0) {
		m--;
		i += d;
	}

	return m == 0 ? true : false;
}

// Function to implement
// binary search
int maximumDistance(int arr[], int n, int m)
{

	int low = 1, high = n - 1;
	int ans = 0;

	while (low <= high) {

		int mid = (low + high) / 2;

		// Check for valid distance i.e mid
		bool flag = check(arr, n, m, mid);

		if (flag) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return ans;
}

// Driver code
int main()
{

	int n = 5, m = 3;
	int arr[n] = { 0 };

	cout << maximumDistance(arr, n, m);

	return 0;
}
