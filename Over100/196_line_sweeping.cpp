vector<vector<long long>> splitPainting(vector<vector<int>>& segments) 
    {
        long long n = segments.size();
        unordered_map<long long,long long>color_mix;
        priority_queue<long long, vector<long long>, greater<long long>>end;
        unordered_set<int>s;
        //set<int>end;
        
        for(long long i=0;i<n;i++)
        {
            color_mix[segments[i][0]] += segments[i][2];
            color_mix[segments[i][1]] -= segments[i][2];
            
            if(s.find(segments[i][0]) == s.end())
                end.push(segments[i][0]), s.insert(segments[i][0]);
            
            if(s.find(segments[i][1]) == s.end())
                end.push(segments[i][1]), s.insert(segments[i][1]);
            
            //end.insert(segments[i][0]);
            //end.insert(segments[i][1]);
        }
        
        long long sum = 0, last_index = 0;
        vector<vector<long long>>ans;
        while(end.size())
        {
            //long long val = *(end.begin());
            long long val = end.top();
            end.pop();
            s.erase(val);
            //end.erase(val);
            
            if(sum)
                ans.push_back({last_index, val, sum});
            
            last_index = val;
            sum += color_mix[val];
        }
        
        return ans;
    }
