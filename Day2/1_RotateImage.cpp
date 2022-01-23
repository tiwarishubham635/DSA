// Question: https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int tmp = INT_MIN;
        
        /*
        Approach -1 : Picking border values and swapping the corners in circular manner
        
        for(int j=0;j<n/2;j++)
        {
            for(int i=0;i<n-1-2*j;i++)
            {
                tmp = matrix[n-1-j-i][n-1-j];
                matrix[n-1-j-i][n-1-j] = matrix[j][n-1-j-i];
                matrix[j][n-1-j-i] = matrix[j+i][j];
                matrix[j+i][j] = matrix[n-1-j][j+i];
                matrix[n-1-j][j+i] = tmp;
            }
        }*/
        
        // Approach -2 : Take image about major diagonal i.e. Transpose the matrix
        // Now reverse each row of the matrix
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
        
    }
};
