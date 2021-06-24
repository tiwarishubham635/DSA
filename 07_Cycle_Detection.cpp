//Directed
	
	bool cycle(vector<int> adj[], int n, int v, vector<int>&visited, vector<int>&rec_stack)
    {
        if(!visited[v])
        {
            visited[v]=1;
            rec_stack[v]=1;
            
            for(int i=0;i<adj[v].size();i++)
            {
                if(!visited[adj[v][i]] && cycle(adj, n, adj[v][i], visited, rec_stack))
                    return true;
                else if(rec_stack[adj[v][i]])
                    return true;
            }
        }
        rec_stack[v]=0;
        return false;
    }
	
	bool isCyclic(int n, vector<int> adj[]) 
	{
	    vector<int>visited(n,0);
	    vector<int>rec_stack(n,0);
	    
	    for(int i=0;i<n;i++)
	        if(cycle(adj, n, i, visited, rec_stack))
	            return true;
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
