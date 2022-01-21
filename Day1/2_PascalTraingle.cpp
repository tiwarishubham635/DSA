// Question: https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      
        /*
        Approach - 1: Recursion
        
        vector<vector<int>>ans;
        vector<int>lst; 
        lst.push_back(1);
        if(numRows == 1)
        {
            ans.push_back(lst);
            return ans;
        }
        
        ans = generate(numRows-1); // [[1], [1,1]]
        vector<int> last = ans[ans.size()-1]; // [1,1]
        for(int i=0;i<last.size()-1;i++)
            lst.push_back(last[i]+last[i+1]);
        
        lst.push_back(1);
        ans.push_back(lst);
        return ans;*/
        
        // Approach - 2: DP
        /*vector<vector<int>>ans;
        vector<int> lst;
        lst.push_back(1);
        ans.push_back(lst); 

        for(int i=1;i<numRows;i++)
        {
            lst.clear();
            lst.push_back(1); 
            
            vector<int> last = ans[i-1]; 
            for(int i=0;i<last.size()-1;i++)
                lst.push_back(last[i]+last[i+1]);
            
            lst.push_back(1); 
            ans.push_back(lst); 
        }
        return ans;*/
        
        // Approach-3: DP in better way
        vector<vector<int>>ans(numRows);
        /*for(int i=0;i<numRows;i++)
        {
            ans[i].resize(i+1);
            ans[i][0] = 1;
            ans[i][i] = 1;
            
            for(int j=1;j<i;j++)
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
        
        return ans;*/
        
        // Approach-4: Using nCr in a better way. nCr = 1*(n-i)/(i+1) for i = 0 to r-1.
        // Example 7C3 = 1*(7/1)*(6/2)*(5/3)
        for(int i=0;i<numRows;i++)
        {
            ans[i].resize(i+1);
            int start = 1;
            ans[i][0] = start;
            
            for(int j=1;j<i+1;j++)
            {
                start *= (i-j+1);
                start /= (j);
                
                ans[i][j] = start;
            }
        }
        return ans;
    }
};
