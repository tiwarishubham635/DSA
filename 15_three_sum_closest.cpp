int threeSumClosest(vector<int> arr, int target)
    {
        int res = INT_MIN, minDiff = INT_MAX;
        sort(arr.begin(), arr.end());
    
        for (int i = 0; i < arr.size(); i++)
        {
            int sum = arr[i];
            int l = i + 1, h = arr.size() - 1;
    
            while (l < h)
            {
                int temp = sum + arr[l] + arr[h];
    
                int diff = abs(target - temp);
    
                if (diff == 0)
                    return temp;
                else if (temp < target)
                    l++;
                else
                    h--;
    
                if (minDiff == diff)
                {
                    res = max(res, temp);
                }
                else
                {
                    minDiff = min(diff, minDiff);
                    if (minDiff == diff)
                        res = temp;
                }
            }
        }
    
        return res;
    }
