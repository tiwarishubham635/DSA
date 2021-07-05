#define R (8417508174513LL)
#define X (165131LL)

#define MOD(x) ((x%R+R)%R)

class Solution 
{
 public:
    bool verify(int L, vector<vector<int>>& paths) 
    {
        long long tail = 1;
        for (int i=0;i<L-1;++i) 
            tail = MOD(tail*X); // calculates hash of first path of length L in paths[0]
        
        map<long long, int> mark;
        auto& p0 = paths[0];
        long long v = 0;
        for (int i=0;i<p0.size();++i) 
        {
            v =  MOD(v * X + p0[i]); // calculates running hash
            if (i >= L-1) 
            {
                mark[v] = 1;         // when L length subpath is found, hash it
                
                // here the value can be negative
                // that's why MOD is defined that way
                v = MOD(v - p0[i-L+1] * tail); // subtract the previous part of hash to include the 
                                               // next part
            }
        }
        
        for (int p=1;p<paths.size();++p) 
        {
            v = 0;
            auto& pth = paths[p];  // traverse all paths to check if any of the hash value is present
            
            for (int i=0;i<pth.size();++i) 
            {
                v = MOD(v * X + pth[i]);
                if (i>=L-1) 
                {
                    if (mark.count(v) > 0 && mark[v] == p) // only the hash which is present in all 
                    {                                      // previous paths is increased
                        mark[v] += 1;
                    }
                    v = MOD(v - pth[i-L+1]*tail); // subtract the previous part of hash to include the
                                                  // next part
                }
            }
        }
        
        for (auto it : mark) 
        {
            if (it.second == paths.size()) // a hash that is present in all paths 
                return true;
        }
        return false;
    }
    
    
    int longestCommonSubpath(int n, vector<vector<int>>& paths) 
    {
        int best = 0;
        // sort paths in increasing order of size
        sort(paths.begin(), paths.end(), [&](auto& p1, auto& p2) { return p1.size() < p2.size(); });
        
        int L = 0, H = paths[0].size() + 1;
        while (H - L > 1) 
        {
            int m = (H+L) / 2; // choose a length for subpath in smallest length path
            if (verify(m, paths)) 
                L = m;         // m will be an ans, but we want the largest subpath
            else H = m;
        }
        return L;
    }
};
