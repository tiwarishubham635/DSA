// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    vector<ull>ugly;
	    ugly.push_back(1); 
	    ull i2 = 0, //2
	    i3 = 0, // 2
	    i5 = 0; // 1
	    ull next2 = ugly[i2]*2,// 8
	    next3 = ugly[i3]*3,// 9
	    next5 = ugly[i5]*5;// 10
	    while(ugly.size()<n)
	    {
	        ull min_num = min(next2, min(next3, next5)); // 6
	        ugly.push_back(min_num);
	        
	        if(min_num==next2)
	            i2++, next2 = ugly[i2]*2;
	        
	        if(min_num==next3)
	            i3++, next3 = ugly[i3]*3;
	        
	        if(min_num==next5)
	            i5++, next5 = ugly[i5]*5;
	    }
	    return ugly[n-1];
	}
