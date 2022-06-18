// https://leetcode.com/problems/prefix-and-suffix-search/

class WordFilter {
    /*unordered_map<string,vector<int>>prefix;
    unordered_map<string,vector<int>>suffix;*/
    
    unordered_map<string, int>mp;
public:
    WordFilter(vector<string>& words) {
        /*for(int i=0;i<words.size();i++)
        {
            string word = words[i];
            for(int j=1;j<=word.size();j++)
            {
                prefix[word.substr(0, j)].push_back(i);
                suffix[word.substr(word.size()-j, j)].push_back(i);
            }
        }*/
        
        for(int i=0;i<words.size();i++)
        {
            string word = words[i];
            for(int j=1;j<=word.size();j++)
            {
                string pref = word.substr(0, j);
                for(int k=1;k<=word.size();k++)
                {
                    string suff = word.substr(word.size()-k, k);
                    mp[pref + '@' + suff] = i;
                }
            }
        }
    }
    
    bool find(vector<int> &a, int val)
    {
        // a is sorted
        int low = 0, high = a.size()-1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(a[mid]==val)
                return true;
            
            if(a[mid]<val)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return false;
    }
    
    int f(string pref, string suff) {
        /*if(prefix.find(pref)==prefix.end())
            return -1;

        if(suffix.find(suff)==suffix.end())
            return -1;
         
        
       vector<int>pref_arr = prefix[pref];
        while(pref_arr.size()!=0 && find(suffix[suff], pref_arr[pref_arr.size()-1]) == false)
            pref_arr.pop_back();
        
        if(pref_arr.size()==0)
            return -1;
        
        return pref_arr[pref_arr.size()-1];*/
        
        string key = pref + '@' + suff;
        if(mp.find(key)==mp.end())
            return -1;
        return mp[key];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 
 a
 ap
 app
 appl
 apple
 
 e
 le
 ple
 pple
 apple
 */
