// Question: https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        /*int i=m-1, j=n-1, k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            
            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        
        while(i>=0)
        {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        
        while(j>=0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }*/
        for(int i=0;i<n;i++)
            nums1[i+m] = nums2[i];
        
        int gap = (m+n);
        int k = 0;
        if(gap&1)
            k++;
        gap /= 2;
        gap += k;
        
        while(gap>=1)
        {
            int i=0,j=i+gap;
            while(j<(m+n))
            {
                if(nums1[i] > nums1[j])
                    swap(nums1[i], nums1[j]);
                i++, j++;
            }
            
            if(gap == 1)
                break;
            
            k = 0;
            if(gap&1)
                k++;
            gap /= 2;
            gap += k;
        }
    }
};

// Little variation: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1/?track=md-arrays&batchId=144#

void merge(int arr1[], int arr2[], int n, int m) 
	{
	    int max_ele = arr1[0];
	    for(int i=1;i<n;i++)
	        if(max_ele < arr1[i])
	            max_ele = arr1[i];
	            
	   for(int i=0;i<m;i++)
	        if(max_ele < arr2[i])
	            max_ele = arr2[i];
	            
	   max_ele++;//to have unique remainders 
	   int i,j,k;
	   for(i=0, j=0,k=0;i<n&&j<m;)
	   {
	       int e1 = arr1[i]%max_ele; // old value of arr1[i]
	       int e2 = arr2[j]%max_ele; // old value of arr2[j]
	       if(e1<=e2)
	       {
	           if(k<n)
	            arr1[k] += e1*max_ele;
	           else
	            arr2[k-n] += e1*max_ele;
	           k++; i++;
	       }
	       else
	       {
	           if(k<n)
	            arr1[k] += e2*max_ele;
	           else
	            arr2[k-n] += e2*max_ele;
	           k++; j++;
	       }
	   }
	   
	   while(i<n)
	   {
	       if(k<n)
	        arr1[k] += (arr1[i]%max_ele)*max_ele;
	       else
	        arr2[k-n] += (arr1[i]%max_ele)*max_ele;
       k++; i++;
	   }
	   
	   while(j<m)
	   {
	       if(k<n)
	        arr1[k] += (arr2[j]%max_ele)*max_ele;
	       else
	        arr2[k-n] += (arr2[j]%max_ele)*max_ele;
	       k++; j++;
	   }
	   
	   for(int i=0;i<n;i++)
	    arr1[i] = arr1[i]/max_ele;
	    
	   for(int j=0;j<m;j++)
	    arr2[j] = arr2[j]/max_ele;
	}

//Approach - 2: Gap method
void merge(int arr1[], int arr2[], int n, int m) {
	    int gap = (m+n);
	    int k = (gap&1 ? 1:0);
	    gap = (gap/2) + k;
	    
	    while(true)
	    {
	        int i=0,j=i+gap;
	        while(j<n)
	        {
	            if(arr1[i] > arr1[j])
	                swap(arr1[i], arr1[j]);
	            i++, j++;
	        }
	        
	        j=0;
	        while(i<n&&j<m)
	        {
	            if(arr1[i] > arr2[j])
	                swap(arr1[i], arr2[j]);
	            i++, j++;
	        }
	        
	        if(j<m)
	            i=0;
	        
	        while(j<m)
	        {
	            if(arr2[i] > arr2[j])
	                swap(arr2[i], arr2[j]);
	            i++, j++;
	        }
	        
	        if(gap==1)
	            break;
	        
	        k = (gap&1 ? 1:0);
	        gap = (gap/2) + k;
	    }
	}
