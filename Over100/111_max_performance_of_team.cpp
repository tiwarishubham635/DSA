int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<int, int>> eff_sp;
        priority_queue <int, vector<int>, greater<int> > pq_speeds; // min heap
        long sum = 0, res = 0;
        for (int i = 0; i < n; ++i)
            eff_sp.push_back({efficiency[i], speed[i]});
        sort(rbegin(eff_sp), rend(eff_sp)); // reverse begin, reverse end sort =>decreasing order sort
        for (int i = 0; i < n; i++) 
        {
            sum += eff_sp[i].second;
            pq_speeds.push(eff_sp[i].second);
            if (pq_speeds.size() > k) 
            {
                sum -= pq_speeds.top();
                pq_speeds.pop();
            }
            res = max(res, sum * eff_sp[i].first);
        }
        return res % (int)(1e9+7);
    }
