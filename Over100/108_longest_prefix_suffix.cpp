int lps(string s)
	{
	    int n=s.size();
	    int* lps_array = new int[n];
	    int len = 0, i=1;
	    lps_array[0] = 0;
	    while(i<n)
	    {
	        if(s[i]==s[len])
	        {
	            len++;
	            lps_array[i]=len;
	            i++;
	        }
	        
	        else
	        {
	            if(len==0)
	                lps_array[i] = 0, i++;
	            
	            else
	                len = lps_array[len-1];
	        }
	    }
	    
	    return lps_array[n-1];
	}
