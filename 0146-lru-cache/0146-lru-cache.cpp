class LRUCache {
private:
// In this scheme, the front of list is most recently used.
// the back of the list is least recently used.
    int capacity; // capacity of the lru
    std::list<std::pair<int, int>> lru; // the head of the lru linked list 
    std::map<int, std::list<std::pair<int, int>>::iterator> mp; // a map that maps a key to the node of the linked list
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = mp.find(key);

        if (it == mp.end()) return -1;

        auto value = it->second->second;
        put(key, value);

        return value;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);

        if (it != mp.end()) {
            lru.erase(it->second);
            mp.erase(it);
        }

        lru.push_front({key, value});
        mp[key] =  lru.begin();

        if (mp.size() > capacity) {
            auto it = mp.find(lru.rbegin()->first);
            mp.erase(it);
            lru.pop_back();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */