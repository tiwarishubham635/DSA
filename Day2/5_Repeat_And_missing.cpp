// Question: https://www.interviewbit.com/problems/repeat-and-missing-number-array/#

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    /*
    // Sum and sum of squares used
    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    vector <int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;*/

    // xor approach
    vector <int> ans(2);
    int xor1 = A[0];
    int n = A.size();
    for(int i=1;i<n;i++)
        xor1 ^= A[i];

    for(int i=1;i<=n;i++)
        xor1 ^= i;
    // so xor1 has x^y
    int rightmost_set_bit = xor1 & ~(xor1 - 1);
    // as x^y has rightmost_set_bit then x and y will have different bits at this position
    int missing = 0, repeated = 0; 
    for(int i=0;i<n;i++)
    {
        if(A[i] & rightmost_set_bit)
            missing ^= A[i];
        
        else
            repeated ^= A[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(i & rightmost_set_bit)
            missing ^= i;
        
        else
            repeated ^= i;
    }

    int mis_count = 0;

    for(int i=0;i<n;i++)
        if(A[i]==missing) // missing and repeated might be swapped
            mis_count++; 
    
    if(mis_count != 0)
        swap(missing, repeated);
    

    ans[0] = repeated;
    ans[1] = missing;
    return ans;
}

