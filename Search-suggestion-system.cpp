// https://leetcode.com/problems/search-suggestions-system/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>>mp;
        
        for(int i=0;i<products.size();i++)
        {
            string word = products[i];
            for(int j=1;j<=word.size();j++)
            {
                string prefix = word.substr(0, j);
                if(mp[prefix].size()<3)
                    mp[prefix].push_back(word);
            }
        }
        
        string word = searchWord;
        for(int j=1;j<=word.size();j++)
        {
            string prefix = word.substr(0, j);
            ans.push_back(mp[prefix]);
        }
        
        return ans;
    }
};

// Solution 2 - Binary search

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        
        /*unordered_map<string, vector<string>>mp;
        
        for(int i=0;i<products.size();i++)
        {
            string word = products[i];
            for(int j=1;j<=word.size();j++)
            {
                string prefix = word.substr(0, j);
                if(mp[prefix].size()<3)
                    mp[prefix].push_back(word);
            }
        }*/
        
        string word = searchWord;
        string prefix = "";
        int bsStart = 0, start, n = products.size();
        for(int j=0;j<word.size();j++)
        {
             prefix += word[j];
            //ans.push_back(mp[prefix]);
            
            start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();

           vector<string>result;

            // till prefix is same, add 3 words
            for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); i++)
                result.push_back(products[i]);
            
            ans.push_back(result);

            bsStart = start;
        }
        
        return ans;
    }
};
