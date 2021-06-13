int celebrity(vector<vector<int> >& arr, int n) 
    {
        stack<int>s;
        for(int i=0;i<n;i++)
            s.push(i);
            
        while(s.size()>1)
        {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(arr[a][b])
                s.push(b);
            
            else
                s.push(a);
        }
        
        if(s.empty())
            return -1;
        
        int celeb = s.top();
        int knownby = 0, knows=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i][celeb])
                knownby++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[celeb][i])
                knows++;
        }
        
        if(knows==0 && knownby==n-1)
            return celeb;
        else
            return -1;
    }
