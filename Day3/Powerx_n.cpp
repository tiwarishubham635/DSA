// Question: https://leetcode.com/problems/powx-n/
class Solution {
    double power(double x, long long n)
    {
        if(x == 0.0 or x == 1.0)
            return x;
        if(n == 0)
            return 1.0;
        
        double val = power(x, n/2);
        val *= val;
        
        if(n&1)
            return x*val;
        return val;
    }
public:
    double myPow(double x, int n) {
        long long n1 = n;
        if(n < 0)
            n1 *= -1;
        //double ans = power(x, n1);
        double ans = 1.0;
        while(n1)
        {
            if(n1&1)
            {
                ans *= x;
                n1--;
            }
            else
            {
                x *= x;
                n1 /= 2;
            }
        }
        if(n < 0)
            ans = (double)(1.0)/ans;
        return ans;
            
    }
};
