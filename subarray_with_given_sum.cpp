/*vector<int> subarraySum(int arr[], int n, int s) // Handles only positive numbers
    {
        int l = 0, r = 0, sum = arr[l];
        while (r < n)
        {
            if (sum == s)
            {
                vector<int> ans;
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                return ans;
            }
            if (sum < s)
            {
                r++;
                sum += arr[r];
            }
            else
            {
                while (sum > s)
                {
                    sum -= arr[l];
                    l++;
                }
            }
        }
        //cout<<-1<<endl;
        vector<int> ans;
        ans.push_back(-1);
        return ans;
    }*/
    
    vector<int> subarraySum(int arr[], int n, int sum) //handles negatives too
    { 
    	unordered_map<int, int> map;
    	int curr_sum = 0;
    	vector<int>ans;
    
    	for (int i = 0; i < n; i++) 
    	{ 
    		curr_sum = curr_sum + arr[i];
    		if (curr_sum == sum) 
    		{ 
    			ans.push_back(1);
    			ans.push_back(i+1);
    			return ans; 
    		} 
    		
    		if (map.find(curr_sum - sum) != map.end()) 
    		{ 
    			ans.push_back(map[curr_sum - sum] + 1+1); 
    			ans.push_back(i+1); 
    			return ans; 
    		} 
    		map[curr_sum] = i; 
        }
        ans.push_back(-1);
        return ans;
    
