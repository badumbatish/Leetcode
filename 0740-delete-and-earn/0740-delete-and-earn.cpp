class Solution {
    std::map<int, int> cache;
    std::map<int, int> mp;

public:
    int deleteAndEarn(vector<int>& nums) {
        for (auto n : nums) mp[n]+=n;

        int mama = std::max_element(mp.begin(), mp.end())->first;

        return max_points(mama);
    }

    int max_points(int num) {
        if (num == 0) return 0;
        else if (num == 1) return mp[1];

        if (cache.contains(num)) return cache[num];
        
        cache[num] = std::max(max_points(num-1), max_points(num-2) + mp[num]);
        return cache[num];
    }
};