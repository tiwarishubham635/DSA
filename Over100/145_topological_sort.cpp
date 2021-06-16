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
	    stack<int>st;
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
	    return ans;
	}
