int *findTwoElement(int *arr, int n) 
    {
        int ele, rem;
        /*
        approach 1
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] *= -1;
            
            else
                ele = abs(arr[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                rem = i+1;
                break;
            }
        }*/
        
        /*
        approach 2
        long long sum = 0, product = 1;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            product *= arr[i];
        }
        
        sum = n*(n+1)/2 - x + y;
        product = fact(n)*y/x
        
        x = (fact(n)*y/product)
        x = n*(n+1)/2 + y - sum
        
        n*(n+1)/2 + y - sum = (fact(n)*y/product)
        n*(n+1)*product/2 + y*product - sum*product = fact(n)*y
        n*(n+1)*product/2 - sum*product = fact(n)*y - y*product
        
        y = (n*(n+1)/2 - sum)/(fact(n)/product - 1)
        x = n*(n+1)/2 + y - sum
        
        ele = y
        rem = x

        int* ans = new int[2];
        ans[0] = ele;
        ans[1] = rem;
        return ans;
        */
        
        /*
        approach 3
        */
    
       int res=0;
       for(int i=0;i<n;i++){
           res^=arr[i];
       }
       for(int i=1;i<=n;i++){
           res^=i;
       }
       int rep=0,miss=0;
       int lbs=res&~(res-1);
       for(int i=0;i<n;i++){
           if(arr[i]&lbs)
               rep=rep^arr[i];
           else
               miss=miss^arr[i];
       }
       for(int i=1;i<=n;i++){
           if(i&lbs)
               rep=rep^i;
           else
               miss=miss^i;
       }
       if(find(arr,arr+n,rep)!=arr+n){
           return new int[2]{rep,miss};
       }
       else
           return new int[2]{miss,rep};
    }
