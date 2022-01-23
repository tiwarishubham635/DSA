// Question: https://leetcode.com/problems/merge-intervals/

class Solution {
    bool overlap(vector<int> &a, vector<int> &b)
    {
        return !((a[0] > b[1]) or (a[1] < b[0]));
    }
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return (a[0] < b[0]);
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
        Approach:
        1. Sort the intervals on the basis of start time
        2. All the overlapping intervals will always be consecutive, so we will take one initial interval pair.
        3. We will check if this pair overlaps with next pair or not, if yes, then we update the merged interval
           and if not, then we store it in our answer.
        4. Two intervals do not overlap when:
            i. When first interval starts after the end of second interval. (Though sort will take care of this)
            ii. When first interval ended before start of second interval.
        */
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> intval = intervals[0];
        
        vector<vector<int>> ans;
        
        for(int i=1;i<intervals.size();i++)
        {
            if(overlap(intervals[i], intval))
            {
                intval[0] = min(intval[0], intervals[i][0]);
                intval[1] = max(intval[1], intervals[i][1]);                
            }
            
            else
            {
                ans.push_back(intval);
                intval = intervals[i];
            }
        }
        
        ans.push_back(intval);
        
        return ans;
    }
};
