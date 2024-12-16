class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        std::priority_queue<std::tuple<int, int>, std::vector<std::tuple<int, int>>,std::greater<>> a;
        for (int i = 0; i < nums.size(); i++) a.push({nums[i], i});

        while (k--) {
            auto [num, index] = a.top(); a.pop();

            auto new_value = num * multiplier;

            nums[index] = new_value;
            a.push({new_value, index});
        }

        return nums;
    }
};