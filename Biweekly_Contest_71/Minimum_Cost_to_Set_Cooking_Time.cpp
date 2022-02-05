// https://leetcode.com/problems/minimum-cost-to-set-cooking-time/

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int max_minutes = targetSeconds/60;
        int ans = INT_MAX;
        for(int minutes=0;minutes<=max_minutes;minutes++)
        {
            int seconds = targetSeconds - 60*minutes;
            if(seconds > 99 or minutes>99) // either all part gone to seconds or minutes(6008)
                continue;
            
            string timer = to_string(100*minutes + seconds); // convert timer to 100
            char curr = (char)('0'+startAt);
            int cost = 0;
            for(int j=0;j<timer.size();j++) // calculate cost by checking characters
            {
                if(timer[j]!=curr)
                    cost += moveCost;
                
                cost += pushCost;
                curr = timer[j];
            }
            ans = min(ans, cost);
        }
        return ans;
    }
};
