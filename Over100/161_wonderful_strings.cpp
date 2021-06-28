long long wonderfulSubstrings(string word) { // word = aabb
        long long ans = 0; 
        vector<int> no_of_times_seen_this_mask(1024,0);
        int mask = 0;
        no_of_times_seen_this_mask[0] = 1;

        for (char c : word) 
        {  
            mask ^= (1<<(c-'a')); 
            
            ans += no_of_times_seen_this_mask[mask]; // previously, each time we have seen this mask, from that index to this index, 
                                                  // there is a wonderful string having all characters with even frequency 
            
            no_of_times_seen_this_mask[mask]++;  // mask is seen this time
            
            for (int k=0;k<10;++k)
            {
                int change_of_one_place = mask^(1<<k); // flicking one position in mask, to check odd at exactly one position 
                ans += no_of_times_seen_this_mask[change_of_one_place]; 
            }
        }
        return ans;
    }
