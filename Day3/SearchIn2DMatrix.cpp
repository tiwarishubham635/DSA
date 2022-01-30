// Question: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        /*if(target < matrix[0][0] or target > matrix[m-1][n-1])
            return false;
        
        int row=0;
        int low = 0, high = m-1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(matrix[mid][n-1] == target)
                return true;
            if(matrix[mid][n-1] < target)
                low = mid+1;
            else
                row = mid, high = mid-1;
        }
            
        low = 0, high = n-1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(matrix[row][mid] == target)
                return true;
            if(matrix[row][mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;*/
    
        // Approach - O(log(mn)
        int low = 0, high = m*n - 1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};
