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
        vector<vector<int>>ans;
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
        return ans;
    }
};
