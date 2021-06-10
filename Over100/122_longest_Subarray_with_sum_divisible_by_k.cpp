int longSubarrWthSumDivByK(int arr[], int n, int k)
{
    int* mod_arr = new int[n]; int sum=0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        mod_arr[i] = ((sum%k)+k)%k;
    }

    unordered_map<int,int>mp;
    int max_len=0;
    for(int i=0;i<n;i++)
    {
        if(mod_arr[i]==0)
            max_len=i+1;
        else if(mp.find(mod_arr[i])==mp.end())
            mp[mod_arr[i]]=i;
        else
        {
            int idx = mp[mod_arr[i]];
            if(max_len < i-idx)
                max_len = (i-idx);
        }
    }
    return max_len;
}
