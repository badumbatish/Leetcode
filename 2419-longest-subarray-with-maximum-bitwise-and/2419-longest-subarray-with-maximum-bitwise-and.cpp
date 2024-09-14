class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = 0, ans = 0, current_streak = 0;

        for (int num : nums) {
            if (max_val < num) {
                max_val = num;
                ans = current_streak = 0;
            }

            if (max_val == num) {
                current_streak++;
            } else current_streak = 0;

            ans = max(ans, current_streak);
        }

        return ans;
    }
};