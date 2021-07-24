#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int a, b;
    cin>>a>>b;
    int n = s.size();
    int*prefix = new int[n];
    prefix[0] = (s[0]-'0')%a;
    
    int* suffix = new int[n];
    suffix[n-1] = (s[n-1]-'0')%b;
    long long p = 10;

    for(int i=1;i<n;i++)
    {
      prefix[i] = (prefix[i-1]*10 + (s[i]-'0'))%a;
      suffix[n-i-1] = ((s[n-i-1]-'0')*p + suffix[n-i])%b;
      p = (10*p)%b;
    }

    for(int i=0;i<n;i++)
    {
        if(prefix[i]==0&&suffix[i+1]==0)
      {
          int j = i+1;
          while(j<n&&s[j]=='0')
            j++;
            if(j<n)
            {
                cout<<"YES"<<endl;
                cout<<s.substr(0,j)<<endl;
                cout<<s.substr(j)<<endl;
                return 0;
            }
      }
    }
    cout<<"NO"<<endl;
    return 0;
}
