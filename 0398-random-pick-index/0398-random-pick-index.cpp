class Solution {
    std::unordered_map<int, std::vector<int>> mp;
public:

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            // add in the group of target, the index i
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        // generate [0, 1] * len of our group
        auto &group_target = mp[target];

        double d = rand() % group_target.size(); 

        return group_target[d];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */