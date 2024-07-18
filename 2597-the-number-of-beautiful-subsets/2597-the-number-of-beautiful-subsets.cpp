class Solution {
    std::set<int> temp;
    std::unordered_map<int, int> mp;
    int count;
    int k;
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        this->k = k;

        std::ranges::sort(nums);
        
        dfs(nums, 0);

        return count;
    }

    void dfs(std::vector<int>& nums, int start) {
        for (int i = start; i < nums.size(); i++) {

            int minus_abs = nums[i] - k;

            //dfs(nums, i + 1);
            
            if (!mp[minus_abs]) {
                count++; 
                mp[nums[i]]++;
                dfs(nums, i + 1);
                mp[nums[i]]--;
            }
        }
    }
};