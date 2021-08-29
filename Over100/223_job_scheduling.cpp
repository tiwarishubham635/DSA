class Job{
public:
    int start, finish, profit;
};
bool cmp(Job a, Job b){
    return a.finish < b.finish;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = profit.size();
        Job vec[n];
        
        for(int i = 0; i < n; i++){
            vec[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        sort(vec, vec + n, cmp);
        
        int dp[n];
        dp[0] = vec[0].profit;
        
        for(int i = 1; i < n; i++)
        {
            int include = vec[i].profit;
            int last = -1;
            
            for(int j = i - 1; j >= 0; j--)
            {
                if(vec[j].finish <= vec[i].start){
                    last = j;
                    break;
                }
            }
            
            if(last != -1)
                include += dp[last];
            
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }
        
        return dp[n - 1];
    }
};
