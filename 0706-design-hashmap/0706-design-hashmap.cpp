class MyHashMap {
    // 1. HashMap is between 1-10000 (some small number) -> array
    // 2. An array of N buckets, where each buckets is some size M -> std::vector<std::list<int>>;
    //      hash an integer -> 0 to N -> index into it, search add to list if not exist.
    std::vector<int> arr = std::vector(1000001, -1);
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        arr[key] = value;
    }
    
    int get(int key) {
        return arr[key];
        
    }
    
    void remove(int key) {
       arr[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */