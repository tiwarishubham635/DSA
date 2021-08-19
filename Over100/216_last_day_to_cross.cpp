class Solution {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
public:
    bool bfs(vector<vector<int>>& cells, int n, int m, int days)
    {
        vector<vector<int>>grid(n, vector<int>(m,0));
        queue<pair<int,int>>q;
        
        for(int i=0;i<days;i++)
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        
        for(int j=0;j<m;j++)
            if(grid[0][j]==0)
                q.push({0,j}), grid[0][j]=1;
        
        while(q.size())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x==n-1)
                return true;
            
            for(int i=0;i<4;i++)
            {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                
                if(x1>=0 && x1<n && y1>=0 && y1<m && !grid[x1][y1])
                    q.push({x1,y1}), grid[x1][y1] = 1;
            }
        }
        
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        int ans = 0;
        int l = 1, r = cells.size();
        
        while(l<=r)
        {
            int days = l + (r-l)/2;
            if(bfs(cells, row, col, days))
                ans = days, l = days+1;
            else
                r = days-1;
        }
        
        return ans;
    }
};
