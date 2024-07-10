class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) mp[nums[i]] = i;

        std::vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(target - nums[i]) && mp[target - nums[i]] != i) {
                return {i, mp[target - nums[i]]};
            } 
        }

        return {};
    }
};