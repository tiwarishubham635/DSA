// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

class Solution {
public:
    int minimumSum(int num) {
        vector<int>ans;
        while(num)
            ans.push_back(num%10), num/=10;
        sort(ans.begin(), ans.end());
        return (10*ans[0]+ans[2])+(10*ans[1]+ans[3]); // the two smallest numbers to hold the tens place and two largest numbers to hold the ones place
    }
};
