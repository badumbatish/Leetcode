class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::unordered_set<int> s;
        bool has_zero = false;
        for (auto num : arr) {
            if (num == 0) {
                if (s.contains(0)) return true;
                has_zero = true;
            }
            s.insert(num);
        }
        s.erase(0);
        for (auto n : s) 
            if (s.contains(n*2)) return true;
        
        if (has_zero) return false;
        return false;
    }
};