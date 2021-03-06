// Question: https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num=nums[0], count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(num == nums[i])
                count++;
            else if(count == 0)
            {
                num = nums[i];
                count=1;
            }
            else count--;
        }
        return num;
    }
};
