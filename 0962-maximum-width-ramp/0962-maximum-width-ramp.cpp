class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> stck;

        for (int i = 0; i < n; i++) {
            if (stck.empty() || nums[stck.back()] > nums[i]) {
                stck.push_back(i);
            }
        }


        int max_width = 0;
        for (int j =  n-1; j >=0; j--) {
            while (!stck.empty() && nums[stck.back()] <= nums[j]) {
                max_width = max(j - stck.back(), max_width);
                stck.pop_back();
            }
        }

        return max_width;
    }
};
