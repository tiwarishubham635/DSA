static bool compare(Job j1, Job j2)
    {
        return j1.profit>j2.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        /*               i         
        arr     0  1  2  3
        id      3  4  2  1
        dead    1  1  1  4
        profit  40 30 10 20
        
        t=2
        ans=2
        p=60
        */
        sort(arr, arr+n, compare);
        vector<int>check(n+1, 0);
        int t=0;
        int ans=0, p=0;
        for(int i=0;i<n;i++)
        {
            //cout<<arr[i].id<<" "<<arr[i].dead<<" "<<arr[i].profit<<endl;
            //cout<<t<<" "<<arr[i].dead<<endl;
            for(int j=min(n, arr[i].dead);j>=1;j--)
            {
                if(check[j]==0)
                {
                    ans++;
                    p += arr[i].profit;
                    check[j]=1;
                    break;
                }
            }
            
        }
        vector<int>a;
        a.push_back(ans);
        a.push_back(p);
        return a;
    } 
