class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> sub;
        sub.push_back(nums.front());
        // 1 4 6 3
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num > sub.back()) sub.push_back(num);
            else {
                int j = std::ranges::lower_bound(sub,num) - sub.begin();
                sub[j] = num;
            }
        }

        return sub.size();
        
    } 
};