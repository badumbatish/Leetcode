class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto comparator = [&](int a, int b) {
            auto dist_a = std::abs(a-x); 
            auto dist_b = std::abs(b-x); 
            return (dist_a < dist_b) || (dist_a == dist_b && a < b);
        };

        std::ranges::sort(arr, comparator);
        std::sort(arr.begin(), arr.begin() +k);
        return std::vector<int>(arr.begin(), arr.begin() + k);
    }
};