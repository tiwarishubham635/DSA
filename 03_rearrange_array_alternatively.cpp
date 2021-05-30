void rearrange(long long *arr, int n) 
    {
        /* To store two values at a single index, maintain max_ele = max(original array elements)+1;
         dividend = (quotient)*divisor + remainder
         arr[i] = (new value)*divisor + old value
         max_index = n-1, min_index = 0;
         for storing max elements at even index:
            arr[i] = (arr[max_index]%max_ele)*max_ele +    arr[i];
                            (new value)      (divisor)   (old value)
            max_index--
                            
         for storing min elements at odd index:
            arr[i] = (arr[min_index]%max_ele)*max_ele +    arr[i];
                            (new value)      (divisor)   (old value)
            min_index++
            
        finally for all i:
            arr[i] = arr[i]/max_ele;
        */ 
        int max_index = n-1, min_index = 0;
        long long max_ele = arr[n-1]+1;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                arr[i] += (arr[max_index]%max_ele)*max_ele;
                max_index--;
            }
            else
            {
                arr[i] += (arr[min_index]%max_ele)*max_ele;
                min_index++;
            }
        }
        for(int i=0;i<n;i++)
        {
            arr[i] = arr[i]/max_ele;
        }
    }
