// https://leetcode.com/problems/partition-array-according-to-given-pivot/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
            if(nums[i]<pivot)
                ans.push_back(nums[i]);
        
        for(int i=0;i<nums.size();i++)
            if(nums[i] == pivot)
                ans.push_back(nums[i]);
        
        for(int i=0;i<nums.size();i++)
            if(nums[i]>pivot)
                ans.push_back(nums[i]);
        
        for(int i=0;i<nums.size();i++)
            nums[i] = ans[i];
        
        return nums;
    }
};
