#include<bits/stdc++.h>
using namespace std;

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
     int n;
     cin>>n;
     vector<string>words(n);
 for(int i=0;i<n;i++)
  cin>>words[i];

 int mx = 0;
 for(int i=0;i<5;i++)
 {
   char c = 'a' + i;
   priority_queue<pair<int,string>>pq;
   for(int j=0;j<n;j++)
   {
     int count = 0;
     for(int k=0;k<words[j].size();k++)
        if(words[j][k]==c)
           count++;
     pq.push({count-(words[j].size()-count),words[j]});
   }
   int ans = pq.top().first;
   pq.pop();
   int w = 0;
   while(ans>0&&pq.size())
     w++, ans += pq.top().first, pq.pop();
   if(ans>0)
     w++;
   mx = max(mx, w);
 }
 cout<<mx<<endl;
 }
 return 0;
}
