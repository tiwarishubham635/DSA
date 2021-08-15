int subarraysWithKDistinct(vector<int>& A, int K) 
    {
      vector<int> m(A.size() + 1);
      int res  = 0, prefix = 0, cnt = 0, i = 0, j = 0;
      for(; i < A.size(); ++i) 
      {
        if (m[A[i]] == 0) 
            cnt++;
          m[A[i]]++;
        if (cnt > K) 
            --m[A[j++]], --cnt, prefix = 0;
        while (m[A[j]] > 1) 
            ++prefix, --m[A[j++]];
        if (cnt == K) 
            res += prefix + 1;
      }
      return res;
    }
    
    /*int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }
    int atMostK(vector<int>& a, int k) {
        int l = 0, r = 0, ans = 0, n = a.size();
        unordered_map<int, int> mp;
        int ct = 0;
        while(r<n)
        {
            mp[a[r]]++;
            
            while(mp.size()>k)
            {
                mp[a[l]]--;
                if(mp[a[l]]==0)
                    mp.erase(a[l]);
                l++;
            }
            ans += (r-l+1);
            r++;
        }
        return ans;
    }*/
