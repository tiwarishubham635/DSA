int minThrow(int n, int arr[])
    {
        vector<int>adj[31];
        for(int i=1;i<30;i++)
        {
            for(int j=i+1;j<=min(i+6, 30);j++)
                adj[i].push_back(j);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[2*i]]=arr[2*i+1];
            if(arr[2*i]<=arr[2*i+1]) //ladder
                adj[arr[2*i]].push_back(arr[2*i+1]);
            
            else // snake
            {
                if(arr[2*i]==30)
                    return -1;
                adj[arr[2*i]].erase(adj[arr[2*i]].begin());
                adj[arr[2*i]].push_back(arr[2*i+1]);
                if(arr[2*i]!=0)
                    adj[arr[2*i]-1].push_back(arr[2*i]+1);
            }
        }
        
        vector<int>visited(31,0);
        queue<pair<int,int>>q;
        q.push({1,0});
        visited[1]=1;
        int ans = INT_MAX;
        while(!q.empty())
        {
            int node = q.front().first;
            int moves = q.front().second;
            //cout<<node<<" "<<moves<<" : ";
            q.pop();
            
            visited[node]=1;
            
            if(node==30)
                ans = min(moves, ans);
            
            for(int i=0;i<adj[node].size();i++)
            {
                if(!visited[adj[node][i]])
                {
                    //cout<<adj[node][i]<<" ";
                    int new_moves = moves;
                    if(mp.find(node)==mp.end() or mp[node]!=adj[node][i])
                        new_moves += abs(adj[node][i]-node)/6 + ((abs(adj[node][i]-node)!=6)?1:0);
                    
                    q.push({adj[node][i], new_moves});
                }
            }
            //cout<<endl;
        }
        return ans;
    }
