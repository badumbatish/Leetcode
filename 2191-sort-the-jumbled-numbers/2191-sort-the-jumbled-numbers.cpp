class Solution {

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        std::vector<int> result(nums.size());
        std::ranges::transform(nums, result.begin(), [&](auto num) { return transform_int(mapping, num); });

        std::vector<int> index(nums.size());
        std::iota(index.begin(), index.end(), 0);
        std::ranges::sort(index, [&](auto a, auto b) { return result[a] < result[b];});
        std::ranges::transform(index, result.begin(), [&](auto i) { return nums[i];});
        return result;
    }

    static int transform_int(const std::vector<int>&mapping, int num) {
        int result = 0, power = 1;

        do {
            result = power * mapping[num % 10] + result;
            power *= 10;
            num /= 10;
        } while (num);
        
        return result;
    }
};