class RecentCounter {
private:
    std::vector<int> call_vec;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        call_vec.push_back(t);
        int count = 0;
        for (auto it = call_vec.rbegin(); it != call_vec.rend(); it++) {
            if (t - 3000 <= *it &&  *it <= t ) {
                count++;
            }
        }
        return count;
    }

    
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */