vector<int> canSeePersonsCount(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int>ans(n, 0);
        stack<int>st;
                
        for(int i=n-1;i>=0;i--)
        {
            int can_see = 0, h = temperatures[i];
            while(!st.empty()&&st.top()<=h)
            {
                can_see++;
                st.pop();
            }
            
            temperatures[i] = can_see + !st.empty();
            st.push(h);
        }
        
        return temperatures;
    }
