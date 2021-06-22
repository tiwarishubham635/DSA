int idi;
    void dfs(vector<int> adj[], int v, vector<int> &id, vector<int> &low_link, vector<int> &onStack, stack<int> &st)
    {
        st.push(v);
        onStack[v]=1;
        id[v] = idi;
        low_link[v] = idi;
        idi++;
        
        for(int i=0;i<adj[v].size();i++)
        {
            if(id[adj[v][i]]==-1)
                dfs(adj, adj[v][i], id, low_link, onStack, st);
            if(onStack[adj[v][i]])
                low_link[v] = min(low_link[v], low_link[adj[v][i]]);
        }
        
        if(id[v]==low_link[v])
        {
            while(!st.empty())
            {
                int node = st.top(); 
                st.pop();
                onStack[node]=false;
                low_link[node]=low_link[v];
                if(node==v)
                    break;
            }
        }
    }
    
    vector<vector<int>> tarjans(int n, vector<int> adj[])
    {
        idi=0;
        vector<int>id(n,-1);//-1 = unvisited, else visited with given key
        vector<int>low_link(n, -1); //low_link values of each node
        vector<int>onStack(n,0);
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            if(id[i]==-1)
                dfs(adj, i, id, low_link, onStack, st);
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            //cout<<low_link[i]<<" ";
            mp[low_link[i]].push_back(i);
        }
        //cout<<endl;
        
        vector<vector<int>>ans;
        for(auto i=mp.begin();i!=mp.end();i++)
            ans.push_back(i->second);
        sort(ans.begin(), ans.end());
    
        return ans;
    }
