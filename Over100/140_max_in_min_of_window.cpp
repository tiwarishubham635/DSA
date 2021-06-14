vector <int> maxOfMin(int arr[], int n)
    {
        int* left = new int[n];
        int* right = new int[n];
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty())
        {
            right[st.top()]=n;
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty())
        {
            left[st.top()]=-1;
            st.pop();
        }
        
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int len = (right[i] - left[i] -1);
            ans[len-1] = max(ans[len-1], arr[i]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            ans[i] = max(ans[i], ans[i+1]);
        }
        return ans;
    }
