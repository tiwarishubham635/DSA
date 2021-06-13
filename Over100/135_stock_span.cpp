vector <int> calculateSpan(int price[], int n)
    {
        vector<int>ans(n);
       ans[0] = 1;
        
        /*int maxindex = 0;
        for (int i = 1; i < n; i++)
        {
            if (price[i] >= price[maxindex])
            {
                ans[i] = i + 1;
                maxindex = i;
            }
            else
            {
                int j = i - 1, ct = 1;
                while (price[j] <= price[i] && j >= 0)
                {
                    ct++;
                    j--;
                }
                ans[i] = ct;
            }
        }*/
        
        stack<int> s;
        s.push(0);
        for (int i = 1; i < n; i++)
        {
            // Analyze using bar graph. If given value is greater than a[stack top], then pop the stack
            while (!s.empty() && price[i] >= price[s.top()])
            {
                s.pop();
            }
    
            // If stack is empty, the given value is maximum, so ans[i] = i+1.
            // Else, the difference between the position of given value and stack top, gives ans[i]
            // ANALYSE USING BAR GRAPH
            ans[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        return ans;
    }
