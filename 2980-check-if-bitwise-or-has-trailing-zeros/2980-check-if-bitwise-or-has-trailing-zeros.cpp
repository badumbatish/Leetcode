class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = std::count_if(nums.begin(), nums.end(), [](int a){ return a % 2 == 0;});

        return count >= 2;
    }
};