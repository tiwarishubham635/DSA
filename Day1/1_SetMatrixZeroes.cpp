// Question: https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      
        /*
        Approach - 1: Store the row no. and col no. which will be set to zero
        Space : O(m+n)
        
        unordered_set<int>rows;
        unordered_set<int>cols;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        for(auto i=rows.begin();i!=rows.end();i++)
        {
            for(int j=0;j<matrix[*i].size();j++)
            {
                matrix[*i][j] = 0;
            }
        }
        
        for(auto i=cols.begin();i!=cols.end();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                matrix[j][*i] = 0;
            }
        }
        */
       
        /* Approach - 2: We use the first row and first col to store which row or column will be zero
        If we remove the first row and first column, then for the remaining matrix, if value is zero, 
        then we mark that row and that column to be made 0 by making arr[i][0] = 0 and arr[0][j] = 0.
        For the first row, if value is 0 then we make arr[0][0] = 0 and in first column, if value is 0,
        then we take seperate bool isCol and set it to true. Now, we start from reverse for the 
        inner matrix (after removing first row and column) and if either arr[i][0] = 0 or arr[0][j] = 0
        then that value will be set to 0 (making thw row and column zero). For first row, if arr[0][0] = 0,
        then value will be set to 0. If isCol is set, then we set the first col value to 0.
        
        Space: O(1)
        */
        int n = matrix.size(), m = matrix[0].size();
        bool isFirstColZero = false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(j==0)
                        isFirstColZero = true;
                    
                    else
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        
        for(int i=n-1;i>0;i--)
        {
            for(int j=m-1;j>0;j--)
            {
                if(matrix[i][0] == 0 or matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        if(matrix[0][0] == 0)
        {
            for(int j=0;j<m;j++)
                matrix[0][j] = 0;
        }
        
        if(isFirstColZero == true)
        {
            for(int i=0;i<n;i++)
                matrix[i][0] = 0;
        }
    }
};
