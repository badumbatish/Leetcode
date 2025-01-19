class Solution {
public:
    using ll = long long;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::ranges::sort(nums);
        return kSum(nums, target, 0, 4);
    }

    std::vector<std::vector<int>> kSum(std::vector<int>&nums, ll target, int start, int k) {
        decltype(kSum(nums, target, start, k)) res;

        if (start == nums.size()) return res;

        ll avg = target / k;

        if (nums[start] > avg || avg > nums.back()) return res;
        if (k == 2) return twoSum(nums, target, start);

        for (int i = start; i < nums.size(); i++) {
            if (i == start || nums[i-1] != nums[i]) {
                for (auto &subset : kSum(nums, (ll)target - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), std::begin(subset), std::end(subset));
                }
            }
        }
        return res;
    }
    std::vector<std::vector<int>> twoSum(std::vector<int>& nums, ll target, int start) {
        std::vector<std::vector<int>> res;

        int low = start, high = (int)nums.size() - 1;

        while (low < high) {
            int curr_sum = nums[low] + nums[high];
            if (curr_sum < target || (low > start && nums[low] == nums[low -1])) low++;
            else if (curr_sum > target || (high < nums.size() - 1 && nums[high] == nums[high + 1])) high--;
            else res.push_back({nums[low++], nums[high--]});
        }
        return res;
    }
};