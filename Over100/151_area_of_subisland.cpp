void AreaOfIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int &flag)
    {
        if(i >= 0 && i < grid2.size() && j >= 0 && j < grid2[0].size() && grid2[i][j])
        {
            grid2[i][j] = 0;
            if(grid1[i][j]==0)
                flag=0;
            AreaOfIsland(grid1, grid2, i+1, j, flag);
            AreaOfIsland(grid1, grid2, i-1, j, flag); 
            AreaOfIsland(grid1, grid2, i, j+1, flag);
            AreaOfIsland(grid1, grid2, i, j-1, flag);
        }
        return;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int m = grid1.size();
        int n = grid1[0].size();
        
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j])
                {
                    int flag=1;
                    AreaOfIsland(grid1, grid2, i, j, flag);
                    if(flag)
                        ans++;
                }
            }
        }
        return ans;
    }
