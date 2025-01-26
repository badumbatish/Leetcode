class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> length(n, 1), count(n, 1), dp(n, 0);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    } 
                    if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }

            }
        }
       int maxLength = *max_element(length.begin(), length.end());
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength) {
                result += count[i];
            }
        }

        return result; 
    }
};