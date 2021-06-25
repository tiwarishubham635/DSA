
157.
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
        if (n & 1)
            cout << "Bob" << endl;
        else
        {
            int t = n, ans = 0;
            while (t)
            {
                t = t / 2;
                ans++;
            }
            ans--;
            if ((1 << ans) != n or ans % 2 == 0)
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
        }
    }
    return 0;
}
// Odd number always means Alice will lose, as odd number will either be prime or will have an odd divisor, which on subtracting will give an even number which is not a power of 2. These evens which are not power of 2, can be converted again to odd and thus, these numbers always lead win for alice.
// When n = power of two, all the divisors are powers of two, so they can only be reduced to other power of two or non-power of two. Now, the latter case is never preferred as it will always mean win for other person, so optimal strategy is to divide the number by 2 repeatedly. If log2(n) is even -> alice wins else Bob wins.
