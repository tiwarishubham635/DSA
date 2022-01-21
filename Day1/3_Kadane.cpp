// Question: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxCrossingSum(vector<int>& nums, int l, int m, int r)
    {
        // here, the subarrays must contain arr[m]
        int leftSum = INT_MIN, rightSum = INT_MIN, sum=0;
        for(int i = m; i>=l;i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum); // maxsum in left subarray having middle element
        }
        
        sum=0;
        for(int i =m+1;i<=r;i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum); // maxsum in right subarray having middle element
        }
        
        return max(leftSum+rightSum, max(leftSum, rightSum)); // max of left or right part with mid element or array having both left and right part
    }
    
    int helper(vector<int>& nums, int l, int r)
    {
        /*
        Divide array into two halves
        Return the max subarray sum = maximum of left subarray (without mid element), right subarray(without mid element), 
                                                 subarray having some elements of left and some of right
        */
        if(l > r)
            return INT_MIN;
        
        if(l == r)
            return nums[l];
        
        int m = l + (r-l)/2;
        int leftSum = helper(nums, l, m-1);
        int rightSum = helper(nums, m+1, r);
        int betweenSum = maxCrossingSum(nums, l, m, r);
        
        return max(leftSum, max(rightSum, betweenSum) );
    }
    
    int maxSubArray(vector<int>& nums) {
        
        // Best approach - O(n)
        int curr_sum = nums[0], best_sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            curr_sum = (curr_sum+nums[i] > nums[i] ? curr_sum+nums[i] : nums[i]);
            best_sum = (curr_sum > best_sum ? curr_sum : best_sum);
        }
        return best_sum;
        
        /* kadane for non-negative sub array sum
        int curr_sum = 0, best_sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum += nums[i];
            best_sum = max(curr_sum, best_sum);
            if(curr_sum < 0)
                curr_sum = 0;
        }
        return best_sum;
        */
        
       // Divide and conquer approach
       // return helper(nums, 0, nums.size()-1);
    }
};
