class KthLargest {
private: 
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<>> pq = {};
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto i : nums) pq.push(i);
        this->k = k;
        while (pq.size() > k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);

        if (pq.size() > k) {
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */