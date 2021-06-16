bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int si=-1,sj=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    if(si==-1&&sj==-1)
                        si = i, sj = j;
                    else return false;
                }
            }
        }
        
        if(si==-1 or sj==-1)
            return false;
        
        vector<vector<int>>visited(n, vector<int>(n,0));
        
        queue<pair<int,int>>q;
        q.push({si,sj});
        while(q.size())
        {
            pair<int,int>p = q.front();
            q.pop();
            if(p.first>= n or p.first<0 or p.second>=n or p.second<0 or visited[p.first][p.second] or grid[p.first][p.second]==0)
                continue;
            visited[p.first][p.second]=1;
            if(grid[p.first][p.second]==2)
                return true;
            q.push({p.first+1, p.second});
            q.push({p.first-1, p.second});
            q.push({p.first, p.second+1});
            q.push({p.first, p.second-1});
        }
        return false;
    }
