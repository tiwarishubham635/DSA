#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string str;
        ll sum=0;
        cin>>str;
        ll n=str.size();
        for(long long i=(n-1);i>=(0);--i)
            sum+=str[i]-'a';
        
        cout<<sum<<" ";
        if(sum==(25*n) || sum==0 || n==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        string ans(n,'a');
        
        int i = n - 1;
        while (i >= 0)
        {
            if (sum >= 25)
            {
                ans[i] = 'z';
                sum -= 25;
            }
            else
                ans[i] = (char)('a' + sum), sum = 0;
            i--;
        }
        
        if (ans.compare(str) == 0)
        {
            for (int i = n - 2; i >= 0; i--)
            {
                if (ans[i] != 'z')
                {
                    ans[i]++;
                    ans[i + 1]--;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
