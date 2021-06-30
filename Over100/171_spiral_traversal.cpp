vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>ans;
        int i=0,rn,cn;
        if(r%2==0)
            rn = r/2;
        else
            rn = (r+1)/2;
        
        if(c%2==0)
            cn = c/2;
        else
            cn = (c+1)/2;
        
        vector<vector<int>>v(r, vector<int>(c,0));
        while(i<min(rn,cn))
        {
            for(int j=i;j<c-i;j++)
                if(!v[i][j])
                    v[i][j]=1, ans.push_back(matrix[i][j]);
            
            for(int j=i+1;j<r-i;j++)
                if(!v[j][c-i-1])
                    v[j][c-i-1]=1, ans.push_back(matrix[j][c-i-1]);
            
            for(int j=c-i-2;j>=i;j--)
                if(!v[r-i-1][j])
                    v[r-i-1][j]=1, ans.push_back(matrix[r-i-1][j]);
            
            for(int j=r-i-2;j>i;j--)
                if(!v[j][i])
                    v[j][i]=1, ans.push_back(matrix[j][i]);
            
            i++;
        }
        return ans;
    }
