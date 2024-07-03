class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> sub = {nums[0]};

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            if (num > sub.back()) {
                sub.push_back(num);
            } else {
                int j = std::lower_bound(sub.begin(), sub.end(), num) - sub.begin();

                sub[j] = num;
            }
        }

        return sub.size();
    }
};