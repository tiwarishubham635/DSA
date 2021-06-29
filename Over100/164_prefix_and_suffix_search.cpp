/* class WordFilter {
public:
    unordered_map<string, int>mp;
    
    WordFilter(vector<string>& words) 
    {
        for(int i=0;i<words.size();i++)
        {
            string x = words[i];
            for(int j=1;j<=x.size();j++)
            {
                string p = x.substr(0,j);
                for(int k=0;k<x.size();k++)
                {
                    mp[p + "*" + x.substr(k,x.size())]=i+1;
                }
            }
        }
    }
    
    int f(string pre, string suf) 
    {
        return mp[pre + "*" + suf]-1;
    }
}; */

using t_elt = unsigned short;
using t_item = short;

const int triesz = 50000, maxItems = 15001;
t_elt pre[triesz][28] {}, post[triesz][28] {}, presz=0, postsz=0;
t_item preItems[maxItems], postItems[maxItems], s1[maxItems] {-1}, s2[maxItems] {-1};
int speedup = [] { ios::sync_with_stdio(0); cin.tie(0); return 0; }();

inline void add(const string &word, t_item idx, t_elt trie[][28], t_elt &sz, int bg, int ed, int step) {
    t_elt pos = 0;
    for (int i = bg; i != ed; i += step) {
        auto &t = trie[pos][word[i]-'a'];
        if (!t) t = sz++;
        pos = t;
    }
    trie[pos][26] = idx+1;
}

inline int build(t_elt trie[][28], t_item items[], t_elt pos, int idx) {
    int left = idx;
    if (trie[pos][26] != 0) items[idx++] = trie[pos][26]-1;
    for (int i = 0; i < 26; ++i)
        if (trie[pos][i]) idx = build(trie, items, trie[pos][i], idx);
    trie[pos][26] = left;
    trie[pos][27] = idx-left;
    return idx;
}

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        memset(pre, 0, presz*sizeof pre[0]);    presz = 1;
        memset(post, 0, postsz*sizeof post[0]); postsz = 1;
        for (int i = 0; i < words.size(); ++i) {
            add(words[i], i, pre,  presz,  0, words[i].size(), 1);
            add(words[i], i, post, postsz, words[i].size()-1, -1, -1);
        }
        build(pre, preItems, 0, 0);
        build(post, postItems, 0, 0);
    }
    
    int f(string prefix, string suffix) {
        int pos = 0;
        for (char c : prefix) if (!(pos = pre[pos][c-'a'])) return -1;
        int l1 = pre[pos][26], sz1 = pre[pos][27];
        
        pos = 0;
        for (int i = suffix.size()-1; i >= 0; --i) if (!(pos = post[pos][suffix[i]-'a'])) return -1;
        int l2 = post[pos][26], sz2 = post[pos][27];
        
        for (int i = 0; i < sz1; ++i) s1[i+1] = preItems[i+l1];
        for (int i = 0; i < sz2; ++i) s2[i+1] = postItems[i+l2];
        
        if (sz1*sz2 < 3000) {
            t_item *bg = s1+1, *ed = bg+sz1, best = -1;
            for (int i = sz2; i; --i)
                if (s2[i] > best && find(bg, ed, s2[i]) != ed) best = s2[i];
            return best;
        }
        
        sort(s1+1, s1+1+sz1);
        sort(s2+1, s2+1+sz2);
        while (s1[sz1] != s2[sz2]) if (s1[sz1] > s2[sz2]) --sz1; else --sz2;
        return s1[sz1];
    }
};
