class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> sub = {nums[0]};

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            if (num > sub.back()) {
                sub.push_back(num);
            } else {
                int j = 0;
                while (num > sub[j]) {
                    j += 1;
                }

                sub[j] = num;
            }
        }

        return sub.size();
    }
};