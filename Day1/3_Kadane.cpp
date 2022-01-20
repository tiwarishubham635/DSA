// Question: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0], best_sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            curr_sum = (curr_sum+nums[i] > nums[i] ? curr_sum+nums[i] : nums[i]);
            best_sum = (curr_sum > best_sum ? curr_sum : best_sum);
        }
        return best_sum;
    }
};
