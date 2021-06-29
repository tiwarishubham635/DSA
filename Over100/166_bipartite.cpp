bool isBipartiteUtil(vector<int>adj[], int src, int* color)
    {
        color[src] = 1;
        queue <int> q;
        q.push(src);
    
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
    
            for (int v = 0; v < adj[u].size(); ++v)
            {
                if(adj[u][v]==u)
                    return false;
                
                if (color[adj[u][v]] == -1)
                {
                    color[adj[u][v]] = 1 - color[u];
                    q.push(adj[u][v]);
                }
    
                else if (color[adj[u][v]] == color[u])
                    return false;
            }
        }
    
        return true;
    }

	bool isBipartite(int V, vector<int>adj[])
	{
	    int* color = new int[V];
        for (int i = 0; i < V; ++i)
            color[i] = -1;
            
        for(int i=0;i<V;i++)
            if (color[i] == -1)
                if (isBipartiteUtil(adj, i, color) == false)
                    return false;
    
        return true;
	}
