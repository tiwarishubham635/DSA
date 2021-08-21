//Directed
	
	bool dfs(vector<int> adj[], int vertex, vector<int>&vis, vector<int>&path)
	{
	    vis[vertex] = 1;
	    path[vertex] = 1;
	    
	    for(int i=0;i<adj[vertex].size();i++)
	    {
	        if(!vis[adj[vertex][i]])
	        {
	            if(dfs(adj, adj[vertex][i], vis, path))
	            {
	                //cout<<vertex<<" "<<true<<endl;
	                return true;
	            }
	        }
	        
	        else if(path[adj[vertex][i]])
	        {
	            //cout<<vertex<<" "<<true<<endl;
	            return true;
	        }
	    }
	    
	    path[vertex] = 0;
	    //cout<<vertex<<" "<<false<<endl;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int>vis(V,0);
	   	vector<int>path(V,0);
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!vis[i])
    	   	    if(dfs(adj, i, vis, path))
	   	            return true;
	   	}
	   	return false;
	}
	
	// Undirected
#include <iostream>
using namespace std;

 int find(int i, vector<pair<int, int>> &subset)
    {
        if (subset[i].first != i)
            subset[i].first = find(subset[i].first, subset);
        return subset[i].first;
    }
    
    void Union(int x, int y, vector<pair<int, int>> &subset)
    {
        if (subset[x].second < subset[y].second)
            subset[x].first = y;
        else if (subset[x].second > subset[y].second)
            subset[y].first = x;
        else
        {
            subset[y].first = x;
            subset[x].second++;
        }
    }
    
    bool isCycle(vector<pair<int, int>> edges, int n)
    {
        vector<pair<int, int>> subset;
        for (int i = 0; i < n; i++)
            subset.push_back({i, 0});
    
        for (int i = 0; i < edges.size(); i++)
        {
            pair<int, int> p = edges[i];
            int x = p.first.first;
            int y = p.first.second;
            //cout << x << " " << y << " " << p.second << endl;
    
            int p1 = find(x, subset);
            int p2 = find(y, subset);
            //cout << p1 << " " << p2 << endl;
            if (p1 == p2)
                return 1;
    
            Union(p1, p2, subset);
            //cout << find(x, subset) << " " << find(y, subset) << endl;
        }
        return 0;
    }


int main() 
{
	int v, e;
	cin>>v>>e;
	int** graph = new int*[e];
	for(int i=0;i<e;i++)
	    graph[i] = new int[2];
	for(int i=0;i<e;i++)
	    cin>>graph[i][0]>>graph[i][1];
	cout<<isCycle(graph, v, e);
	return 0;
}
