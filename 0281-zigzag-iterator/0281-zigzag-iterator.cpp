class ZigzagIterator {
    std::queue<std::pair<std::vector<int>&, int>> vec_queue;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size() > 0) vec_queue.push({v1, 0});
        if (v2.size() > 0) vec_queue.push({v2, 0});
    }

    int next() {
        int ans = 0;

        auto [v, index] = vec_queue.front();
        vec_queue.pop();
        if (index < v.size()) ans = v[index];
        index++;
        if (index < v.size()) vec_queue.push({v, index});

        return ans;
    }

    bool hasNext() {
        return !vec_queue.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */