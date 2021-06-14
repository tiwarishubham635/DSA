bool recreationalSpot(int arr[], int n)
	{
	    if(n<3)
	        return false;
	    
	    int* premin = new int[n];
	    premin[0] = arr[0];
	    for(int i=1;i<n;i++)
	        premin[i] = min(premin[i-1], arr[i]);
	    
		stack<int>st;
		for(int i=n-1;i>=0;i--)
		{
		    if(arr[i]>premin[i])
		    {
		        while(!st.empty()&&st.top()<=premin[i])
		            st.pop();
		        
		        if(!st.empty()&&st.top()<arr[i])
		            return true;
		        st.push(arr[i]);
		    }
		}
		return false;
	}
