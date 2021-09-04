class Solution {
    void dfs(vector<int>adj[], vector<int>&ct, vector<int>&ans, int v, int pre)
    {
        for(int i=0;i<adj[v].size(); i++)
        {
            int child = adj[v][i];
            if(child == pre)
                continue;
            
            dfs(adj, ct, ans, child, v);
            ct[v] += ct[child];
            ans[v] += (ans[child] + ct[child]);
        }
        ct[v]++;
    }
    
    void dfs2(vector<int>adj[], vector<int>&ct, vector<int>&ans, int v, int pre, int n)
    {
        for(int i=0;i<adj[v].size(); i++)
        {
            int child = adj[v][i];
            if(child == pre)
                continue;
            
            ans[child] = ans[v] - ct[child] + n - ct[child];
            dfs2(adj, ct, ans, child, v, n);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> ans(n,0);
        vector<int> ct(n,0);
        
        dfs(adj, ct, ans, 0, -1);
        dfs2(adj, ct, ans, 0, -1, n);
        
        return ans;
    }
};
