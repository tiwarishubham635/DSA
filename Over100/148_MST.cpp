static bool compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
    {
        return p1.second < p2.second;
    }
    
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
    
    bool isCycle(vector<pair<pair<int, int>, int>> edges, int n)
    {
        vector<pair<int, int>> subset;
        for (int i = 0; i < n; i++)
            subset.push_back({i, 0});
    
        for (int i = 0; i < edges.size(); i++)
        {
            pair<pair<int, int>, int> p = edges[i];
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
    
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        //kruskals
        vector<pair<pair<int, int>, int>> edges;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (i <= adj[i][j][0])
                {
                    pair<pair<int, int>, int> p;
                    p.first = {i, adj[i][j][0]};
                    p.second = adj[i][j][1];
                    edges.push_back(p);
                }
            }
        }
    
        sort(edges.begin(), edges.end(), compare);
        /*for (int i = 0; i < edges.size(); i++)
            cout << edges[i].first.first << " " << edges[i].first.second << " " << edges[i].second << endl;*/
    
        vector<pair<pair<int, int>, int>> mst;
        int ix = 0;
        int sum = 0;
        while (mst.size() != n - 1 && ix<edges.size())
        {
            mst.push_back(edges[ix]);
            if (isCycle(mst, n))
                mst.pop_back();
            else
                sum += edges[ix].second;
            ix++;
        }
    
        /*for (int i = 0; i < mst.size(); i++)
        {
            cout << mst[i].first.first << " " << mst[i].first.second << " " << mst[i].second << endl;
        }*/
        return sum;
        //prims
        /*unordered_set<int> s;
            vector<int> dist(n, INT_MAX);
            dist[0] = 0;
            int sum = 0;
            while (s.size() != n)
            {
                int node = -1, val = INT_MAX;
                for (int i = 0; i < n; i++)
                    if (s.find(i) == s.end() && dist[i] < (node == -1 ? val : dist[node]))
                        node = i;
                //cout << node << endl;
                sum += dist[node];
        
                s.insert(node);
                for (int i = 0; i < adj[node].size(); i++)
                {
                    if (dist[adj[node][i][0]] > adj[node][i][1])
                        dist[adj[node][i][0]] = adj[node][i][1];
                }
            }
            return sum;*/
    }
