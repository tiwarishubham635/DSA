// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/

// Reference: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/discuss/1746989/C%2B%2B-Heap-O(NlogN)

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long ans = LLONG_MAX;
        priority_queue<int>maxHeap;
        priority_queue<int, vector<int>, greater<int>>minHeap;
        
        int n = nums.size()/3;
        long long lsum=0, rsum=0;
        vector<long>rsumt(nums.size());
        
        for(int i=nums.size()-1;i>=n;i--)
        {
            rsum += nums[i];
            minHeap.push(nums[i]);
            
            if(minHeap.size()>n)
            {
                rsum -= minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size()==n)
                rsumt[i] = rsum;
        }

        for(int i=0;i<nums.size()-n;i++)
        {
            lsum += nums[i];
            maxHeap.push(nums[i]);
            
            if(maxHeap.size()>n)
            {
                lsum -= maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size()==n)
                ans = min(ans, lsum-rsumt[i+1]);
        }
        
        return ans;
    }
};
