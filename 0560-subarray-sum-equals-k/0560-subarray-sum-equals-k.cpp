class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;

        std::unordered_map<int, int> mp = {{0, 1}};

        for (auto num : nums) {
            sum += num;
            count += mp[sum-k];
            mp[sum]+=1;
        }

        return count;
    }
};