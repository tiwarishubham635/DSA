void topsort(vector<int>adj[], int i, int n, vector<int>&visited, stack<int>&st)
	{
	    if(visited[i])
	        return;
	    
	    visited[i]=1;
	    for(int j=0;j<adj[i].size();j++)
	        topsort(adj, adj[i][j], n, visited, st);
	    
	    st.push(i);
	}
vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    /*stack<int>st;
	    vector<int>visited(n,0);
	    
	    for(int i=0;i<n;i++)
	        if(!visited[i])
	            topsort(adj, i, n, visited, st);
	    vector<int>ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;*/
	    vector<int>in_degree(n,0);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	            in_degree[adj[i][j]]++;
	    }
	    
	    int count=0;
	    queue<int>q;
	    for(int i=0;i<n;i++)
	        if(in_degree[i]==0)
	            q.push(i);
	            
	    vector<int>top_sort;
	    while(q.size())
	    {
	        int node = q.front();
	        q.pop();
	        top_sort.push_back(node);
	        count++;
	        for(int i=0;i<adj[node].size();i++)
	        {
	            in_degree[adj[node][i]]--;
	            if(in_degree[adj[node][i]]==0)
	                q.push(adj[node][i]);
	        }
	    }
	    if(count!=n)
	        top_sort.clear();
	    
	    return top_sort;
	}
