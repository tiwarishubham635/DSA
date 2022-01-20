// Question: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        // l 
        // 1 0 2
        //   m
        //   h
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            
            else if(nums[mid]==1)
                mid++;
            
            else
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};
