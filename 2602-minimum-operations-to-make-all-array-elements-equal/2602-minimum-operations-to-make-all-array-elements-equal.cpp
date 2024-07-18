class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        std::ranges::sort(nums);
        std::vector<int> prefix;
        prefix.push_back(0);
        for( int i = 0; i < nums.size(); i++) {
            prefix.push_back(prefix.back() + nums[i]);
        }


        std::vector<long long> result;
        
        for (auto q : queries) {
            auto s = std::lower_bound(nums.begin(), nums.end(), q) - nums.begin(); 
            std::cout << s << std::endl;
            
            long long before = q * s - prefix[s];
            long long after = (prefix[nums.size()] - prefix[s])- q * (nums.size() - s);
            std::cout << before << " " << after << std::endl;

            result.push_back(before + after);
        }
        return result;
    }
};