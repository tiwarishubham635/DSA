class Solution {
public:
    static bool isPallindrome(string a)
    {
        for(int i=0;i<a.size()/2;i++)
            if(a[i]!=a[a.size()-1-i])
                return false;
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>>ans;
        int n = words.size();
        
        unordered_map<string, int>mp;
        for(int i=0;i<n;i++)
        {
            string x = words[i];
            reverse(x.begin(), x.end());
            mp[x]=i;
        }
        
        if(mp.find("")!=mp.end())
        {
            for(int i=0;i<n;i++)
            {
                if(words[i].size()!=0 && isPallindrome(words[i]))
                {
                    ans.push_back({mp[""], i});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                
                if(mp.find(left)!=mp.end() && isPallindrome(right) && mp[left]!=i)
                    ans.push_back({i, mp[left]});
                
                if(mp.find(right)!=mp.end() && isPallindrome(left) && mp[right]!=i)
                    ans.push_back({mp[right], i});
            }
        }
        
        return ans;
    }
};
