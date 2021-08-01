class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    int dfs(vector<vector<int>>& grid, int r, int c, int id)
    {
        if(r<0 or r>=grid.size() or c<0 or c>=grid[0].size() or grid[r][c]!=1)
            return 0;
        
        int ans = 1;
        grid[r][c] = id;
        
        for(int i=0;i<4;i++)
        {
            int x = r+dx[i];
            int y = c+dy[i];
            
            ans += dfs(grid, x, y, id);
        }
        
        return ans;
    }
    
    int dfs2(vector<vector<int>>& grid, int r, int c, unordered_map<int,int>&mp)
    {
        unordered_set<int>val;
        int ans = 0;
        
        for(int i=0;i<4;i++)
        {
            //cout<<endl;
            int x = r+dx[i]; 
            int y = c+dy[i]; 
            //cout<<x<<" "<<y<<" ";
            
            if(x<0 or x>=grid.size() or y<0 or y>=grid[0].size() or grid[x][y]==0)
                continue;
            
            //cout<<mp[grid[x][y]];
            val.insert(grid[x][y]);
        }
        //cout<<endl;
        for(auto i=val.begin();i!=val.end();i++)
            ans += mp[*i];
        //cout<<ans<<endl;
        
        return ans+1;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int id=2;
        unordered_map<int,int>mp;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int ans = dfs(grid, i, j, id);
                    mp[id] = ans;
                    id++;
                }
            }
        }
        
        int answer = 0;
        for(auto i=mp.begin();i!=mp.end();i++)
            answer = max(answer, i->second);
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0)
                {
                    answer = max(answer, dfs2(grid, i, j, mp));
                }
            }
        }
        
        return answer;
    }
};
