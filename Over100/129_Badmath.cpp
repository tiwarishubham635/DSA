#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fun(string s, int m, ll ind,ll sum,ll res) 
{ 
    if(ind == -1) { 
        if(sum%m == 0) 
            return 1; 
        return 0; 
    } 
    if(s[ind] != '_') { 
        if(s[ind] == '1') 
            return fun(s, m, ind-1,(sum+res)%m, (res*2)%m); 
        else  
            return fun(s, m, ind-1,sum,(res*2)%m); 
    } 
    else  
        return fun(s, m, ind-1, (sum+res)%m, (res*2)%m) + fun(s, m, ind-1, sum, (res*2)%m); 
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        int num =0, res = 1;
        cout<<fun(s, m, n-1, 0, 1)<<endl;
    }
	return 0;
}
