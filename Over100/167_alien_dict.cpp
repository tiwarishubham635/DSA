void topologicalSortUtil(int v, bool visited[], stack<int> &Stack,  vector<int> adj[])
    {
        // Mark the current node as visited.
        visited[v] = true;
    
        // Recur for all the vertices adjacent to this vertex
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                topologicalSortUtil(*i, visited, Stack, adj);
    
        // Push current vertex to stack which stores result
        Stack.push(v);
    }
    
    // The function to do Topological Sort. It uses recursive topologicalSortUtil()
    string topologicalSort(vector<int> adj[], int V)
    {
        stack<int> Stack;
        string ans = "";
    
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
    
        // Call the recursive helper function to store Topological Sort
        // starting from all vertices one by one
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topologicalSortUtil(i, visited, Stack, adj);
    
        // Print contents of stack
        while (Stack.empty() == false)
        {
            ans += (char) ('a' + Stack.top());
            Stack.pop();
        }
        return ans;
    }
    
    string findOrder(string words[], int n, int k) 
    {
        vector<int>adj[k];

        // Process all adjacent pairs of words and create a graph
        for (int i = 0; i < n-1; i++)
        {
            // Take the current two words and find the first mismatching
            // character
            string word1 = words[i], word2 = words[i+1];
            for (int j = 0; j < min(word1.length(), word2.length()); j++)
            {
                // If we find a mismatching character, then add an edge
                // from character of word1 to that of word2
                if (word1[j] != word2[j])
                {
                    adj[word1[j]-'a'].push_back(word2[j]-'a');
                    break;
                }
            }
        }
    
        // Print topological sort of the above created graph
        return topologicalSort(adj, k);
    }
