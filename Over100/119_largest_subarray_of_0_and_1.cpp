int maxLen(int arr[], int n)
{
    unordered_map<int,int>mp;
    int sum=0, max_len=0;
    for(int i=0;i<n;i++)
        arr[i] = (arr[i]==0)?-1:1;

    for(int i=0;i<n;i++)
    {
        sum += arr[i];

        if(sum==0)
            max_len = i+1;

        if(mp.find(sum) != mp.end())
        {
            if(max_len < i - mp[sum])
                max_len = i-mp[sum];
        }

        else mp[sum] = i;
    }
    return max_len;
}
