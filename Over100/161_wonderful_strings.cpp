long long wonderfulSubstrings(string word) {
        long long res = 0;
        vector<int> cnt(1024);
        int x = 0;
        cnt[0] = 1;
        for (char c : word) {
            x ^= (1<<(c-'a'));
            res = res + cnt[x];
            cnt[x] += 1;
            for (int k=0;k<10;++k)
                res = res + cnt[x^(1<<k)];
        }
        return res;
    }
