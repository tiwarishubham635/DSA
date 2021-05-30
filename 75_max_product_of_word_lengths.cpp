int maxProduct(vector<string>& words) 
    {
        int n = words.size();
        unordered_map<string, int>mp;
        for(int i=0;i<n;i++)
        {
            mp[words[i]]=0;
            for(int j=0;j<words[i].size();j++)
            {
                mp[words[i]]=(mp[words[i]] | (1<<(words[i][j]-'a')));
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((mp[words[i]]&mp[words[j]])==0)
                {
                    if(ans < (words[i].size())*(words[j].size()))
                        ans = (words[i].size())*(words[j].size());
                }
            }
        }
        return ans;
    }
