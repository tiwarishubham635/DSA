// Question: https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        Algorithm:
        1. We first find the first element a[i] from the end which is in sorted order with next element (arr[i] < arr[i+1])
        2. If there is no such i > 0, then array is reverse sorted, just reverse the array and return
        3. If there is a valid i, then find the first element a[j] from the end which is greater than arr[i] (arr[i] < arr[j]). 
           This way we are finding in the smallest no. greater than a[i] because the part in the right of i is reverse sorted.
        4. Now, just swap the values at i and j index. 
        5. Now reverse the elements from index i+1 to end, as the new value at index i is to have smallest lexicographically 
           sequence, so that we can get the lexicographically next permutation
        */
      
        int i=nums.size()-2;
        for(;i>=0;i--)
            if(nums[i] < nums[i+1])
                break;
        
        if(i >= 0)
        {
            int j=nums.size()-1;
            for(;j>i;j--)
                if(nums[j] > nums[i])
                    break;

            swap(nums[i], nums[j]);
        }
        
        reverse(nums.begin()+i+1, nums.end()); // or sort 
    }
};
