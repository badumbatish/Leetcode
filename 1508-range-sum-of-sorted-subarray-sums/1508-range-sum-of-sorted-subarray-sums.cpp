class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        std::vector<int> prefix = {0};

        for (auto i : nums) prefix.push_back(i + prefix.back());

        

        std::vector<int> result;
        for (int i = 0; i < prefix.size(); i++) {
            for (int j = i+1; j < prefix.size(); j++) {
                result.push_back(prefix[j] - prefix[i]);
            }
        }
        std::sort(result.begin(), result.end());

        int64_t sum =0 ;
        for (int i = left - 1; i < right; i++) {
            sum+= result[i];
            sum %= 1000000007;
        }
        return sum;
    }
};