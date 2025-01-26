class Solution {
    std::unordered_map<uint16_t, uint16_t> mp;

public:
    int deleteAndEarn(vector<int>& nums) {
        for (auto n : nums) mp[n]+=n;

        int mama = std::max_element(mp.begin(), mp.end())->first;

        return max_points(mama);
    }

    int max_points(int num) {
        if (num == 0) return 0;
        else if (num == 1) return mp[1];

        int prev = 0, current = mp[1];
        for (int i = 2; i <= num; i++) {
            auto temp = current;
            current = std::max(current, prev + mp[i]);
            prev = temp;
        }
        return current;
    }
};