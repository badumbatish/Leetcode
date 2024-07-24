class Solution {

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        std::ranges::sort(nums, [&](auto a, auto b) { return transform_int(mapping, a) < transform_int(mapping, b); });
        
        return nums;
    }

    static int transform_int(std::vector<int>&mapping, int num) {
        if (num == 0) return mapping[0];
        int64_t result = 0;
        int64_t power = 1;
        do {
            result = power * mapping[num % 10] + result;
            power *= 10;
            num /= 10;
        } while (num);
        
        return result;
    }
};