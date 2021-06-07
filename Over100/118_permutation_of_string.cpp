vector<string>find_permutation(string s)
		{
		    vector<string>ans;
		    int n = s.size();
		    
		    sort(s.begin(), s.end());
		    bool finished = 0;
		    
		    while(!finished)
		    {
		        ans.push_back(s);
		        int i;
		        for(i=n-2;i>=0;i--)
		            if(s[i]<s[i+1])
		                break;
		        
		        if(i<0)
		            finished=1;
		        
		        else
		        {
		            int idx=i+1;
    		        for(int j=i+2;j<n;j++)
    		            if(s[j]>s[i]&&s[j]<s[idx])
    		                idx = j;
    		        
    		        swap(s[idx], s[i]);
    		        string x = s.substr(i+1);
    		        sort(x.begin(), x.end());
    		        s = s.substr(0, i+1) + x;
		        }
		    }
		    
		    return ans;
		}
