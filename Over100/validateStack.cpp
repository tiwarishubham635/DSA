class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        /*
        stack<int>st;
        vector<bool>in_the_stack(1001, false);
        int top = -1;
        
        int j=0;// pushed index
        
        for(int i=0;i<n;i++)
        {
            while((!in_the_stack[popped[i]]) && j<n)
            {
                in_the_stack[pushed[j]] = true;
                st.push(pushed[j]);
                j++;
            }
            
            if(st.top()!=popped[i])
                return false;
                        
            in_the_stack[popped[i]] = false;
            st.pop();
        }
        return true;*/
        int j=0, i=0;
        for(int k=0;k<n;k++)
        {
            pushed[i] = pushed[k];
            i++;
            while(i>0 && pushed[i-1]==popped[j])
                j++, i--;
        }
        
        return i==0;
    }
};
