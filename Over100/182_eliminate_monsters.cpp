int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        int n = dist.size(); 
        int kills=0;
        vector<double>time;
        for(int i=0;i<n;i++)
        {
            time.push_back((double)dist[i]/speed[i]);
        }
            
        sort(time.begin(), time.end());
       
        int t=0, j=0;
        
        while(j<n)
        {
            if(time[j]<=t)
                return j;
            // kills time[j]
            j++;
            t++;
        }
        return j;
    }
