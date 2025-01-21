class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // [0][1, 2, -3, 3]
        std::unordered_map<int, int> mp = { {0, 1}}; // stores the freq of all subarray starting from 0 that adds up to a sum
        //  
        int prefix_sum = 0, count = 0; 

        // k : target
        // s : prev sum
        // n : curr num

        // k = s + 

        // 3 4 -7 7 k = 0
        // 0,
        int i = 0;
        for (auto num : nums) {
            std::cout << "At i : " << i++ << "\n";
            prefix_sum += num;
            std::cout << "prefix_sum is: " << prefix_sum << std::endl;
            std::cout << "The count of ... " << mp[prefix_sum-k] << std::endl;
            count += mp[prefix_sum - k];
            mp[prefix_sum]++;
        }
        return count;
    }
};