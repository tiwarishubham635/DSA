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

int findParent(int v, int* parent)
{
    while(parent[v]!=v)
    {
        v = parent[v];
    }
    return parent[v];
}

bool isCycle(int** graph, int v, int e)
{
    int* parent = new int[v];
    for(int i=0;i<v;i++)
        parent[i] = i;
    for(int i=0;i<e;i++)
    {
        int x = findParent(graph[i][0], parent);
        int y = findParent(graph[i][1], parent);
        
        if(x==y)
            return true;
        parent[x] = y;
    }
    return false;
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
