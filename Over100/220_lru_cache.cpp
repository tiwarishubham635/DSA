class LRUCache {
    list<int>lru;
    unordered_map<int,list<int>::iterator>mp;
    unordered_map<int, int>key_val;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    void updateLRU(int key)
    {
        if(key_val.count(key))
            lru.erase(mp[key]);
        lru.push_front(key);
        mp[key] = lru.begin();
    }
    
    int get(int key) {
        if(key_val.find(key)==key_val.end())
            return -1;
        updateLRU(key);
        return key_val[key];
    }
    
    void put(int key, int value) {
        if(key_val.size()==cap && key_val.find(key)==key_val.end())
        {
            mp.erase(lru.back());
            key_val.erase(lru.back());
            lru.pop_back();
        }
        updateLRU(key);
        key_val[key] = value;
    }
};
