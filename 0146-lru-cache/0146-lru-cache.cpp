class LRUCache {
    std::list<std::pair<int, int>> lq;
    std::unordered_map<int, decltype(lq.begin())> mp;

    int capacity = 0;
    int curr_size = 0;
public:
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        if (!mp.contains(key)) return -1;
        put(key, mp[key]->second);
        return mp[key]->second; 
    }
    
    void put(int key, int value) {
        if (mp.contains(key)) {
            lq.erase(mp[key]);
            mp.erase(key);
        }
        
        lq.push_front({key, value});
        mp[key] = lq.begin();
        if (mp.size() > capacity) {
            mp.erase(lq.rbegin()->first);
            lq.pop_back();
            curr_size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */