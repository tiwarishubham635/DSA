int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int,int>>arr(n);
	    for(int i=0;i<n;i++)
	        arr[i].first = nums[i], arr[i].second = i;
	    sort(arr.begin(), arr.end());
	    vector<int>is_at_correct_index(n,0);
	    int ans = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(is_at_correct_index[i] or arr[i].second==i)
	            continue;
	        int j = i;
	        int cycle_size=0;
	        while(!is_at_correct_index[j])
	        {
	           is_at_correct_index[j]=1;
	           j = arr[j].second;
	           cycle_size++;
	        }
	        ans += ((cycle_size>0)?(cycle_size-1):0);
	    }
	    return ans;
	}
