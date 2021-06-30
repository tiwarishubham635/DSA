int activitySelection(vector<int> s, vector<int> f, int n)
    {
        vector<pair<int,int>>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
      
        for(int i=0;i<s.size();i++){
            // Pushing elements in priority queue where the key is f[i]
            p.push(make_pair(f[i],s[i]));
        }
      
        auto it = p.top();
        int start = it.second;
        int end = it.first;
        p.pop();
        int ct=1;
        
      
        while(!p.empty()){
            auto itr = p.top();
            p.pop();
            if(itr.second > end){
                start = itr.second;
                end = itr.first;
                ct++;
            }
        }
        return ct;
    }
