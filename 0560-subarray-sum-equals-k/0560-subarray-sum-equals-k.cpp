class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0, curr_sum = 0;

        std::unordered_map<int, int> mp = {{0, 1}};

        for (auto num : nums) {
            curr_sum += num;
            count += mp[curr_sum-k];
            mp[curr_sum]++;
        }

        return count;
    
    }
};