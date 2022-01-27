// Question: https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        //Time: O(nlogn)
        //Space: O(1)
        
        int n = nums.size()-1;
        long long sum_exp = n*(n+1)/2;
        long long sum =0;
        for(int i=0;i<=n;i++)
            sum += nums[i];
        
        return sum - sum_exp;
        */
        
        /*
        //Time: O(n)
        //Space: O(1)
        
        int slow = nums[0], fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;*/
        
        // Time: O(n)
        // Space: O(1)
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            int val = abs(nums[i]);
            if(nums[val] < 0)
            {
                ans = val;
                break;
            }
            nums[val] *= -1;
        }
        
        for(int i=0;i<nums.size();i++)
            nums[i] = abs(nums[i]);
        return ans;
    }
};
