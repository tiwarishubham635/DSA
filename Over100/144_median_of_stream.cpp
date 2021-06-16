class Solution
{
    priority_queue<int> lower_half;
    priority_queue<int,vector<int>,greater<int> > upper_half;
    double med;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(lower_half.size()==0)
            lower_half.push(x), med=x;
        
        else
            balanceHeaps(x);
    }
    
    //Function to balance heaps.
    void balanceHeaps(int x)
    {
        if (lower_half.size() > upper_half.size())
        {
            if (x < med)
            {
                upper_half.push(lower_half.top());
                lower_half.pop();
                lower_half.push(x);
            }
            else
                upper_half.push(x);
  
            //cout<<"case 1 : "<<lower_half.top()<<" "<<upper_half.top()<<" "
            //<<(lower_half.top()+upper_half.top())/2.0<<endl;
            med = (lower_half.top()+upper_half.top())/2.0;
            //cout<<med<<endl;
        }
  
        // case2(both heaps are balanced)
        else if (lower_half.size() == upper_half.size())
        {
            if (x < med)
            {
                lower_half.push(x);
                med = (double)(lower_half.top());
            }
            else
            {
                upper_half.push(x);
                med = (double)(upper_half.top());
            }
        }
        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                lower_half.push(upper_half.top());
                upper_half.pop();
                upper_half.push(x);
            }
            else
                lower_half.push(x);
  
            //cout<<"case 2 : "<<lower_half.top()<<" "<<upper_half.top()<<endl;
            med = (lower_half.top()+upper_half.top())/2.0;
            //med = med/2;
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        return med;
    }
};
