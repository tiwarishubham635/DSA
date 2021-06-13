long long getMaxArea(long long arr[], int n)
    {
        stack<int>st;
        long long area = 0;
        int i;
        for(i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                long long height = arr[st.top()];
                st.pop();
                long long width;
                if(st.empty())
                    width = i;
                else width = (i-st.top()-1);
                if(area < width*height)
                    area = width*height;
            }
            
            st.push(i);
        }
        
        while(!st.empty())
        {
            long long height = arr[st.top()];
            st.pop();
            long long width;
            if(st.empty())
                width = i;
            else width = (i-st.top()-1);
            if(area < width*height)
                area = width*height;
        }
        
        return area;
    }
