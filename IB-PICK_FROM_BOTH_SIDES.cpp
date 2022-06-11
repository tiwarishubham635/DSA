// Problem - https://www.interviewbit.com/problems/pick-from-both-sides/

int Solution::solve(vector<int> &arr, int num_of_values) {
    int n = arr.size();
    
    // Approach - 1
    /*int size_of_subarray = n - num_of_values;
    
    int l=0, r=0;
    long long sum = 0, TotalSum = 0;
    while(r-l < size_of_subarray)
        sum += arr[r], TotalSum += arr[r], r++;
    
    long long minsum = sum;
    
    while(r<n)
    {
        sum -= arr[l], l++;
        TotalSum += arr[r];
        sum += arr[r], r++;
        
        minsum = min(minsum, sum);
    }
    
    return TotalSum - minsum;*/
    
    // Approach - 2                        
    vector<long long> prefix(n+1, 0); 
    vector<long long> suffix(n+1, 0); 
    
    for(int i=1;i<=n;i++)
        prefix[i] = prefix[i-1] + arr[i-1],
        suffix[n-i] = suffix[n-i+1] + arr[n-i];
    
    long long maxsum = INT_MIN;
    for(int i=0;i<=num_of_values;i++)
    {
        // i = no. of values from left in the removed subarray
        // x = no. of values from right = num_values - i from end
        long long sum = prefix[i] + suffix[n - (num_of_values - i) ];
        maxsum = max(maxsum, sum);
    }
    
    return maxsum;
}
