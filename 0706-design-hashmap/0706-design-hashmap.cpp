#include <ranges>
class MyHashMap {
    // 1. HashMap is between 1-10000 (some small number) -> array
    // 2. An array of N buckets, where each buckets is some size M -> std::vector<std::list<int>>;
    //      hash an integer -> 0 to N -> index into it, search add to list if not exist.
    std::vector<std::list<std::pair<int, int>>> arr = std::vector<std::list<std::pair<int,int>>>(20);
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto search = std::ranges::find_if(arr[key % 20], [&](auto x) { return x.first == key;});
        if (search == arr[key % 20].end()) 
            arr[key%20].push_back({key, value});
        else search->second = value;
    }
    
    int get(int key) {
        for (auto [k, value] : arr[key % 20]) {
            if (k == key) return value;
        }
        return -1;
    }
    
    void remove(int key) {
        arr[key % 20].remove_if([&](auto p) {return p.first == key;});
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */