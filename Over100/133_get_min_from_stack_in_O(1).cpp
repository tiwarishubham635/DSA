class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

*/

/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty())
        return -1;
   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty())
        return -1;
   int y = s.top();
   s.pop();
   if(y < minEle)
    {   int val = minEle;
       minEle = 2*minEle - y;
       return val;
    }
   
   return y;
}

/*push element x into the stack*/
void _stack::push(int x)
{
   if(s.empty())
   {
       minEle = x;
       s.push(x);
   }
   
   else
   {
       if(x < minEle)
          s.push(2*x-minEle), minEle=x;
          
       else
        s.push(x);
   }
}
