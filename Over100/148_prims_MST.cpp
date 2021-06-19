int spanningTree(int n, vector<vector<int>> adj[])
{
    //prims
    unordered_map<int, int> s;
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    int sum = 0;
    int prev = -1;
    while (s.size() != n)
    {
        int node = -1, val = INT_MAX;
        for (int i = 0; i < n; i++)
            if (s.find(i) == s.end() && dist[i] < (node == -1 ? val : dist[node]))
                node = i;

        sum += dist[node];

        s[node] = prev;
        prev = node;
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (dist[adj[node][i][0]] > adj[node][i][1])
                dist[adj[node][i][0]] = adj[node][i][1];
        }
    }

    for (auto i = s.begin(); i != s.end(); i++)
    {
        if (i->second != -1)
            cout << i->second << " -> " << i->first << endl;
    }
    return sum;
}
