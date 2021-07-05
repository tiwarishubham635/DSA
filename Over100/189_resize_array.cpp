vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int n = mat.size();
        int m = mat[0].size();
        if(m*n!=r*c)
            return mat;
        
        vector<vector<int>>ans(r, vector<int>(c,0));
        /*int row=0, col=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[row][col++] = mat[i][j];
                if(col==c)
                    row++,col=0;
            }
        }*/
        
        // mat[i][j] = tmp[i*m+j]
        // (i*m + j)/c = ix
        // (i*m + j)%c = jx
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ix = (i*m + j)/c;
                int jx = (i*m + j)%c;
                
                ans[ix][jx] = mat[i][j];
            }
        }
        return ans;
    }
