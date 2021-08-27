class Solution {
    static bool cmp(string a, string b)
    {
        return a.size() > b.size();
    }
    
    static bool SjSubsequenceOfSi(string a, string b)
    {
        int i=0, j=0;
        while(i<a.size()&&j<b.size())
        {
            if(a[i]==b[j])
                j++;
            i++;
        }
        return (j==b.size());
    }
    
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), cmp);
        unordered_map<string, int>mp;
        
        for(int i=0;i<strs.size();i++)
            mp[strs[i]]++;
        
        for(int i=0;i<strs.size();i++)
        {
            if(mp[strs[i]]==1)
            {
                int j = 0;
                for(;j<i;j++)
                {
                    if(SjSubsequenceOfSi(strs[j], strs[i]))
                        break;
                }
                if(j==i)
                    return strs[i].size();
            }
        }
        return -1;
    }
};
